/*You need to store data about different shapes: circles (need radius), rectangles (length and width), and triangles(three sides) 
How could you use a structure and a union together to save memory? 
How would you know which shape you are dealing with when using the data?*/

#include <stdio.h>

struct Shape {
    int type; // 1 = circle, 2 = rectangle, 3 = triangle
    union {
        float radius;
        struct {
            float length, width;
        } rectangle;
        struct {
            float a, b, c;
        } triangle;
    } data;
};

void printShape(struct Shape s) {
    if (s.type == 1) {
        printf("Circle with radius: %.2f\n", s.data.radius);
    } else if (s.type == 2) {
        printf("Rectangle with length %.2f and width %.2f\n", s.data.rectangle.length, s.data.rectangle.width);
    } else if (s.type == 3) {
        printf("Triangle with sides: %.2f, %.2f, %.2f\n", s.data.triangle.a, s.data.triangle.b, s.data.triangle.c);
    } else {
        printf("Unknown shape type.\n");
    }
}

int main() {
    struct Shape s1 = {1, .data.radius = 5.0};
    struct Shape s2 = {2, .data.rectangle = {10.0, 4.0}};
    struct Shape s3 = {3, .data.triangle = {3.0, 4.0, 5.0}};

    printShape(s1);
    printShape(s2);
    printShape(s3);

    return 0;
}
