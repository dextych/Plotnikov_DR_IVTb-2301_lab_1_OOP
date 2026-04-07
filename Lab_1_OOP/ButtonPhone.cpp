#ifndef BUTTONPHONE_CPP
#define BUTTONPHONE_CPP

#include "Phone.cpp"
#include <vector>

class ButtonPhone : public Phone {
private:
    vector<string> contacts;
    int maxContacts;

public:
    ButtonPhone() : Phone(), maxContacts(100) {}
    
    ButtonPhone(string model, string number, double balance, int maxContacts)
        : Phone(model, number, balance), maxContacts(maxContacts) {}
    
    ButtonPhone(const ButtonPhone& other)
        : Phone(other), contacts(other.contacts), maxContacts(other.maxContacts) {}
    
    ~ButtonPhone() {}
    
    vector<string> getContacts() const { return contacts; }
    int getMaxContacts() const { return maxContacts; }
    void setMaxContacts(int max) { maxContacts = max; }
    
    void getNumberInfo() const override {
        cout << "Кнопочный телефон " << getModel() << ", номер: " << getNumber() << endl;
    }
    
    void checkBalance() const override {
        cout << "Баланс кнопочного телефона " << getModel() << ": " << getBalance() << " руб." << endl;
        cout << "Контактов: " << contacts.size() << "/" << maxContacts << endl;
    }
    
    void showInfo() const override {
        cout << "\n=== Информация о кнопочном телефоне ===" << endl;
        cout << "Модель: " << getModel() << endl;
        cout << "Номер: " << getNumber() << endl;
        cout << "Баланс: " << getBalance() << " руб." << endl;
        cout << "Максимум контактов: " << maxContacts << endl;
        cout << "Контактов сохранено: " << contacts.size() << endl;
    }
    
    void typeText(string input) {
        string keys[10] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string result = "";
        int i = 0;

        while (i < input.length()) {
            char current = input[i];

            if (current == '#') break;

            if (current == '*') {
                if (!result.empty()) result.pop_back();
                i++;
                continue;
            }

            if (current == '0') {
                result += ' ';
                i++;
                continue;
            }

            if (current >= '2' && current <= '9') {
                int digit = current - '0';
                int count = 1;

                while (i + count < input.length() && input[i + count] == current) {
                    count++;
                }

                int maxPresses = (digit == 7 || digit == 9) ? 4 : 3;
                if (count > maxPresses) count = maxPresses;

                result += keys[digit][count - 1];
                i += count;
            }
            else {
                i++;
            }
        }

        cout << "Ввод: " << input << " Текст: \"" << result << "\"" << endl;
    }
    
    void saveKontakt(string name, string number) {
        if (contacts.size() >= maxContacts) {
            cout << "Ошибка: Телефонная книга переполнена!" << endl;
        } else {
            string contact = name + ": " + number;
            contacts.push_back(contact);
            cout << "Контакт '" << name << "' сохранен!" << endl;
        }
    }
};

#endif