#include "Voucher.h"

PlusVoucher::PlusVoucher() {}
PlusVoucher::PlusVoucher(string country, string city, string date, int cost, int code, string transport,
    int number_of_compartment, string insuranse, string all_Included)
    :Voucher(country, city, date, cost, code, transport) {
    this->number_of_compartment = number_of_compartment;
    this->insuranse = insuranse;
    this->all_Included = all_Included;
}


void PlusVoucher::Copy(PlusVoucher v) {
    this->Voucher::country = v.Voucher::country;
    this->Voucher::date = v.Voucher::date;
    this->Voucher::cost = v.Voucher::cost;
    this->setCode(v.getCode());
    this->setTransport(v.getTransport());
    this->setCity(v.getCity());

    this->number_of_compartment = number_of_compartment;
    this->insuranse = insuranse;
    this->all_Included = all_Included;
}

PlusVoucher PlusVoucher::getCopy() {
    return PlusVoucher(country, this->getCity(), date, cost, this->getCode(), this->getTransport(),
        number_of_compartment, insuranse, all_Included);
}


int PlusVoucher::getNumber_of_compartment() {
    return number_of_compartment;
}

string PlusVoucher::getInsuranse() {
    return insuranse;
}

string PlusVoucher::getAll_Included() {
    return all_Included;
}

void PlusVoucher::setNumber_of_compartment(int number_of_compartment) {
    this->number_of_compartment = number_of_compartment;
}

void PlusVoucher::setInsuranse(string insuranse) {
    this->insuranse = insuranse;
}

void PlusVoucher::setAll_Included(string all_Included) {
    this->all_Included = all_Included;
}


void PlusVoucher::writeToFile() {
    ofstream wf("info_PlusVoucher.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(PlusVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void PlusVoucher::writeToFile(string fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(PlusVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

PlusVoucher PlusVoucher::readFromFile() {
    ifstream rf("info_PlusVoucher.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return PlusVoucher();
    }

    static PlusVoucher rstu;

    rf.read((char*)&rstu, sizeof(PlusVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return PlusVoucher();
    }

    return rstu;
}

PlusVoucher PlusVoucher::readFromFile(string fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return PlusVoucher();
    }

    static PlusVoucher rstu;

    rf.read((char*)&rstu, sizeof(PlusVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return PlusVoucher();
    }

    return rstu;
}
