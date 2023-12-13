#include "Voucher.h"
#include <windows.h>

Voucher::Voucher() : country(""), city(""), date(""), cost(0), code(0), transport("") {}


Voucher::Voucher(string country, string city, string date, int cost, int code, string transport) {
    this->country = country;
    this->city = city;
    this->date = date;
    this->cost = cost;
    this->code = code;
    this->transport = transport;
}

Voucher::Voucher(string country, string city, int date) {
    this->country = country;
    this->city = city;
    this->date = date;
}

Voucher::~Voucher() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << ">>>Go out from Voucher: " << country << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}


//getters
string Voucher::getCountry() {
    return country;
}

string Voucher::getCity() {
    return city;
}

string Voucher::getDate() {
    return date;
}

int Voucher::getCost() {
    return cost;
}

int Voucher::getCode() {
    return code;
}

string Voucher::getTransport() {
    return transport;
}

//setters
void Voucher::setCountry(string country) {
    this->country = country;
}

void Voucher::setCity(string city) {
    this->city = city;
}

void Voucher::setDate(string date) {
    this->date = date;
}

void Voucher::setCost(int cost) {
    this->cost = cost;
}

void Voucher::setCode(int code) {
    this->code = code;
}

void Voucher::setTransport(string transport) {
    this->transport = transport;
}
