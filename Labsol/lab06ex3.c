/**
 * ENGG1110 Problem Solving by Programming
 * Lab 06 Exercise 3
 * Moving average of order K
 */

 #include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<=N-K; i++) {
        double sum = 0;
        for (int j=i; j<i+K; j++) {
            sum += a[j];
        }
        printf("%.2f ", sum/K);
    }
    return 0;
}
