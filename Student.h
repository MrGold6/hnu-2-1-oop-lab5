#include "Human.h"
#include "Voucher.h"

class Student : public Human
{
private:
    string date_of_admission;
    bool isGraduated;
    string atestat;
    int number_of_record_book;
    string document;
    Voucher* voucher;
public:
    string group;
    string speciality;
    int course;

    Student();
    Student(string RNTRC, string name, string surname, string lastname, int age, string email,
        string phone_number, string address,
        string date_of_admission, bool isGraduated, string atestat, int number_of_record_book, string document,
        string group, string speciality, int course);
    void Copy(Student t);
    Student getCopy();
    ~Student();

    //getters
    string getDate_of_admission();
    bool getIsGraduated();
    string getAtestat();
    int getNumber_of_record_book();
    string getDocument();
    string getGroup();
    string getSpeciality();
    int getCourse();
    Voucher* getVoucher();

    //setters
    void setDate_of_admission(string date_of_admission);
    void setIsGraduated(bool isGraduated);
    void setAtestat(string atestat);
    void setNumber_of_record_book(int number_of_record_book);
    void setDocument(string document);
    void setGroup(string group);
    void setSpeciality(string speciality);
    void setCourse(int course);
    void setVoucher(Voucher* voucher);

    void writeToFile();
    void writeToFile(string fileName);
    Student readFromFile();
    Student readFromFile(string fileName);

    using Human::getRNTRC;
    using Human::setRNTRC;


    bool operator<(const Student& other) const {
        return name < other.name;
    }
};

