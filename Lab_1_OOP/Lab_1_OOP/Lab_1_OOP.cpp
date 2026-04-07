#include "Phone.cpp"
#include "Smartphone.cpp"
#include "ButtonPhone.cpp"
#include "vector"
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем объекты
    //Smartphone iphone("iPhone 15", "+79991234567", 10.0, 1000.0);
    //ButtonPhone nokia("Nokia 3310", "+79301112233", 150.0, 2);

    //ButtonPhone n1();
    //ButtonPhone n2(nokia);
    ////конструктор копирования
    //Smartphone ip2(iphone);
    ////ip2.showInfo();
    ////конструктор по умолчанию
    //Smartphone ip1;
    ////ip1.showInfo();

    Smartphone* ip = new Smartphone("Iphone 15", "+79023324", 10.0, 1000.0);
    Smartphone* ip1 = new Smartphone();
    Smartphone* ip2 = new Smartphone(*ip);

    ButtonPhone* nk = new ButtonPhone("Nokia 3310", "+79301112233", 150.0, 2);
    ButtonPhone* nk1 = new ButtonPhone();
    ButtonPhone* nk2 = new ButtonPhone(*nk);


    std::vector<Phone*> oop = {
        ip,
        ip1,
        ip2,
        nk,
        nk1,
        nk2
    };

    /*static_cast<Smartphone*>(oop[1])->getAllApps();
    static_cast<Smartphone*>(oop[1])->installApp("Telegram");
    static_cast<Smartphone*>(oop[1])->useInternet("аудио", 50);*/


    //dynamic_cast<Smartphone*>(oop[4])->checkBalance();
    static_cast<Smartphone*>(oop[4])->checkBalance();



 /*   for (Phone* phone : oop) {
        phone->showInfo();
    }*/
    //if(Smartphone * smartphone = dynamic_cast<Smartphone*>(oop[1])) {
    //    smartphone->checkBalance();
    //    smartphone->getAllApps();      
    //    smartphone->installApp("Telegram");  
    //    smartphone->useInternet("аудио", 50);  
    //    }

    //cout << "\n";
    // if (ButtonPhone* buttonPhone = dynamic_cast<ButtonPhone*>(oop[5])) {
    //     buttonPhone->setMaxContacts(10);
    //     buttonPhone->typeText("22");   
    //     buttonPhone->saveKontakt("Имя", "123");
    //     buttonPhone->showInfo();
    //}


    // демонстрация
    //iphone.getAllApps();
    //iphone.installApp("Telegram");
    //iphone.installApp("Viber");
    //iphone.useInternet("аудио", 50);
    //iphone.showInfo();

    //nokia.typeText("22#22");
    ////nokia.setMaxContacts(1);
    //nokia.saveKontakt("Мама", "+794567");
    //nokia.saveKontakt("Маа", "+73467");

    //nokia.showInfo();
    return 0;
}