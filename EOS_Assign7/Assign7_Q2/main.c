#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main() {
    double radius, side, length, width;

    printf("Enter radius of circle: ");
    scanf("%lf", &radius);

    printf("Enter side of square: ");
    scanf("%lf", &side);

    printf("Enter length and width of rectangle: ");
    scanf("%lf %lf", &length, &width);

    printf("Area of circle: %.2lf\n", circle_area(radius));
    printf("Area of square: %.2lf\n", square_area(side));
    printf("Area of rectangle: %.2lf\n", rectangle_area(length, width));

    return 0;
}