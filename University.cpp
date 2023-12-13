#include "University.h"
#include <windows.h>

string University::dateOfCreation = "19.11.2021";
University::University() :name(""), count(0), phone_number(""), isCertified(true), rector(Human()) {}

University::University(string name, int count, Human rector) {
    this->name = name;
    this->count = count;
    this->rector = rector;
}

University::University(string name, int count, string phone_number, bool isCertified,
    Human rector, vector<Student*> students,
    string t_name, int t_count, string t_dateOfCreation, Student head, bool t_isApproved,
    vector<Student*> t_students, vector<Voucher*> t_vouchers, string t_document) {
    this->name = name;
    this->count = count;
    this->phone_number = phone_number;
    this->isCertified = isCertified;
    this->rector = rector;
    this->students = students;

    this->tradeUnion.name = t_name;
    this->tradeUnion.count = t_count;
    this->tradeUnion.setHead(head);
    this->tradeUnion.setDateOfCreation(t_dateOfCreation);
    this->tradeUnion.setIsApproved(t_isApproved);
    this->tradeUnion.setDocument(t_document);
    this->tradeUnion.setStudents(t_students);
    this->tradeUnion.setVouchers(t_vouchers);
}

void University::Copy(University u) {
    this->name = u.name;
    this->count = u.count;
    this->phone_number = u.phone_number;
    this->isCertified = u.isCertified;
    this->rector = u.rector;
    this->students = u.students;

    this->tradeUnion.name = u.tradeUnion.name;
    this->tradeUnion.count = u.tradeUnion.count;
    this->tradeUnion.setHead(u.tradeUnion.getHead());
    this->tradeUnion.setDateOfCreation(u.tradeUnion.dateOfCreation);
    this->tradeUnion.setIsApproved(u.tradeUnion.getIsApproved());
    this->tradeUnion.setDocument(u.tradeUnion.getDocument());
    this->tradeUnion.setStudents(u.tradeUnion.getStudents());
    this->tradeUnion.setVouchers(u.tradeUnion.getVouchers());
}


University University::getCopy() {
    return University(name, count, phone_number, isCertified,
        rector, students, tradeUnion.name, tradeUnion.count, tradeUnion.dateOfCreation, tradeUnion.getHead(),
        tradeUnion.getIsApproved(), tradeUnion.getStudents(), tradeUnion.getVouchers(),
        tradeUnion.getDocument());
}

University::~University() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << ">>>Go out from University: " << name << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}




//getters
string University::getName() {
    return name;
}

int University::getCount() {
    return count;
}

bool University::getIsCertified() {
    return isCertified;
}

string University::getPhone_number() {
    return phone_number;
}

Human University::getRector() {
    return rector;
}

vector<Student*> University::getStudents() {
    return students;
}


//setters
void University::setName(string name) {
    this->name = name;
}

void University::setCount(int count) {
    this->count = count;
}


void University::setIsCertified(bool isCertified) {
    this->isCertified = isCertified;
}

void University::setPhone_number(int phone_number) {
    this->phone_number = phone_number;
}

void University::setRector(Human rector) {
    this->rector = rector;
}

void University::setStudents(vector<Student*> students) {
    this->students = students;
}

void University::writeToFile() {
    ofstream wf("info_University.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(University));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void University::writeToFile(const char* fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(University));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

University University::RD() {
    ifstream rf("info_University.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return University();
    }

    static University rstu;

    rf.read((char*)&rstu, sizeof(University));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return University();
    }

    return rstu;
}

University University::RD(const char* fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return University();
    }

    static University rstu;

    rf.read((char*)&rstu, sizeof(University));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return University();
    }

    return rstu;
}

//2. Реалізувати віртуальне наслідування.
//the problem of diamant
X::X(): Voucher("country", "city", "date", 5900, 123, "transport") {
    cout << "X costructor" << endl;
}

X::~X() {
    cout << "X destructor" << endl;
}

Y::Y() :X() {
    cout << "Y costructor" << endl;
}

Y::~Y() {
    cout << "Y destructor" << endl;
}

Z::Z() :X() {
    cout << "Z costructor" << endl;
}
void Z::zavd9() {
    cout << "Zavd 9" << endl;
}

Z::~Z() {
    cout << "Z destructor" << endl;
}

XYZ::XYZ() : X(), Y(), Z() {
    cout << "XYZ costructor" << endl;
}

XYZ::~XYZ() {
    cout << "XYZ destructor" << endl;
}