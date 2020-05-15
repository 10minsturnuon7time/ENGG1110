/**
 * ENGG1110 Problem Solving by Programming
 * Lab 13 Exercise 3 (Optional)
 * Adding Memory to Card Game Players
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Player Type */
const int MAN = 1;	// Human
const int COM = 2;	// Computer

/* Intelligence levels */
const int LOW = 5;
const int MEDIUM = 10;
const int HIGH = 15;

/* Card structure */
typedef struct {
	char suit;   // 'S'pade / 'H'eart / 'C'lub / 'D'iamond
	int  rank;   // A (1) / 2 - 10 / J (11) / Q (12) / K (13);
	int  status; // covered (0) or flipped (1)
	int  row;
	int  col;
} Card_t;

/* Structure for storing a pair of cards */
typedef struct {
	Card_t card1;
	Card_t card2;
} Pair_t;

/* Player structure */
typedef struct {
   char name[20];
   int type;		// MAN or COM
   int wisdom;		// size of memory array
   Card_t *memory;
} Player_t;


void print_face_value(Card_t card) {
	printf("%c", card.suit);
	switch (card.rank) {
		case  1: printf("%2c", 'A'); break;
		case 11: printf("%2c", 'J'); break;
		case 12: printf("%2c", 'Q'); break;
		case 13: printf("%2c", 'K'); break;
		default:
			printf("%2d", card.rank);
	}
}

void print_card(Card_t card) {
	if (card.status == 1)
		print_face_value(card);
	else
		printf("XXX");
}

/*
 * A function that compares two cards
 * Return 0 if c1 and c2 are identical (same in both rank and suit)
 * Return -ve if c1's rank < c2's rank or c1's suit < c2's suit (if same rank)
 * Return +ve if c1's rank > c2's rank or c1's suit > c2's suit (if same rank)
 */
int compare(const void *c1, const void *c2)
{
	Card_t *card1 = (Card_t *) c1;
	Card_t *card2 = (Card_t *) c2;
	if (card1->rank == card2->rank)
		return card1->suit - card2->suit;
	else
		return card1->rank - card2->rank;
}

void print_memory(Player_t *player){
	// Sort the cards by quick sort algorithm
	// qsort is a function provided by the standard C library
	// Reference: http://www.cplusplus.com/reference/cstdlib/qsort/
	qsort(player->memory, player->wisdom, sizeof(Card_t), compare);

	printf("%s's memory:\n", player->name);

	for (int i=0; i < player->wisdom; i++) {
		if (player->memory[i].rank != 0) {
			printf("[");
			print_face_value(player->memory[i]);
			printf("] ");
		}
	}
	printf("\n");
}

Player_t create_player(char name[], int type, int wisdom) {
	Player_t player;
	strcpy(player.name, name);
	player.type = type;
	player.wisdom = wisdom;
	player.memory = (Card_t*) malloc(wisdom * sizeof(Card_t));
	Card_t zeros = { 0 };
	for (int i=0; i < wisdom; i++)
		player.memory[i] = zeros;
	return player;
}

void destroy_player(Player_t player) {
	free(player.memory);
}

/*
 * A function that accepts a pair of coordinates from the user
 * With this function, we can control which cards to flip by each player
 * via standard input for a deterministic result to check correction.
 */
Pair_t flip_pair(Card_t desktop[][14]) {
	Pair_t pair;
	int r1, c1, r2, c2;
	scanf("%d%d", &r1, &c1);
	scanf("%d%d", &r2, &c2);
	// assume no invalid coordinates
	pair.card1 = desktop[r1][c1];
	pair.card2 = desktop[r2][c2];
	return pair;
}

/*
 * Save a card into the specified player's memory array
 */
