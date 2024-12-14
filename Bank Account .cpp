#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  //Created a Base Class named bank Acount

public:
    // Initialized a constructor for input validation
    BankAccount(double initialBalance = 0.0) {
        if (initialBalance < 0) {
            cout << "Initial balance cannot be negative. Setting to 0.\n";
            balance = 0.0;
        } else {
            balance = initialBalance;
        }
    }

    // Made a friend function to Increment what the user add in his initial balance
    friend BankAccount operator+(const BankAccount &account, double deposit);

      // Made a friend function to decrement what the user add in his deposit amount
    friend BankAccount operator-(const BankAccount &account, double withdrawal);

//   Function for display
    void displayBalance() const {
        cout << "Current Balance: Rs " << balance << endl;
    }
};

// Now overloading + operator to deposit and also checking if user enter - value 
BankAccount operator+(const BankAccount &account, double deposit) {
    if (deposit < 0) {
        cout << "Deposit amount cannot be negative.\n";
        return account;
    }
    return BankAccount(account.balance + deposit);
}
// Now overloading - operator to withdraw and also checking if user enter - value 

BankAccount operator-(const BankAccount &account, double withdrawal) {
    if (withdrawal < 0) {
        cout << "Withdrawal amount cannot be negative.\n";
        return account;
    } else if (withdrawal > account.balance) {
        cout << "Insufficient balance. Withdrawal not allowed.\n";
        return account;
    }
    return BankAccount(account.balance - withdrawal);
}


int main() {
     cout << "Welcome To MBL\n";
    double initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
   
    
    BankAccount myAccount(initialBalance);

    cout << "\nInitial Balance:\n";
    myAccount.displayBalance();

    char choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            double depositAmount;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            myAccount = myAccount + depositAmount;
            myAccount.displayBalance();
        } else if (choice == '2') {
            double withdrawalAmount;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawalAmount;
            myAccount = myAccount - withdrawalAmount;
            myAccount.displayBalance();
        } else if (choice != '3') {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');
    cout << "\nThank you for using the bank system. Goodbye!\n";
}
