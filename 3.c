#include <stdio.h>

#define PI 3.14159

// Function to convert temperature from F to C
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to calculate the area from width and height (rectangle)
float area_rectangle(float width, float height) {
    return width * height;
}

// Function to calculate the area from radius (circle)
float area_circle(float radius) {
    return PI * radius * radius;
}

int main() {
    // 3.1: Using pointer, print the second element
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    printf("Second element: %d\n", *(ptr + 1));  // Pointer arithmetic to access second element

    // 3.2: Using for loop and pointer, print all elements, each element on a line
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("All elements:\n");
    for (int i = 0; i < length; i++) {
        printf("%d\n", *(ptr + i));  // Pointer arithmetic in for loop
    }

    // 3.3: Function exercises
    // 3.3.1: Convert temperature from F to C
    float fahrenheit = 98.6;
    printf("Temperature in Celsius: %.2f\n", fahrenheit_to_celsius(fahrenheit));

    // 3.3.2: Calculate area of rectangle
    float width = 5.0, height = 10.0;
    printf("Area of rectangle: %.2f\n", area_rectangle(width, height));

    // 3.3.3: Calculate area of circle
    float radius = 7.0;
    printf("Area of circle: %.2f\n", area_circle(radius));

    return 0;
}

