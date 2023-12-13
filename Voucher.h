#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
//1. Для визначеної раніше ієрархії класів додати абстрактного клас та кілька обґрунтованих (не менше трьох) похідних класів.
class Voucher {

private:
    int code;
    string transport;
    string city;

public:
    string country;
    string date;
    int cost;

    //4. Кожен клас, що входить в ієрархію, що використовує відкрите наслідування, повинен містити принаймні одну віртуальну функцію.Функціональність зазначених функцій не повинна дублюватися.
    virtual void startUseIt() const = 0;

    Voucher();
    Voucher(string country, string city, string date, int cost, int code, string transport);
    Voucher(string country, string city, int date);
    //3. На базі кожного похідного класу визначити віртуальні деструктори та продемонструвати відмінність їх роботи від невіртуальних деструкторів.
    virtual ~Voucher();

    //getters
    string getCountry();
    string getCity();
    string getDate();
    int getCost();
    int getCode();
    string getTransport();

    //setters
    void setCountry(string country);
    void setCity(string city);
    void setDate(string date);
    void setCost(int cost);
    void setCode(int code);
    void setTransport(string transport);

};






//1. Для визначеної раніше ієрархії класів додати абстрактного клас та кілька обґрунтованих (не менше трьох) похідних класів.
class PlusVoucher : public Voucher
{
private:
    int number_of_compartment;
    string insuranse;
    string all_Included;

public:
    void writeToFile();
    void writeToFile(string fileName);
    PlusVoucher readFromFile();
    PlusVoucher readFromFile(string fileName);

    PlusVoucher();
    PlusVoucher(string country, string city, string date, int cost, int code, string transport,
        int number_of_compartment, string insuranse, string all_Included);
    void Copy(PlusVoucher v);
    PlusVoucher getCopy();

    //getters
    int getNumber_of_compartment();
    string getInsuranse();
    string getAll_Included();

    //setters
    void setNumber_of_compartment(int number_of_compartment);
    void setInsuranse(string insuranse);
    void setAll_Included(string all_Included);


    //3. На базі кожного похідного класу визначити віртуальні деструктори та продемонструвати відмінність їх роботи від невіртуальних деструкторів.
    ~PlusVoucher() override {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << ">>>Go out from PlusVoucher" << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    }
    //4. Кожен клас, що входить в ієрархію, що використовує відкрите наслідування, повинен містити принаймні одну віртуальну функцію.Функціональність зазначених функцій не повинна дублюватися.
    void startUseIt() const override {
        std::cout << "PlusVoucher is using" << std::endl;
        std::cout << "Your number of compartment: " << number_of_compartment << std::endl;
        std::cout << "Here what is included:" << all_Included << std::endl;
    }
};




//1. Для визначеної раніше ієрархії класів додати абстрактного клас та кілька обґрунтованих (не менше трьох) похідних класів.
class NormalVoucher : public Voucher
{
private:
    int number_of_seat;
    string insuranse;
    string breakfast_Included;

public:
    void writeToFile();
    void writeToFile(string fileName);
    NormalVoucher readFromFile();
    NormalVoucher readFromFile(string fileName);

    NormalVoucher();
    NormalVoucher(string country, string city, string date, int cost, int code, string transport,
        int number_of_seat, string insuranse, string breakfast_Included);
    void Copy(NormalVoucher v);
    NormalVoucher getCopy();

    //getters
    int getNumber_of_seat();
    string getInsuranse();
    string getBreakfast_Included();

    //setters
    void setNumber_of_seat(int number_of_seat);
    void setInsuranse(string insuranse);
    void setBreakfast_Included(string breakfast_Included);

    //3. На базі кожного похідного класу визначити віртуальні деструктори та продемонструвати відмінність їх роботи від невіртуальних деструкторів.
    ~NormalVoucher() override {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << ">>>Go out from NormalVoucher" << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    }

    //4. Кожен клас, що входить в ієрархію, що використовує відкрите наслідування, повинен містити принаймні одну віртуальну функцію.Функціональність зазначених функцій не повинна дублюватися.
    void startUseIt() const override {
        std::cout << "NormalVoucher is using" << std::endl;
        std::cout << "Your number of seat: " << number_of_seat << std::endl;
        std::cout << "Here your breakfast:" << breakfast_Included << std::endl;
    }

};


//1. Для визначеної раніше ієрархії класів додати абстрактного клас та кілька обґрунтованих (не менше трьох) похідних класів.
class CutVoucher : public Voucher
{
private:
    bool hasAdditionalStaff;
    string wifi_password;

public:
    void writeToFile();
    void writeToFile(string fileName);
    CutVoucher readFromFile();
    CutVoucher readFromFile(string fileName);

    CutVoucher();
    CutVoucher(string country, string city, string date, int cost, int code, string transport,
        string wifi_password, bool hasAdditionalStaff);
    void Copy(CutVoucher v);
    CutVoucher getCopy();

    //getters
    bool getHasAdditionalStaff();
    string getWifi_password();

    //setters
    void setHasAdditionalStaff(bool hasAdditionalStaff);
    void setWifi_password(string wifi_password);


    //3. На базі кожного похідного класу визначити віртуальні деструктори та продемонструвати відмінність їх роботи від невіртуальних деструкторів.
    ~CutVoucher() override {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << ">>>Go out from CutVoucher" << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    }

    //4. Кожен клас, що входить в ієрархію, що використовує відкрите наслідування, повинен містити принаймні одну віртуальну функцію.Функціональність зазначених функцій не повинна дублюватися.
    void startUseIt() const override {
        std::cout << "CutVoucher is using" << std::endl;
        std::cout << "You was connected to Wifi" << std::endl;
    }

};






