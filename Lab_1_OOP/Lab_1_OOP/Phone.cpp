#ifndef PHONE_CPP
#define PHONE_CPP

#include <iostream>
#include <string>
using namespace std;

class Phone {
private:
    string model;
    string number;
    double balance;

public:
    // Конструкторы
    Phone() : model("Unknown"), number("000000"), balance(0.0) {}

    Phone(string model, string number, double balance)
        : model(model), number(number), balance(balance) {}

    Phone(const Phone& other)
        : model(other.model), number(other.number), balance(other.balance) {}

    virtual ~Phone() {}

    // Геттеры и сеттеры
    string getModel() const { return model; }
    void setModel(string model) { this->model = model; }

    string getNumber() const { return number; }
    void setNumber(string number) { this->number = number; }

    double getBalance() const { return balance; }
    void setBalance(double balance) { this->balance = balance; }

    // Виртуальные методы
    virtual void getNumberInfo() const {
        cout << "Номер телефона: " << number << endl;
    }

    virtual void checkBalance() const {
        cout << "Баланс счета: " << balance << " руб." << endl;
    }

    // Чисто виртуальный метод
    virtual void showInfo() const = 0;
};

#endif