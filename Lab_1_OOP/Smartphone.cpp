#ifndef SMARTPHONE_CPP
#define SMARTPHONE_CPP

#include "Phone.cpp"
#include <vector>
#include <algorithm>

class Smartphone : public Phone {
private:
    double internetTraffic;
    vector<string> installedApps;
    vector<string> availableApps;

public:
    Smartphone() : Phone(), internetTraffic(5000.0) {
        availableApps = { "Telegram", "WhatsApp", "Viber", "YouTube", "Instagram" };
    }

    Smartphone(string model, string number, double balance, double traffic)
        : Phone(model, number, balance), internetTraffic(traffic) {
        availableApps = { "Telegram", "WhatsApp", "Viber", "YouTube", "Instagram" };
    }

    Smartphone(const Smartphone& other)
        : Phone(other), internetTraffic(other.internetTraffic), installedApps(other.installedApps), availableApps(other.availableApps) {}

    ~Smartphone() {}

    double getInternetTraffic() const { return internetTraffic; }
    void setInternetTraffic(double traffic) { internetTraffic = traffic; }
    vector<string> getInstalledApps() const { return installedApps; }

    vector<string> getAvailableApps() { return availableApps; }

    void getNumberInfo() const override {
        cout << "Смартфон " << getModel() << ", номер: " << getNumber() << endl;
    }

    void checkBalance() const override {
        cout << "Баланс счета смартфона " << getModel() << ": " << getBalance() << " руб." << endl;
        cout << "Остаток интернет-трафика: " << internetTraffic << " МБ" << endl;
    }

    void showInfo() const override {
        cout << "\n=== Информация о смартфоне ===" << endl;
        cout << "Модель: " << getModel() << endl;
        cout << "Номер: " << getNumber() << endl;
        cout << "Баланс: " << getBalance() << " руб." << endl;
        cout << "Трафик: " << internetTraffic << " МБ" << endl;
        cout << "Установленные приложения: ";
        if (installedApps.empty()) {
            cout << "нет";
        }
        else {
            for (size_t i = 0; i < installedApps.size(); i++) {
                cout << installedApps[i];
                if (i < installedApps.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }

    void getAllApps() {
        cout << "Доступные приложения" << endl;
        for (size_t i = 0; i < availableApps.size(); i++) {
            cout << availableApps[i] << "\n";
        }
    }

    void installApp(string appName) {
        bool appExists = false;
        for (const string& app : availableApps) {
            if (app == appName) {
                appExists = true;
                break;
            }
        }

        if (!appExists) {
            cout << "Ошибка: Приложение '" << appName << "' не найдено в магазине!" << endl;
            return;
        }

        for (const string& app : installedApps) {
            if (app == appName) {
                cout << "Ошибка: Приложение '" << appName << "' уже установлено!" << endl;
                return;
            }
        }

        if (installedApps.size() >= 50) {
            cout << "Ошибка: Лимит приложений (50)!" << endl;
            return;
        }

        installedApps.push_back(appName);
        cout << "Успех: Приложение '" << appName << "' установлено!" << endl;
    }

    void useInternet(string contentType, double mb) {
        double coefficient = 1.0;
        if (contentType == "текст") coefficient = 0.5;
        else if (contentType == "аудио") coefficient = 1.5;
        else if (contentType == "видео") coefficient = 3.0;
        else {
            cout << "Неизвестный тип контента!" << endl;
            return;
        }

        double spent = mb * coefficient;
        if (spent <= internetTraffic) {
            internetTraffic -= spent;
            cout << "Списано " << spent << " МБ за " << contentType << endl;
            cout << "Остаток трафика: " << internetTraffic << " МБ" << endl;
        }
        else {
            cout << "Недостаточно трафика!" << endl;
        }
    }
};

#endif