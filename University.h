#include "TradeUnion.h"

class University
{
private:
    Human rector;
    vector<Student*> students;
    int count;
    bool isCertified;
    string phone_number;

public:
    string name;
    static string dateOfCreation;
    TradeUnion tradeUnion = TradeUnion();


    University();
    University(string name, int count, Human rector);
    University(string name, int count, string phone_number, bool isCertified,
        Human rector, vector<Student*> students,
        string t_name, int t_count, string t_dateOfCreation, Student head, bool t_isApproved,
        vector<Student*> t_students, vector<Voucher*> t_vouchers, string t_document);
    void Copy(University t);
    University getCopy();
    ~University();

    //getters
    string getName();
    int getCount();
    bool getIsCertified();
    string getPhone_number();
    Human getRector();
    vector<Student*> getStudents();

    //setters
    void setName(string name);
    void setCount(int count);
    void setIsCertified(bool isCertified);
    void setPhone_number(int phone_number);
    void setRector(Human rector);
    void setStudents(vector<Student*> students);

    void writeToFile();
    void writeToFile(const char* fileName);
    University RD();
    University RD(const char* fileName);

    static void greeting() {
        cout << "Welcome to University. University was created at " << dateOfCreation << endl;
    }

    //3. Для наявних в проекті класів застосувати перевантаження операторів *, =, +=, -=, *=,[] - як функції-члени класу. Продемонструвати використання вказаних операцій.
    // Перевантаження оператора "[]"
    Student* operator[](size_t index) {
        if (index < students.size()) {
            return students[index];
        }
        else {
            return students[0];
        }
    }

};

//2. Реалізувати віртуальне наслідування.
//the problem of diamant
class X: public virtual Voucher
{
public:
    X();
    ~X();
};


class Y : public virtual X
{
public:
    Y();
    ~Y();
};

class Z : public virtual X
{
public:
    Z();
    ~Z();
    static void zavd9();
};


class XYZ : public Y, public Z
{
public:
    XYZ();
    ~XYZ();

    void startUseIt() const override {
        std::cout << "XYZ is using" << std::endl;
    }
};
