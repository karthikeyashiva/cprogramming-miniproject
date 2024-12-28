#include <stdio.h>
#include <stdbool.h>

// Define the initial balance and maximum attempts
#define INITIAL_BALANCE 10000
#define MAX_ATTEMPTS 3

// Function prototypes
bool verifyPin();
void displayBalance(int balance);
void withdrawCash(int *balance);
void depositCash(int *balance);
void displayMenu();

int main() {
    int balance = INITIAL_BALANCE;
    int attempts = 0;
    int choice;
    bool authenticated = false;

    // Authenticate user with PIN
    while (attempts < MAX_ATTEMPTS) {
        if (verifyPin()) {
            authenticated = true;
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    if (!authenticated) {
        printf("Too many failed attempts. Exiting the system.\n");
        return 0;
    }

    // Main menu loop
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBalance(balance);
                break;
            case 2:
                withdrawCash(&balance);
                break;
            case 3:
                depositCash(&balance);
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to verify the user's PIN
bool verifyPin() {
    int correctPin = 1234; // Predefined PIN
    int enteredPin;

    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    return enteredPin == correctPin;
}

// Function to display the current balance
void displayBalance(int balance) {
    printf("Your current balance is: ₹%d\n", balance);
}

// Function to handle cash withdrawal
void withdrawCash(int *balance) {
    int amount;

    printf("Enter the amount to withdraw: ₹");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please try again.\n");
    } else if (amount > *balance) {
        printf("Insufficient balance! Transaction failed.\n");
    } else {
        *balance -= amount;
        printf("Transaction successful! ₹%d withdrawn.\n", amount);
        printf("Remaining balance: ₹%d\n", *balance);
    }
}

// Function to handle cash deposit
void depositCash(int *balance) {
    int amount;

    printf("Enter the amount to deposit: ₹");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please try again.\n");
    } else {
        *balance += amount;
        printf("Transaction successful! ₹%d deposited.\n", amount);
        printf("Updated balance: ₹%d\n", *balance);
    }
}

// Function to display the ATM menu
void displayMenu() {
    printf("\n--- ATM Menu ---\n");
    printf("1. Balance Inquiry\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Deposit Cash\n");
    printf("4. Exit\n");
}