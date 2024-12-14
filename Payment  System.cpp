#include <iostream>
using namespace std;

class Payment {
public:
    int pay_amount;
    int result;
    float cal;

    virtual void processPayment() {
        cout << "Payment Processed Successfully" << endl;
    };
};

class CreditCard : public Payment {
public:
    void processPayment() override {
        cout << "Credit Card";
        cout << endl;
        cout << "Enter PayAmount" << endl;
        cin >> pay_amount;
        cal = 2.0 / 100.0;
        result = pay_amount - (pay_amount * cal);
        cout << "Payment Processed Via CreditCard: " << result << endl;
    }
};

class Paypal : public Payment {
public:
    void processPayment() override {
        cout << "Paypal" << endl;
        cout << "Enter PayAmount" << endl;
        cin >> pay_amount;
        cal = 3.0 / 100.0;
        result = pay_amount - (pay_amount * cal);
        cout << "Payment Processed Via Paypal: " << result << endl;
    }
};

class Cash : public Payment {
public:
    void processPayment() override {
        cout << "Cash" << endl;
        cout << "Enter PayAmount" << endl;
        cin >> pay_amount;
        cout << "Payment Processed Via Cash: " << pay_amount << endl;
    }
};

int main() {
    int choice;
    CreditCard ob2;
    Paypal ob3;
    Cash ob4;

    cout << "Press 1 for Credit Card" << endl;
    cout << "Press 2 for Paypal" << endl;
    cout << "Press 3 for Cash" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        ob2.processPayment();
        break;
    case 2:
        ob3.processPayment();
        break;
    case 3:
        ob4.processPayment();
        break;
    default:
        cout << "Select a valid input" << endl;
        break;
    }

    return 0;
}
