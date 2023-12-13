#include <string>
#include <fstream>
#include <vector>

#include "University.h"

//5. Створити 2 типи об’єктів – статичні та динамічні (по 5). Передбачити усі можливі виключні ситуації роботи з динамічною пам’яттю (з демонстрацією роботи через try-catch та throw - не менше трьох).
CutVoucher* vouchers_5[5];
TradeUnion tradeUniouns_5[5];

//6. Для видалення об’єкта з масивів передбачити методи Service_Static та Service_Dinamic. Видалення об’єкта даним методом здійснюється за певним критерієм (задається студентом самостійно, наприклад: колір, розмір, кількість, більше, менше, числові дані тощо). Передбачити усі можливі виключні ситуації роботи з динамічною пам’яттю (з демонстрацією роботи через try-catch та throw - не менше трьох).
static void Service_Static(string date) {
    bool wasFounded = false;
    for (int i = 0; i < 5; i++) {
        if (tradeUniouns_5[i].getDateOfCreation() == date) {
            tradeUniouns_5[i] = TradeUnion();
            wasFounded = true;
        }
        if (wasFounded != true) {
            throw std::runtime_error("Object not found in dynamicArray with the specified size.");
        }
    }

}

static void Service_Dynamic(string country) {
    bool wasFounded = false;

    for (int i = 0; i < 5; i++) {
        if (vouchers_5[i]->getCountry() == country) {
            delete vouchers_5[i];
            vouchers_5[i] = nullptr;
            wasFounded = true;
        }

    }
    if (wasFounded != true) {
        throw std::runtime_error("Object not found in dynamicArray with the specified size.");
    }
}

