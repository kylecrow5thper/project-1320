#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int studentID;
    char name[50];
    float balanceDeposit;   // current balance loaded from balance.txt
    float semLimit;         // semester spending limit (cannot change)
    float spentThisSem;     // tracked by spendMoney()
    long routingNumber;     // optional for withdrawals
} StudentAccount;


// Loads student accounts from students.txt into memory (runs FIRST)
void loadAccounts(const char *filename);

// Saves all student accounts back into students.txt (runs LAST)
void saveAccounts(const char *filename);

// Creates a new student account (uses balance.txt for initial balance)
void createAccount();

// Logs a student into their account and returns their array index
int loginStudent();

// Spending function (subtracts from balanceDeposit, adds to spentThisSem)
void spendMoney(int studentIndex);

// Shows account information for a logged-in user
void viewAccount(int studentIndex);

// Withdraws money to bank (uses routingNumber)
void withdrawToBank(int studentIndex);

// Simulated club transaction voting (does NOT modify students.txt)
void approveClubTransaction();

// Menu for logged-in students (view/spend/withdraw/logout)
void studentMenu(int studentIndex);

// Main menu (createAccount, loginStudent, approveClubTransaction, exit)
void mainMenu();


int main() {
    // FIRST: Load all student accounts from students.txt
    loadAccounts("students.txt");

    // MIDDLE: User interacts with createAccount(), loginStudent(), etc.
    mainMenu();

    // LAST: Save all changes back into students.txt
    saveAccounts("students.txt");

    return 0;
}
