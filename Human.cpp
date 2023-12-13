#include "Human.h"
#include <windows.h>

Human::Human() : RNTRC(""), name(""), surname(""), lastname(""), age(0), email(""), phone_number(""), address("") {}


Human::Human(string RNTRC, string name, string surname, string lastname, int age,
    string email, string phone_number, string address) {
    this->RNTRC = RNTRC;
    this->name = name;
    this->surname = surname;
    this->lastname = lastname;
    this->age = age;
    this->email = email;
    this->phone_number = phone_number;
    this->address = address;
}

Human::Human(string RNTRC, string name, string surname, string lastname, int age, string address) {
    this->RNTRC = RNTRC;
    this->name = name;
    this->surname = surname;
    this->lastname = lastname;
    this->age = age;
    this->address = address;
}

void Human::Copy(Human h) {
    this->RNTRC = h.RNTRC;
    this->name = h.name;
    this->surname = h.surname;
    this->lastname = h.lastname;
    this->age = h.age;
    this->email = h.email;
    this->phone_number = h.phone_number;
    this->address = h.address;
}

Human Human::getCopy() {
    return Human(RNTRC, name, surname, lastname, age, email, phone_number, address);
}

Human::~Human() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << ">>>Go out from Human: " << surname << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


//getters
string Human::getRNTRC() {
    return RNTRC;
}

string Human::getName() {
    return name;
}

string Human::getSurname() {
    return surname;
}

string Human::getLastname() {
    return lastname;
}

int Human::getAge() {
    return age;
}

string Human::getEmail() {
    return email;
}

string Human::getPhone_number() {
    return phone_number;
}

string Human::getAddress() {
    return address;
}

//setters
void Human::setRNTRC(string RNTRC) {
    this->RNTRC = RNTRC;
}

void Human::setName(string name) {
    this->name = name;
}

void Human::setSurname(string surname) {
    this->surname = surname;
}

void Human::setLastname(string lastname) {
    this->lastname = lastname;
}

void Human::setAge(int age) {
    this->age = age;
}

void Human::setEmail(string email) {
    this->email = email;
}

void Human::setPhone_number(string phone_number) {
    this->phone_number = phone_number;
}

void Human::setAddress(string address) {
    this->address = address;
}

void Human::writeToFile() {
    ofstream wf("info_Human.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(Human));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void Human::writeToFile(string fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(Human));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

Human Human::readFromFile() {
    ifstream rf("info_Human.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return Human();
    }

    static Human rstu;

    rf.read((char*)&rstu, sizeof(Human));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return Human();
    }

    return rstu;
}

Human Human::readFromFile(string fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return Human();
    }

    static Human rstu;

    rf.read((char*)&rstu, sizeof(Human));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return Human();
    }

    return rstu;
}