//7. Визначити в функцію Service, яка в якості параметра отримує об’єкт класу, і яка оперуючи визначеними раніше методами Read, Write. Вказані методі записують у файл та читають з файлу поля даних. Передбачити усі можливі виключні ситуації роботи з файлами (з демонстрацією роботи через try-catch та throw - не менше п’яти - не менше п’яти). Ім’я створюваного файлу є параметром, що задається в командному рядку (робота програми здійснюється саме з виклику даного методу у функції main() ).
static void Service(const char* fileName, TradeUnion& obj) {
    //5 
    try {
        obj.writeToFile(fileName);
        std::cout << "Object successfully written to file." << std::endl;

        obj = obj.RD(fileName);
        std::cout << "Object successfully read from file. Date from file: " << obj.getDateOfCreation() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

}

int main()
{
    vouchers_5[0] = new CutVoucher("America0", "New York", "11.11.2003", 300 + 0, 223, "plane", "ann12", true);
    vouchers_5[1] = new CutVoucher("America1", "New York", "11.11.2003", 300 + 1, 223, "plane", "ann12", true);
    vouchers_5[2] = new CutVoucher("America2", "New York", "11.11.2003", 300 + 2, 223, "plane", "ann12", true);
    vouchers_5[3] = new CutVoucher("America3", "New York", "11.11.2003", 300 + 3, 223, "plane", "ann12", true);
    vouchers_5[4] = new CutVoucher("America4", "New York", "11.11.2003", 300 + 4, 223, "plane", "ann12", true);

    Student head = Student("2030040", "Nastya", "Bin", "Oleksandrivna", 18, "head@gmail.com", "058938593", "Nov, 9",
        "19.11.2023", false, "School 5", 883, "zal3", "KI2c-22-2", "computer engeneering", 4);

    tradeUniouns_5[0] = TradeUnion("a", 0 + 1, "12.02.2000", head, true);
    tradeUniouns_5[1] = TradeUnion("a", 1 + 1, "12.02.2001", head, true);
    tradeUniouns_5[2] = TradeUnion("a", 2 + 1, "12.02.2002", head, true);
    tradeUniouns_5[3] = TradeUnion("a", 3 + 1, "12.02.2003", head, true);
    tradeUniouns_5[4] = TradeUnion("a", 4 + 1, "12.02.2004", head, true);


    cout << "TradeUnion static massive before deleting:" << endl;
    for (int i = 0; i < 5; i++) {
        if (tradeUniouns_5[i].getDateOfCreation() != "")
            cout << tradeUniouns_5[i].getDateOfCreation() << endl;
    }

    cout << "Voucher static massive before deleting:" << endl;
    for (int i = 0; i < 5; i++) {
        if (vouchers_5[i] != nullptr)
            cout << vouchers_5[i]->getCountry() << endl;
    }

   

    try {
        Service_Static("12.02.2000");
        Service_Dynamic("America0");

        cout << "TradeUnion static massive before deleting:" << endl;
        for (int i = 0; i < 5; i++) {
            if (tradeUniouns_5[i].getDateOfCreation() != "")
                cout << tradeUniouns_5[i].getDateOfCreation() << endl;
        }

        cout << "Voucher static massive before deleting:" << endl;
        for (int i = 0; i < 5; i++) {
            if (vouchers_5[i] != nullptr)
                cout << vouchers_5[i]->getCountry() << endl;
        };

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    CutVoucher* vouchers[5];
    TradeUnion tradeUniouns[5];

    for (int i = 0; i < 5; i++) {
        vouchers[i] = new CutVoucher("America", "New York", "11.11.2003", 300 + i, 223, "plane", "ann12", true);
    }




    for (int i = 0; i < 5; i++) {
        tradeUniouns[i] = TradeUnion("a", i + 1, "12.02.2001", head, true);
    }

    cout << "TradeUnion massive: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Name: " << tradeUniouns[i].getName() << endl;
        cout << "Count: " << tradeUniouns[i].getCount() << endl;
        cout << "DateOfCreation: " << tradeUniouns[i].getDateOfCreation() << endl;
        cout << "Head Name: " << tradeUniouns[i].getHead().getName() << endl;
        cout << "Head Surname: " << tradeUniouns[i].getHead().getSurname() << endl;
        cout << "Head Lastname: " << tradeUniouns[i].getHead().getLastname() << endl;
        cout << "Head Age: " << tradeUniouns[i].getHead().getAge() << endl;
        cout << endl;
    }
    cout << endl;


    cout << "Voucher massive: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Country: " << vouchers[i]->getCountry() << endl;
        cout << "City: " << vouchers[i]->getCity() << endl;
        cout << "Code: " << vouchers[i]->getCode() << endl;
        cout << "Cost: " << vouchers[i]->getCost() << endl;
        cout << "Date: " << vouchers[i]->getDate() << endl;
        cout << "Additional Staff: " << vouchers[i]->getHasAdditionalStaff() << endl;
        cout << "Wifi password: " << vouchers[i]->getWifi_password() << endl;
        cout << "Transport: " << vouchers[i]->getTransport() << endl;
        cout << endl;

    }
    cout << endl;
    cout << endl;

    //9. Продемонструвати поліморфні виклики методів трьома способами. Продемонструвати зміну форми об’єкта із застосуванням принципу поліморфізму.
    //  10. Продемонструвати поліморфні виклики методів за допомогою пізнього зв'язуванням (динамічного) та раннього (статичним) зв'язуванням. Продемонструвати зміну форми об’єкта із застосуванням принципу поліморфізму.
    //раннього (статичним) зв'язуванням
    NormalVoucher voucher1 = NormalVoucher();

    voucher1.setCountry("Poland");
    voucher1.setCity("Warshaw");
    voucher1.setCode(8593);
    voucher1.setCost(400);
    voucher1.setDate("06.03.2023");
    voucher1.setNumber_of_seat(12);
    voucher1.setInsuranse("AOB");
    voucher1.setTransport("bus");
    voucher1.setBreakfast_Included("apple and croissant");

    voucher1.writeToFile();
    voucher1 = voucher1.readFromFile();

    //поліморфні виклики методів
    voucher1.startUseIt();

    PlusVoucher* voucher2 = new PlusVoucher();

    voucher2->setCountry("England");
    voucher2->setCity("London");
    voucher2->setCode(3320);
    voucher2->setCost(500);
    voucher2->setDate("9.01.2023");
    voucher2->setNumber_of_compartment(19);
    voucher2->setInsuranse("AOB");
    voucher2->setTransport("train");
    voucher2->setAll_Included("breakfast, wifi");

    //поліморфні виклики методів
    voucher2->startUseIt();


    NormalVoucher* voucher3 = new NormalVoucher();

    voucher3->setCountry("Germany");
    voucher3->setCity("Dresden");
    voucher3->setCode(8593);
    voucher3->setCost(653);
    voucher3->setDate("01.06.2023");
    voucher3->setNumber_of_seat(51);
    voucher3->setInsuranse("AOK");
    voucher3->setTransport("plane");
    voucher3->setBreakfast_Included("apple and croissant");

    //поліморфні виклики методів
    voucher3->startUseIt();

    cout << "<<<<<<<<" << endl;
    //пізнього зв'язуванням (динамічного)
    Voucher* globalVoucher = new CutVoucher();
    globalVoucher->setCountry("Poland");
    globalVoucher->setCity("Warshaw");
    globalVoucher->setCode(8593);
    globalVoucher->setCost(400);
    globalVoucher->setDate("06.03.2023");
    globalVoucher->setTransport("bus");

    globalVoucher->startUseIt();

    //Продемонструвати зміну форми об’єкта із застосуванням принципу поліморфізму.
    globalVoucher = new PlusVoucher();
    globalVoucher->setCountry("England");
    globalVoucher->setCity("London");
    globalVoucher->setCode(3320);
    globalVoucher->setCost(500);
    globalVoucher->setDate("9.01.2023");
    globalVoucher->setTransport("train");

    globalVoucher->startUseIt();

    cout << endl;


    cout << "<" << endl;
    //11. Продемонструвати механізм обходу віртуальних функцій для виклику одного метода.
    Voucher* baseObj;
    CutVoucher derivedObj;

    baseObj = &derivedObj;
    baseObj->startUseIt();
    cout << "<" << endl;



    vector<Voucher*> vouchersVector;
    vouchersVector.push_back(voucher2);
    vouchersVector.push_back(voucher3);

    int a = 0;

    //8. Програма повинна надавати користувачу можливість вибору створення та знищення певного об’єкта (основні сутності) засобами меню.
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    cout << "Choose object that you want create and delete:" << endl;

    cout << "1 - Students" << endl;
    cout << "2 - Trade Union" << endl;
    cout << "3 - University" << endl;
    cin >> a;

    switch (a)
    {
    case 1: {
        Student* student = new Student();
        student->setAddress("England");
        student->setAge(15);
        student->setAtestat("school 10");
        student->setCourse(2);
        student->setDate_of_admission("9.01.2020");
        student->setDocument("stud_124");
        student->setEmail("e@gmail.com");
        student->setGroup("KI2s-22-2");
        student->setIsGraduated(false);
        student->setLastname("Petrovich");
        student->setSurname("Gah");
        student->setName("Max");
        student->setNumber_of_record_book(39204);
        student->setPhone_number("9493049940");
        student->setRNTRC("38490294");
        student->setSpeciality("computer engeneer");

        cout << "Student: " << endl;
        cout << "Name: " << student->getName() << endl;
        cout << "Surname: " << student->getSurname() << endl;
        cout << "Speciality: " << student->getSpeciality() << endl;
        cout << "Course: " << student->getCourse() << endl;
        cout << "Group: " << student->getGroup() << endl;
        cout << endl;

        delete student;
    } break;
    case 2: {


        Student* student = new Student();
        student->setAddress("England");
        student->setAge(15);
        student->setAtestat("school 10");
        student->setCourse(2);
        student->setDate_of_admission("9.01.2020");
        student->setDocument("stud_124");
        student->setEmail("e@gmail.com");
        student->setGroup("KI2s-22-2");
        student->setIsGraduated(false);
        student->setLastname("Petrovich");
        student->setSurname("Gah");
        student->setName("Max");
        student->setNumber_of_record_book(39204);
        student->setPhone_number("9493049940");
        student->setRNTRC("38490294");
        student->setSpeciality("computer engeneer");

        Student* student1 = new Student();
        student1->setAddress("Poland");
        student1->setAge(16);
        student1->setAtestat("school 11");
        student1->setCourse(3);
        student1->setDate_of_admission("08.02.2023");
        student1->setDocument("stud_937");
        student1->setEmail("as@gmail.com");
        student1->setGroup("KI2s-22-1");
        student1->setIsGraduated(false);
        student1->setLastname("Ellen");
        student1->setSurname("Vit");
        student1->setName("Ken");
        student1->setNumber_of_record_book(9377);
        student1->setPhone_number("1534042945");
        student1->setRNTRC("18430896");
        student1->setSpeciality("programming engeneer");

        Student* student2 = new Student();
        student2->setAddress("Germany");
        student2->setAge(18);
        student2->setAtestat("school 28");
        student2->setCourse(4);
        student2->setDate_of_admission("11.04.2019");
        student2->setDocument("stud_432");
        student2->setEmail("ttt@gmail.com");
        student2->setGroup("KI2s-22-2");
        student2->setIsGraduated(true);
        student2->setLastname("Pinned");
        student2->setSurname("Jun");
        student2->setName("Ern");
        student2->setNumber_of_record_book(2142);
        student2->setPhone_number("1420421922");
        student2->setRNTRC("12434833");
        student2->setSpeciality("programming engeneer");



        vector<Student*> t_students;
        t_students.push_back(student);
        t_students.push_back(student1);


        TradeUnion tradeUnion = TradeUnion();

        tradeUnion.setName("Profspilca");
        tradeUnion.setCount(10);
        tradeUnion.setDateOfCreation("02.02.2001");
        tradeUnion.setHead(head);
        tradeUnion.setDocument("Certificate");
        tradeUnion.setIsApproved(true);

        tradeUnion.setStudents(t_students);
        tradeUnion.setVouchers(vouchersVector);

        for (int i = 0; i < t_students.size(); i++) {
            tradeUnion.giveVoucher(t_students[i], vouchersVector[i]);
        }

        cout << "TradeUnion: " << endl;
        cout << "Name: " << tradeUnion.getName() << endl;
        cout << "Count: " << tradeUnion.getCount() << endl;
        cout << "DateOfCreation: " << tradeUnion.getDateOfCreation() << endl;
        cout << "Head Name: " << tradeUnion.getHead().getName() << endl;
        cout << "Head Surname: " << tradeUnion.getHead().getSurname() << endl;
        cout << "Head Lastname: " << tradeUnion.getHead().getLastname() << endl;
        cout << "Head Age: " << tradeUnion.getHead().getAge() << endl;
        cout << endl;

        cout << "Students in trade union: " << tradeUnion.getName() << endl;
        for (int i = 0; i < tradeUnion.getStudents().size(); i++) {
            cout << "Student: " << endl;
            cout << "Name: " << tradeUnion.getStudents()[i]->getName() << endl;
            cout << "Surname: " << tradeUnion.getStudents()[i]->getSurname() << endl;
            cout << "Speciality: " << tradeUnion.getStudents()[i]->getSpeciality() << endl;
            cout << "Course: " << tradeUnion.getStudents()[i]->getCourse() << endl;
            cout << "Group: " << tradeUnion.getStudents()[i]->getGroup() << endl;
            cout << endl;

            cout << "Voucher: " << endl;
            cout << "Country: " << tradeUnion.getStudents()[i]->getVoucher()->getCity() << endl;
            cout << "City: " << tradeUnion.getStudents()[i]->getVoucher()->getCity() << endl;
            cout << "Code: " << tradeUnion.getStudents()[i]->getVoucher()->getCode() << endl;
            cout << "Cost: " << tradeUnion.getStudents()[i]->getVoucher()->getCost() << endl;
            cout << "Date: " << tradeUnion.getStudents()[i]->getVoucher()->getDate() << endl;
            cout << "Transport: " << tradeUnion.getStudents()[i]->getVoucher()->getTransport() << endl;
            cout << endl;
            cout << endl;
        }


        delete student;
        delete student1;
        delete student2;

    } break;
    case 3: {
        Student* student = new Student();
        student->setAddress("England");
        student->setAge(15);
        student->setAtestat("school 10");
        student->setCourse(2);
        student->setDate_of_admission("9.01.2020");
        student->setDocument("stud_124");
        student->setEmail("e@gmail.com");
        student->setGroup("KI2s-22-2");
        student->setIsGraduated(false);
        student->setLastname("Petrovich");
        student->setSurname("Gah");
        student->setName("Max");
        student->setNumber_of_record_book(39204);
        student->setPhone_number("9493049940");
        student->setRNTRC("38490294");
        student->setSpeciality("computer engeneer");

        Student* student1 = new Student();
        student1->setAddress("Poland");
        student1->setAge(16);
        student1->setAtestat("school 11");
        student1->setCourse(3);
        student1->setDate_of_admission("08.02.2023");
        student1->setDocument("stud_937");
        student1->setEmail("as@gmail.com");
        student1->setGroup("KI2s-22-1");
        student1->setIsGraduated(false);
        student1->setLastname("Ellen");
        student1->setSurname("Vit");
        student1->setName("Ken");
        student1->setNumber_of_record_book(9377);
        student1->setPhone_number("1534042945");
        student1->setRNTRC("18430896");
        student1->setSpeciality("programming engeneer");

        Student* student2 = new Student();
        student2->setAddress("Germany");
        student2->setAge(18);
        student2->setAtestat("school 28");
        student2->setCourse(4);
        student2->setDate_of_admission("11.04.2019");
        student2->setDocument("stud_432");
        student2->setEmail("ttt@gmail.com");
        student2->setGroup("KI2s-22-2");
        student2->setIsGraduated(true);
        student2->setLastname("Pinned");
        student2->setSurname("Jun");
        student2->setName("Ern");
        student2->setNumber_of_record_book(2142);
        student2->setPhone_number("1420421922");
        student2->setRNTRC("12434833");
        student2->setSpeciality("programming engeneer");



        vector<Student*> t_students;
        t_students.push_back(student);
        t_students.push_back(student1);


        Human rector = Human("930285", "Sem", "Vog", "Pitterson", 40, "rector@gmail.com", "324238513", "Vod, 10");

        vector<Student*> students;
        students.push_back(student);
        students.push_back(student1);
        students.push_back(student2);

        University university = University("HNU", 10, "093827930", true, rector, students,
            "Profspilca2", 10, "02.02.2003", head, true, t_students, vouchersVector, "doc");

        cout << "University: " << endl;
        cout << "Name: " << university.getName() << endl;
        cout << "Count: " << university.getCount() << endl;
        cout << "DateOfCreation: " << university.dateOfCreation << endl;
        cout << "Rector Name: " << university.getRector().getName() << endl;
        cout << "Rector Surname: " << university.getRector().getSurname() << endl;
        cout << "Rector Lastname: " << university.getRector().getLastname() << endl;
        cout << "Rector Age: " << university.getRector().getAge() << endl;
        cout << endl;

        cout << "Students: " << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << "Student: " << endl;
            cout << "Name: " << university.getStudents()[i]->getName() << endl;
            cout << "Surname: " << university.getStudents()[i]->getSurname() << endl;
            cout << "Speciality: " << university.getStudents()[i]->getSpeciality() << endl;
            cout << "Course: " << university.getStudents()[i]->getCourse() << endl;
            cout << "Group: " << university.getStudents()[i]->getGroup() << endl;
            cout << endl;
        }


        cout << "TradeUnion: " << endl;
        cout << "Name: " << university.tradeUnion.getName() << endl;
        cout << "Count: " << university.tradeUnion.getCount() << endl;
        cout << "DateOfCreation: " << university.tradeUnion.getDateOfCreation() << endl;
        cout << "Head Name: " << university.tradeUnion.getHead().getName() << endl;
        cout << "Head Surname: " << university.tradeUnion.getHead().getSurname() << endl;
        cout << "Head Lastname: " << university.tradeUnion.getHead().getLastname() << endl;
        cout << "Head Age: " << university.tradeUnion.getHead().getAge() << endl;
        cout << endl;

        cout << "Students in trade union: " << university.tradeUnion.getName() << endl;
        for (int i = 0; i < university.tradeUnion.getStudents().size(); i++) {
            cout << "Student: " << endl;
            cout << "Name: " << university.tradeUnion.getStudents()[i]->getName() << endl;
            cout << "Surname: " << university.tradeUnion.getStudents()[i]->getSurname() << endl;
            cout << "Speciality: " << university.tradeUnion.getStudents()[i]->getSpeciality() << endl;
            cout << "Course: " << university.tradeUnion.getStudents()[i]->getCourse() << endl;
            cout << "Group: " << university.tradeUnion.getStudents()[i]->getGroup() << endl;
            cout << endl;

        }

        delete student;
        delete student1;
        delete student2;

    } break;

    default:
        break;
    }

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;




    cout << "Voucher: " << endl;
    for (int i = 0; i < vouchersVector.size(); i++) {

    }

    NormalVoucher voucher_copy = NormalVoucher();
    voucher_copy.Copy(voucher1);
    voucher_copy.getCopy();

    cout << "Voucher copy: " << endl;
    cout << "Country: " << voucher_copy.getCountry() << endl;
    cout << "City: " << voucher_copy.getCity() << endl;
    cout << "Code: " << voucher_copy.getCode() << endl;
    cout << "Cost: " << voucher_copy.getCost() << endl;
    cout << "Date: " << voucher_copy.getDate() << endl;
    cout << "Breakfast Included: " << voucher_copy.getBreakfast_Included() << endl;
    cout << "Number of seat: " << voucher_copy.getNumber_of_seat() << endl;
    cout << "Insuranse: " << voucher_copy.getInsuranse() << endl;
    cout << "Transport: " << voucher_copy.getTransport() << endl;
    cout << endl;

    //7. Визначити в функцію Service, яка в якості параметра отримує об’єкт класу, і яка оперуючи визначеними раніше методами Read, Write. Вказані методі записують у файл та читають з файлу поля даних. Передбачити усі можливі виключні ситуації роботи з файлами (з демонстрацією роботи через try-catch та throw - не менше п’яти - не менше п’яти). Ім’я створюваного файлу є параметром, що задається в командному рядку (робота програми здійснюється саме з виклику даного методу у функції main() ).
    cout << "Write and read from file:" << endl;
    Service("file_trade", tradeUniouns[1]);

    //5. Створити 2 типи об’єктів – статичні та динамічні (по 5). Передбачити усі можливі виключні ситуації роботи з динамічною пам’яттю (з демонстрацією роботи через try-catch та throw - не менше трьох).

    // Ситуація 1: викидання виключення при взятті значення з nullptr

    try {
        throw std::exception_ptr();
        vouchers_5[1] = nullptr;
        std::cout << "Dynamic object 1 value: " << vouchers_5[1]->getCity() << std::endl;


    }
    catch (std::exception_ptr& e) {
        cout << "Exception of getting value of nullptr " << std::endl;

    }

    // Ситуація 2: помилка  звертання до неіснуючої комірки масиву
    try {
        throw std::exception();


        std::cout << "Dynamic object 2 value: " << vouchers_5[-5]->getCity() << std::endl;


    }
    catch (std::exception& e) {
        cout << "Exception of getting value from not existiong part of massive: " << std::endl;
    }


    // Ситуація 3: викидання виключення при використанні динамічного об'єкта, який був видалений
    try {
        throw std::bad_exception();

        delete vouchers_5[1];

        std::cout << "Dynamic object 3 value: " << vouchers_5[1]->getCity() << std::endl;


    }
    catch (std::bad_exception& e) {
        cout << "Exception of using deleted object " << std::endl;

    }

    XYZ* xyz = new XYZ();
    xyz->startUseIt();
    delete xyz;
    cout << endl;



}

