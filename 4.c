#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char address[100];
    int squareFeet;
    int bedrooms;
    int bathrooms;
    double price;
} House;

void part4_1() {
    //Open the file for writing ("w" mode). If the file doesn't exist, it will be created.
    FILE *file = fopen("hello.txt", "w");

    // Write to the file
    fprintf(file, "Hello!\n");
    fprintf(file, "How are you?\n");
    fprintf(file, "My name is Caleb DeBoer.\n");
    fprintf(file, "What is your name?\n");

    // Close the file
    fclose(file);

    printf("File 'hello.txt' created successfully.\n");
}

void part4_2() {
    //Open the file for reading ("r" mode)
    FILE *file = fopen("hello.txt", "r");

    //Read and display the contents of the file

    //Temporary storage for each line
    char buffer[256]; 

    printf("Contents of 'hello.txt':\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    //Close the file
    fclose(file);
}

void part4_3() {
    //Open the file for writing ("w" mode)
    FILE *file = fopen("hello.txt", "w");

    const char *dataToBeWritten = "This is new data.\n";

    fprintf(file, "%s", dataToBeWritten);

    fputs(dataToBeWritten, file);
    
    fwrite(dataToBeWritten, sizeof(char), strlen(dataToBeWritten), file);

    //Close the file
    fclose(file);
}

void part4_4() {
    char buffer[256];
    FILE *file = fopen("hello.txt", "r");

    printf("\nContents of data.txt using fgets():\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    //Using fread to read the file
    rewind(file);
    char freadBuffer[256] = {0};
    printf("\nContents of data.txt using fread():\n");
    size_t bytesRead = fread(freadBuffer, sizeof(char), sizeof(freadBuffer) - 1, file);
    freadBuffer[bytesRead] = '\0'; //Nullterminate
    printf("%s", freadBuffer);

    fclose(file);
}

void part4_5() {
    House houses[3] = {
        {"123 Maple St", 1500, 3, 2, 250000.0},
        {"456 Oak Ave", 2000, 4, 3, 350000.0},
        {"789 Pine Rd", 1800, 3, 2, 275000.0}
    };

    printf("\nHouse Information:\n");
    for (int i = 0; i < 3; i++) {
        printf("House %d:\n", i + 1);
        printf("Address: %s\n", houses[i].address);
        printf("Square Feet: %d\n", houses[i].squareFeet);
        printf("Bedrooms: %d\n", houses[i].bedrooms);
        printf("Bathrooms: %d\n", houses[i].bathrooms);
        printf("Price: $%.2f\n\n", houses[i].price);
    }
}

void part4_6() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    int *scores = (int *)malloc(numStudents * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the scores of %d students:\n", numStudents);
    for (int i = 0; i < numStudents; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    FILE *file = fopen("scores.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        free(scores);
        return;
    }

    for (int i = numStudents - 1; i >= 0; i--) {
        fprintf(file, "%d\n", scores[i]);
    }

    free(scores);
    fclose(file);
    printf("Scores written to scores.txt in reverse order.\n");
}

int main() {
    task4_1();
    task4_2();
    task4_3();
    task4_4();
    task4_5();
    task4_6();
    return 0;
}