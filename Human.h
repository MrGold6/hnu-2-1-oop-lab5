#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Human
{
protected:
    string RNTRC;
    string name;
    string surname;
    string lastname;
    int age;
public:
    string email;
    string phone_number;
    string address;

    Human();
    Human(string RNTRC, string name, string surname, string lastname, int age, string address);
    Human(string RNTRC, string name, string surname, string lastname, int age, string email, string phone_number, string address);
    void Copy(Human t);
    Human getCopy();
    ~Human();

    //getters
    string getRNTRC();
    string getName();
    string getSurname();
    string getLastname();
    int getAge();
    string getEmail();
    string getPhone_number();
    string getAddress();

    //setters
    void setRNTRC(string RNTRC);
    void setName(string name);
    void setSurname(string surname);
    void setLastname(string lastname);
    void setAge(int age);
    void setEmail(string email);
    void setPhone_number(string phone_number);
    void setAddress(string address);

    void writeToFile();
    void writeToFile(string fileName);
    Human readFromFile();
    Human readFromFile(string fileName);
};

