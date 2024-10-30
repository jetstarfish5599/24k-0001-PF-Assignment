// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function prototypes
int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);
void DisplayMenu();
//start main
int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        DisplayMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal equivalent: %d\n", BinaryToDecimal(number));
                break;

            case 2: // Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary equivalent: %d\n", DecimalToBinary(number));
                break;

            case 3: // Decimal to Hexadecimal
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Hexadecimal equivalent: ");
                DecimalToHexadecimal(number);
                printf("\n");
                break;

            case 4: // Hexadecimal to Decimal
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Decimal equivalent: ");
                HexadecimalToDecimal(hexNumber);
                printf("\n");
                break;

            case 5: // Binary to Hexadecimal
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Hexadecimal equivalent: ");
                BinaryToHexadecimal(number);
                printf("\n");
                break;

            case 6: // Hexadecimal to Binary
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Binary equivalent: ");
                HexadecimalToBinary(hexNumber);
                printf("\n");
                break;

            case 0: // Exit
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function definitions

void DisplayMenu() {
    printf("\n--- Numerical Conversion Menu ---\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("0. Exit\n");
}

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, lastDigit;
    while (number > 0) {
        lastDigit = number % 10;
        if (lastDigit != 0 && lastDigit != 1) {
            printf("Invalid binary number.\n");
            return -1;
        }
        decimal += lastDigit * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    if (number < 0) {
        printf("Invalid input.");
        return;
    }
    printf("%X", number);
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        char digit = hexNumber[i];
        if ((digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F') || (digit >= 'a' && digit <= 'f')) {
            decimal = decimal * 16 + (digit >= '0' && digit <= '9' ? digit - '0' : (digit & ~32) - 'A' + 10);
        } else {
            printf("Invalid hexadecimal number.");
            return;
        }
    }
    printf("%d", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    if (decimal != -1) {
        DecimalToHexadecimal(decimal);
    }
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        char digit = hexNumber[i];
        if ((digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F') || (digit >= 'a' && digit <= 'f')) {
            decimal = decimal * 16 + (digit >= '0' && digit <= '9' ? digit - '0' : (digit & ~32) - 'A' + 10);
        } else {
            printf("Invalid hexadecimal number.");
            return;
        }
    }
    printf("%d", DecimalToBinary(decimal));
}
