#include "Student.h"
#include <windows.h>

Student::Student() {}

Student::Student(string RNTRC, string name, string surname, string lastname, int age, string email,
    string phone_number, string address,
    string date_of_admission, bool isGraduated, string atestat, int number_of_record_book, string document,
    string group, string speciality, int course)
    :Human(RNTRC, name, surname, lastname, age, email, phone_number, address) {

    this->date_of_admission = date_of_admission;
    this->isGraduated = isGraduated;
    this->atestat = atestat;
    this->number_of_record_book = number_of_record_book;
    this->document = document;
    this->group = group;
    this->speciality = speciality;
    this->course = course;
}

void Student::Copy(Student h) {
    this->setRNTRC(h.getRNTRC());
    this->Human::name = h.Human::name;
    this->Human::surname = h.Human::surname;
    this->Human::lastname = h.Human::lastname;
    this->Human::age = h.Human::age;
    this->Human::email = h.Human::email;
    this->Human::phone_number = h.Human::phone_number;
    this->Human::address = h.Human::address;

    this->date_of_admission = h.date_of_admission;
    this->isGraduated = h.isGraduated;
    this->atestat = h.atestat;
    this->number_of_record_book = h.number_of_record_book;
    this->document = h.document;
    this->group = h.group;
    this->speciality = h.speciality;
    this->course = h.course;
}


Student Student::getCopy() {
    return Student(RNTRC, name, surname, lastname, age, email, phone_number, address, date_of_admission,
        isGraduated, atestat, number_of_record_book, document, group, speciality, course);
}

Student::~Student() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << ">>>Go out from Student from course: " << course << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


//getters
Voucher* Student::getVoucher() {
    return voucher;
}

string Student::getDate_of_admission() {
    return date_of_admission;
}

bool Student::getIsGraduated() {
    return isGraduated;
}

string Student::getAtestat() {
    return atestat;
}

int Student::getNumber_of_record_book() {
    return number_of_record_book;
}

string Student::getDocument() {
    return document;
}

string Student::getGroup() {
    return group;
}

string Student::getSpeciality() {
    return speciality;
}

int Student::getCourse() {
    return course;
}

//setters
void Student::setVoucher(Voucher* voucher) {
    this->voucher = voucher;
}

void Student::setDate_of_admission(string date_of_admission) {
    this->date_of_admission = date_of_admission;
}

void Student::setIsGraduated(bool isGraduated) {
    this->isGraduated = isGraduated;
}

void Student::setAtestat(string atestat) {
    this->atestat = atestat;
}

void Student::setNumber_of_record_book(int number_of_record_book) {
    this->number_of_record_book = number_of_record_book;
}

void Student::setDocument(string document) {
    this->document = document;
}

void Student::setGroup(string group) {
    this->group = group;
}

void Student::setSpeciality(string speciality) {
    this->speciality = speciality;
}

void Student::setCourse(int course) {
    this->course = course;
}


void Student::writeToFile() {
    ofstream wf("info_Student.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(Student));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void Student::writeToFile(string fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(Student));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

Student Student::readFromFile() {
    ifstream rf("info_Student.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return Student();
    }

    static Student rstu;

    rf.read((char*)&rstu, sizeof(Student));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return Student();
    }

    return rstu;
}

Student Student::readFromFile(string fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return Student();
    }

    static Student rstu;

    rf.read((char*)&rstu, sizeof(Student));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return Student();
    }

    return rstu;
}