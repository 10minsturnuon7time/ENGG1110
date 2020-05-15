/**
 * ENGG1110 Problem Solving by Programming
 * Lab 08 Exercise 2
 * Circles
 */

#include <math.h>
#include <stdio.h>
#include <sys/param.h>

#define PI 3.14159265

// Point
typedef struct {
  double x; // x coordinate
  double y; // y coordinate
} Point;

// Circle
typedef struct {
  Point p;  // center position
  double r; // radius
} Circle;

// Return the minimum of two values
double min(double a, double b) {
    return (a < b) ? a : b;
}

// Distance of two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Area of a sector
double sectorArea(double angle, double radius) {
    return 0.5 * angle * radius * radius;
}

// Area of a triangle
double triangleArea(double includedAngle, double side1, double side2) {
    return 0.5 * side1 * side2 * sin(includedAngle);
}

// Area of a circle
double circleArea(Circle c) {
    return PI * pow(c.r, 2);
}

// compute the angle of a triangle opposite to side3
double angleOfTriangle(double side1, double side2, double side3) {
    return acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
}

// intersection area of two circles
double intersectionArea(Circle c1, Circle c2) {
    double area = 0;
    double r1 = c1.r, r2 = c2.r;
    double d = distance(c1.p, c2.p);

    if (d >= r1 + r2)
        area = 0;
    else
    if (d <= fabs(r1 - r2))
        area = min(circleArea(c1), circleArea(c2));
    else {
        double angle1 = angleOfTriangle(r1, d, r2);
        double SectorACF = sectorArea(angle1, r1);
        double angle2 = angleOfTriangle(r2, d, r1);
        double SectorBCE = sectorArea(angle2, r2);
        double TriangleABC = triangleArea(angle1, r1, d);
        area = 2 * (SectorACF + SectorBCE - TriangleABC);
    }
    return area;
}

// union area of two circles
double unionArea(Circle c1, Circle c2) {
    return circleArea(c1) + circleArea(c2) - intersectionArea(c1, c2);
}

int main() {
    Circle c1, c2;
    scanf("%lf %lf %lf", &c1.p.x, &c1.p.y, &c1.r);
    scanf("%lf %lf %lf", &c2.p.x, &c2.p.y, &c2.r);

    printf("Intersection area is %.2lf\n", intersectionArea(c1, c2));
    printf("Union area is %.2lf\n", unionArea(c1, c2));

    return 0;
}
