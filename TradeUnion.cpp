#include "TradeUnion.h"
#include <windows.h>


TradeUnion::TradeUnion() :name(""), count(0), dateOfCreation(""), head(Student()), document(""), isApproved(true) {}

TradeUnion::TradeUnion(string name, int count, string dateOfCreation, Student head, bool isApproved) {
    this->name = name;
    this->count = count;
    this->dateOfCreation = dateOfCreation;
    this->document = document;
    this->isApproved = isApproved;
    this->head = head;
}

TradeUnion::TradeUnion(string name, int count, string dateOfCreation, Student head, vector<Voucher*> vouchers,
    vector<Student*> students, string document, bool isApproved) {
    this->name = name;
    this->count = count;
    this->dateOfCreation = dateOfCreation;
    this->document = document;
    this->isApproved = isApproved;
    this->head = head;
    this->vouchers = vouchers;
    this->students = students;
}

void TradeUnion::Copy(TradeUnion t) {
    this->name = t.name;
    this->count = t.count;
    this->dateOfCreation = t.dateOfCreation;
    this->document = t.document;
    this->isApproved = t.isApproved;
    this->head = t.head;
    this->vouchers = t.vouchers;
    this->students = t.students;
}

TradeUnion TradeUnion::getCopy() {
    return TradeUnion(name, count, dateOfCreation, head, vouchers, students, document, isApproved);
}

TradeUnion::~TradeUnion() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << ">>>Go out from TradeUnion: " << name << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


//getters
string TradeUnion::getName() {
    return name;
}

int TradeUnion::getCount() {
    return count;
}

string TradeUnion::getDateOfCreation() {
    return dateOfCreation;
}

Student TradeUnion::getHead() {
    return head;
}

string TradeUnion::getDocument() {
    return document;
}

bool TradeUnion::getIsApproved() {
    return isApproved;
}

vector<Student*> TradeUnion::getStudents() {
    return students;
}

vector<Voucher*> TradeUnion::getVouchers() {
    return vouchers;
}


//setters
void TradeUnion::setName(string name) {
    this->name = name;
}

void TradeUnion::setCount(int count) {
    this->count = count;
}

void TradeUnion::setDateOfCreation(string dateOfCreation) {
    this->dateOfCreation = dateOfCreation;
}

void TradeUnion::setIsApproved(bool isApproved) {
    this->isApproved = isApproved;
}

void TradeUnion::setDocument(string document) {
    this->document = document;
}

void TradeUnion::setHead(Student head) {
    this->head = head;
}

void TradeUnion::setStudents(const vector<Student*> students) {
    this->students = students;
}

void TradeUnion::setVouchers(const vector<Voucher*> vouchers) {
    this->vouchers = vouchers;
}


void TradeUnion::giveVoucher(Student* student, Voucher* voucher) {
    student->setVoucher(voucher);
}


void TradeUnion::writeToFile() {
    ofstream wf("info_TradeUnion.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(TradeUnion));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

//7. Визначити в функцію Service, яка в якості параметра отримує об’єкт класу, і яка оперуючи визначеними раніше методами Read, Write. Вказані методі записують у файл та читають з файлу поля даних. Передбачити усі можливі виключні ситуації роботи з файлами (з демонстрацією роботи через try-catch та throw - не менше п’яти - не менше п’яти). Ім’я створюваного файлу є параметром, що задається в командному рядку (робота програми здійснюється саме з виклику даного методу у функції main() ).
void TradeUnion::writeToFile(const char* fileName) {
    ofstream wf(fileName);
    if (!wf) {
        //Помилка 1: неможливо відкрити файл
        throw std::runtime_error("Cannot open file!");
        return;
    }
    wf.write((char*)this, sizeof(TradeUnion));
    wf.close();
    if (!wf.good()) {
        //Помилка 2: помилка зарипису в файл
        throw std::runtime_error("Error occurred at writing time!");
        return;
    }

}

TradeUnion TradeUnion::RD() {
    ifstream rf("info_TradeUnion.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return TradeUnion();
    }

    static TradeUnion rstu;

    rf.read((char*)&rstu, sizeof(TradeUnion));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return TradeUnion();
    }

    return rstu;
}

//7. Визначити в функцію Service, яка в якості параметра отримує об’єкт класу, і яка оперуючи визначеними раніше методами Read, Write. Вказані методі записують у файл та читають з файлу поля даних. Передбачити усі можливі виключні ситуації роботи з файлами (з демонстрацією роботи через try-catch та throw - не менше п’яти - не менше п’яти). Ім’я створюваного файлу є параметром, що задається в командному рядку (робота програми здійснюється саме з виклику даного методу у функції main() ).
TradeUnion TradeUnion::RD(const char* fileName) {
    ifstream rf(fileName);
    if (!rf) {
        //Помилка 3: неможливо відкрити файл
        throw std::runtime_error("Cannot open file!");
        return TradeUnion();
    }

    static TradeUnion rstu;

    rf.read((char*)&rstu, sizeof(TradeUnion));
    rf.close();
    if (!rf.good()) {
        //Помилка 4: неможливо прочитати файл
        throw std::runtime_error("Error occurred at reading time!");
        return TradeUnion();
    }

    return rstu;
}
