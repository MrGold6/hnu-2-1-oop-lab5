#include "Voucher.h"

NormalVoucher::NormalVoucher() {}
NormalVoucher::NormalVoucher(string country, string city, string date, int cost, int code, string transport,
    int number_of_seat, string insuranse, string breakfast_Included)
    :Voucher(country, city, date, cost, code, transport) {
    this->number_of_seat = number_of_seat;
    this->insuranse = insuranse;
    this->breakfast_Included = breakfast_Included;
}


void NormalVoucher::Copy(NormalVoucher v) {
    this->Voucher::country = v.Voucher::country;
    this->Voucher::date = v.Voucher::date;
    this->Voucher::cost = v.Voucher::cost;
    this->setCode(v.getCode());
    this->setTransport(v.getTransport());
    this->setCity(v.getCity());

    this->number_of_seat = v.number_of_seat;
    this->insuranse = v.insuranse;
    this->breakfast_Included = v.breakfast_Included;
}

NormalVoucher NormalVoucher::getCopy() {
    return NormalVoucher(country, this->getCity(), date, cost, this->getCode(), this->getTransport(),
        number_of_seat, insuranse, breakfast_Included);
}

int NormalVoucher::getNumber_of_seat() {
    return number_of_seat;
}

string NormalVoucher::getInsuranse() {
    return insuranse;
}

string NormalVoucher::getBreakfast_Included() {
    return breakfast_Included;
}

void NormalVoucher::setNumber_of_seat(int number_of_seat) {
    this->number_of_seat = number_of_seat;
}

void NormalVoucher::setInsuranse(string insuranse) {
    this->insuranse = insuranse;
}

void NormalVoucher::setBreakfast_Included(string breakfast_Included) {
    this->breakfast_Included = breakfast_Included;
}


void NormalVoucher::writeToFile() {
    ofstream wf("info_NormalVoucher.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(NormalVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void NormalVoucher::writeToFile(string fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(NormalVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

NormalVoucher NormalVoucher::readFromFile() {
    ifstream rf("info_NormalVoucher.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return NormalVoucher();
    }

    static NormalVoucher rstu;

    rf.read((char*)&rstu, sizeof(NormalVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return NormalVoucher();
    }

    return rstu;
}

NormalVoucher NormalVoucher::readFromFile(string fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return NormalVoucher();
    }

    static NormalVoucher rstu;

    rf.read((char*)&rstu, sizeof(NormalVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return NormalVoucher();
    }

    return rstu;    
}

