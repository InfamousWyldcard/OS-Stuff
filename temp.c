#include <stdio.h>

int main() {
    int temperature;
    int result;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%d", &temperature);

    //Calculate the result using logical operators (to avoid if/else)
    result = (temperature > 70) && (temperature < 85);

    //Output the result (1 if it's in range, 0 otherwise)
    printf("%d\n", result);

    return 0;
}