#include <stdio.h>

// Initial user details
int pin = 1234;
float balance = 1000.00;

// Function declarations
void checkBalance();
void depositMoney();
void withdrawMoney();

int main() {
    int enteredPin;
    int choice;
    int attempts = 0;

    printf("=====================================\n");
    printf("     WELCOME TO THE C-BANK ATM       \n");
    printf("=====================================\n");

    // PIN Verification (Max 3 attempts)
    while (attempts < 3) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("\nPIN verified successfully!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("\nToo many incorrect attempts. Your card is blocked!\n");
        return 0;
    }

    // Main Menu Loop
    do {
        printf("\n-------------------------------------\n");
        printf("              MAIN MENU              \n");
        printf("-------------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("\nThank you for using C-Bank ATM. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option! Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to check current balance
void checkBalance() {
    printf("\nYour current balance is: $%.2f\n", balance);
}

// Function to deposit money
void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be greater than 0.\n");
    } else {
        balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
        printf("New Balance: $%.2f\n", balance);
    }
}

// Function to withdraw money
void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be greater than 0.\n");
    } else if (amount > balance) {
        printf("Insufficient balance! You only have $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("Successfully withdrew $%.2f\n", amount);
        printf("Remaining Balance: $%.2f\n", balance);
    }
}