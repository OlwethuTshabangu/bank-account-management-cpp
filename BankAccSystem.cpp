#include <iostream>
#include <string>

using namespace std;

//function to create a new account 
void createAccount (string &name, int &accountNumber, double &balance) {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);    //read full name including spaces 

    cout << "Enter your account number: ";
    cin >> accountNumber; //read account number 

    do{
        cout << "Enter your initial deposit (must greater than 0): R";
        cin >> balance;   //read initial deposit 
        if (balance <= 0)
           cout << "Initial deposit must be greater than 0." << endl; 

    } while (balance <= 0); //ensure intitial deposit is valid
    cout << " Account created successfully! " << endl;

}
//function to deposit money into the account 
void depositMoney (double &balance) {
    double amount;
    do {
        cout << "Enter amount to deposit (greater than 0): R";
        cin >> amount;       // Read deposit amount
        if (amount <= 0)
           cout << "Deposit amount must be greater than 0." << endl;

    } while (amount <= 0);   // Ensure deposit amount is valid
    
    balance += amount;       // Add deposit to balance
    cout << "Deposit successful! New balance: R" << balance << endl;

}
// Function to withdraw money from the account
void withdrawMoney (double &balance) {
    double amount;
    do{
        cout << "Enter amount to withdraw: R";
        cin >> amount;
        if (amount > balance) {
            cout << "Withdrawal amount exceeds the current balance." << endl;

        } else if (amount <=0){
            cout << "Withdrawal amount must be greater than 0." << endl;
        }
    } while (amount > balance || amount <=0);    // Ensure withdrawal is valid


    balance -=amount;      // Deduct withdrawal from balance
    cout << "WIthdrawal succesful! New balance: R" << balance << endl;
}

// Function to check the current balance
void checkBalance(const double &balance) {
    cout << "Current balance: R" << balance << endl;

}

// Function to display account details
void displayAccountDetails (const string &name, const int &accountNumber, const double &balance) {
    cout << "--- Account Details ---" << endl;
    cout << "Account Holder: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: R" << balance << endl;

}
// Main function with menu-driven loop
int main() {
    string name;
    int accountNumber;
    double balance = 0.0;

    int option;
    do {
        // Display menu options
        cout << "\n--- Bank Account Management System ---" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> option;   // Read user choice

        // Perform action based on user choice
        switch (option) {
        case 1:
            createAccount(name, accountNumber, balance);
            break;
        case 2:
            depositMoney(balance);
            break;
        case 3:
            withdrawMoney(balance);
            break;
        case 4:
            checkBalance(balance);
            break;
        case 5:
            displayAccountDetails(name, accountNumber, balance);
            break;
        case 6:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }   

    } while (option !=6);   // Repeat until user chooses to exit

    return 0; 
}

// new funtion code here