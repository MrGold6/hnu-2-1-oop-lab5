#include <vector>

#include "Student.h"

class TradeUnion {
private:
    Student head;
    vector<Voucher*> vouchers;
    vector<Student*> students;
    string document;
    bool isApproved;

public:
    string name;
    int count;
    string dateOfCreation;


    TradeUnion();
    TradeUnion(string name, int count, string dateOfCreation, Student head, bool isApproved);
    TradeUnion(string name, int count, string dateOfCreation, Student head, vector<Voucher*> vouchers,
        vector<Student*> students, string document, bool isApproved);

    void Copy(TradeUnion t);
    TradeUnion getCopy();
    ~TradeUnion();

    //getters
    string getName();
    int getCount();
    bool getIsApproved();
    string getDateOfCreation();
    string getDocument();
    vector<Voucher*> getVouchers();
    Student getHead();
    vector<Student*> getStudents();

    //setters
    void setName(string name);
    void setCount(int count);
    void setDateOfCreation(string dateOfCreation);
    void setIsApproved(bool isApproved);
    void setDocument(string document);
    void setHead(Student head);
    void setStudents(const vector<Student*> students);
    void setVouchers(const vector<Voucher*> vouchers);
    void giveVoucher(Student* student, Voucher* voucher);



    void writeToFile();
    void writeToFile(const char* fileName);
    TradeUnion RD();
    TradeUnion RD(const char* fileName);

};


