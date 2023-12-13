#include "Voucher.h"

CutVoucher::CutVoucher() {}
CutVoucher::CutVoucher(string country, string city, string date, int cost, int code, string transport,
    string wifi_password, bool hasAdditionalStaff)
    :Voucher(country, city, date, cost, code, transport) {
    this->hasAdditionalStaff = hasAdditionalStaff;
    this->wifi_password = wifi_password;
}


void CutVoucher::Copy(CutVoucher v) {
    this->Voucher::country = v.Voucher::country;
    this->Voucher::date = v.Voucher::date;
    this->Voucher::cost = v.Voucher::cost;
    this->setCode(v.getCode());
    this->setTransport(v.getTransport());
    this->setCity(v.getCity());

    this->hasAdditionalStaff = v.hasAdditionalStaff;
    this->wifi_password = v.wifi_password;
}

CutVoucher CutVoucher::getCopy() {
    return CutVoucher(country, this->getCity(), date, cost, this->getCode(), this->getTransport(),
        wifi_password, hasAdditionalStaff);
}

bool CutVoucher::getHasAdditionalStaff() {
    return hasAdditionalStaff;
}

string CutVoucher::getWifi_password() {
    return wifi_password;
}

void CutVoucher::setHasAdditionalStaff(bool hasAdditionalStaff) {
    this->hasAdditionalStaff = hasAdditionalStaff;
}

void CutVoucher::setWifi_password(string wifi_password) {
    this->wifi_password = wifi_password;
}


void CutVoucher::writeToFile() {
    ofstream wf("info_CutVoucher.txt");
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(CutVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}

void CutVoucher::writeToFile(string fileName) {
    ofstream wf(fileName);
    if (!wf) {
        cout << "Cannot open file!" << endl;
        return;
    }
    wf.write((char*)this, sizeof(CutVoucher));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }

}

CutVoucher CutVoucher::readFromFile() {
    ifstream rf("info_CutVoucher.txt");
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return CutVoucher();
    }

    static CutVoucher rstu;

    rf.read((char*)&rstu, sizeof(CutVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return CutVoucher();
    }

    return rstu;
}

CutVoucher CutVoucher::readFromFile(string fileName) {
    ifstream rf(fileName);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return CutVoucher();
    }

    static CutVoucher rstu;

    rf.read((char*)&rstu, sizeof(CutVoucher));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return CutVoucher();
    }

    return rstu;
}