void memorize(Player_t* player, Card_t card) {
	// check if the specified card is already in player's memory
	for (int i=0; i < player->wisdom; i++) {
		if (card.rank == player->memory[i].rank &&
			 card.suit == player->memory[i].suit) {
			return;   // avoid storing duplicate card
      }
	}
	// find an empty slot to store the specified card
	for (int i=0; i < player->wisdom; i++) {
      if (player->memory[i].rank == 0) {
         player->memory[i] = card;
      	break;
      }
   }
}

/*
 * Remove a card from the specified player's memory array
 */
void forget(Player_t* player, Card_t card) {
	Card_t zeros = { 0 };
	for (int i=0; i < player->wisdom; i++) {
		if (card.rank == player->memory[i].rank &&
			 card.suit == player->memory[i].suit) {
			player->memory[i] = zeros;
			break;
      }
	}
}

/*
 * This function implements the main loop of the game.
 * It plays one round of the game, looping through all players.
 */
void play(Player_t player[], int n, Card_t desktop[][14]) {
	for (int i=0; i < n; i++) {
		Pair_t pair = flip_pair(desktop);
		if (pair.card1.rank == pair.card2.rank) {
			desktop[pair.card1.row][pair.card1.col].status = 1;
			desktop[pair.card2.row][pair.card2.col].status = 1;
			for (int i=0; i < n; i++) {
				if (player[i].type == COM) {
					forget(&player[i], pair.card1);
					forget(&player[i], pair.card2);
				}
			}
		} else {
			for (int i=0; i < n; i++) {
				if (player[i].type == COM) {
					memorize(&player[i], pair.card1);
					memorize(&player[i], pair.card2);
				}
			}
		}
	}
}

/* Starting point of this C program */
int main(void)
{
	/* Given initial card arrangement, DO NOT modify */
	Card_t desktop[4][14] = {
		/* the first element (column 0) of each row is UNUSED */
		/* row: 0 - 3; col: 1 - 13 */
		{{}, {'D', 8}, {'H',11}, {'S',10}, {'C', 7}, {'D', 2}, {'C', 6}, {'H',13}, {'C', 2}, {'C',10}, {'H', 5}, {'H', 2}, {'C',13}, {'D', 4}},
		{{}, {'H',12}, {'H', 6}, {'D', 7}, {'S', 9}, {'S',13}, {'H', 8}, {'S', 4}, {'S', 5}, {'D', 5}, {'S', 7}, {'S',12}, {'H', 9}, {'S', 8}},
		{{}, {'C', 5}, {'D',12}, {'C', 3}, {'D',11}, {'C', 8}, {'H', 1}, {'S', 2}, {'D', 1}, {'S', 6}, {'C', 1}, {'S', 1}, {'D', 9}, {'D',13}},
		{{}, {'D', 3}, {'D',10}, {'C', 4}, {'D', 6}, {'C',12}, {'C',11}, {'S', 3}, {'H', 4}, {'H', 3}, {'C', 9}, {'S',11}, {'H',10}, {'H', 7}}
	};

	for (int i=0; i<4; i++) {
		for (int j=1; j<=13; j++) {
			desktop[i][j].row = i;
			desktop[i][j].col = j;
		}
	}

	// Create an array of players
	Player_t man  = create_player("You", MAN, 0);
	Player_t com1 = create_player("Computer 1", COM, HIGH);
	Player_t com2 = create_player("Computer 2", COM, LOW);
	Player_t player[] = { man, com1, com2 };

	int n_player = sizeof(player) / sizeof(Player_t);
	int rounds;
	scanf("%d", &rounds);

	// Play a sequence of flips,
	// Note: no. of turns = rounds * no. of players
	for (int i=0; i < rounds; i++)
		play(player, n_player, desktop);

	// Show the memory of each computer player
	for (int i=0; i < n_player; i++)
		if (player[i].type == COM)
			print_memory(&player[i]);

	printf("Desktop arrangement:\n");
	for (int i=0; i<4; i++) {
		for (int j=1; j<=13; j++) {
			print_card(desktop[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}
