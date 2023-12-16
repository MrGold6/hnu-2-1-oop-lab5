#include <string>
#include <fstream>

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include "University.h"
#include "MyTemplate.h"

CutVoucher* vouchers_5[5];
TradeUnion tradeUniouns_5[5];

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

static void Service(const char* fileName, TradeUnion& obj) {
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
    Student student = Student();
    student.setAddress("England");
    student.setAge(15);
    student.setAtestat("school 10");
    student.setCourse(2);
    student.setDate_of_admission("9.01.2020");
    student.setDocument("stud_124");
    student.setEmail("e@gmail.com");
    student.setGroup("KI2s-22-2");
    student.setIsGraduated(false);
    student.setLastname("Petrovich");
    student.setSurname("Gah");
    student.setName("Max");
    student.setNumber_of_record_book(39204);
    student.setPhone_number("9493049940");
    student.setRNTRC("38490294");
    student.setSpeciality("computer engeneer");


    Student same_student = Student();
    same_student.setAddress("England");
    same_student.setAge(15);
    same_student.setAtestat("school 10");
    same_student.setCourse(2);
    same_student.setDate_of_admission("9.01.2020");
    same_student.setDocument("stud_124");
    same_student.setEmail("e@gmail.com");
    same_student.setGroup("KI2s-22-2");
    same_student.setIsGraduated(false);
    same_student.setLastname("Petrovich");
    same_student.setSurname("Gah");
    same_student.setName("Max");
    same_student.setNumber_of_record_book(39204);
    same_student.setPhone_number("9493049940");
    same_student.setRNTRC("38490294");
    same_student.setSpeciality("computer engeneer");


    Student student1 = Student();
    student1.setAddress("Poland");
    student1.setAge(16);
    student1.setAtestat("school 11");
    student1.setCourse(3);
    student1.setDate_of_admission("08.02.2023");
    student1.setDocument("stud_937");
    student1.setEmail("as@gmail.com");
    student1.setGroup("KI2s-22-1");
    student1.setIsGraduated(false);
    student1.setLastname("Ellen");
    student1.setSurname("Vit");
    student1.setName("Ken");
    student1.setNumber_of_record_book(9377);
    student1.setPhone_number("1534042945");
    student1.setRNTRC("18430896");
    student1.setSpeciality("programming engeneer");

    Student student2 = Student();
    student2.setAddress("Germany");
    student2.setAge(18);
    student2.setAtestat("school 28");
    student2.setCourse(4);
    student2.setDate_of_admission("11.04.2019");
    student2.setDocument("stud_432");
    student2.setEmail("ttt@gmail.com");
    student2.setGroup("KI2s-22-2");
    student2.setIsGraduated(true);
    student2.setLastname("Pinned");
    student2.setSurname("Jun");
    student2.setName("Ern");
    student2.setNumber_of_record_book(2142);
    student2.setPhone_number("1420421922");
    student2.setRNTRC("12434833");
    student2.setSpeciality("programming engeneer");

    //1. Визначити контейнери послідовностей STL та застосувати їх 3 методи для зберігання набору об'єктів в пам'яті

    //1.1 vector - масив з довільним доступом, найчастіше застосовується тоді, коли треба послідовно додавати дані в кінець ланцюжка

    vector<Student> students;
    students.push_back(student);
    students.push_back(same_student);
    students.push_back(student1);
    students.push_back(student2);


    cout << "Vector of students: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student name: " << students[i].getName() << endl;
    }
    cout << endl;


    //2. Для забезпечення засобів послідовного доступу до вмісту контейнерів визначити ітератори:
    //2.1 вхідні (input);
    // Вхідний ітератор
    auto inputIteratorVector = students.begin();

    //2.2 вихідні (output);
    // Вихідний ітератор
    auto outputIteratorVector = students.end();


    cout << "Vector of students with iterator: " << endl;
    for (auto it = inputIteratorVector; it != outputIteratorVector; ++it) {
        cout << "Student name: " << it->getName() << endl;
    }
    cout << endl;


    //2.5 довільного доступу (random access)
    auto randomAccessIterator = students.begin() + 2;

    cout << "Random access iterator: " << endl;
    
    // Check if the iterator is within bounds
    if (randomAccessIterator != students.end()) {
        std::cout << "Element at index 2: " << randomAccessIterator->getName() << std::endl;
    }
    else {
        std::cout << "Index 2 is out of bounds." << std::endl;
    }
    cout << endl;


    cout << "Vector of students before we used for_each algoritm to make all courses +1: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student address: " << students[i].getCourse() << endl;
    }

    //Застосувати 2 алгоритми для оперування даними.
    for_each(
        students.begin(), students.end(),
        [](Student& element) {
            element.setCourse(element.getCourse() + 1);
        }
    );

    cout << "Vector of students after we used for_each algoritm to make all courses +1: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student address: " << students[i].getCourse() << endl;
    }

    cout << endl;

    cout << "Vector of students before we used transform algoritm to add _hi to all address: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student address: " << students[i].getAddress() << endl;
    }

    //Застосувати 2 алгоритми для оперування даними.
    transform(
        students.begin(), students.end(), students.begin(),
        [](const Student& element) {
            Student result = Student();
            string new_spec = element.address + "_hi";
            result.setAddress(new_spec);
            return result;
        }
    );

    cout << "Vector of students after we used transform algoritm to add _hi to all address: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student address: " << students[i].getAddress() << endl;
    }
    cout << endl;
    


    //1.2 list - схожий на вектор, але ефективний при додаванні і видаленні даних в будь-яке місце ланцюжка;
    list<Student> studentsList;
    studentsList.push_back(student);
    studentsList.push_back(same_student);
    studentsList.push_back(student1);
    studentsList.push_front(student2);


    cout << "List of students emails: " << endl;
    for (const auto& obj : studentsList) {
        cout << "Student email: " << obj.email << endl;
    }

    studentsList.pop_back();
    cout << endl;



    cout << "List of students emails with deleted last one: " << endl;
    for (const auto& obj : studentsList) {
        cout << "Student email: " << obj.email << endl;
    }
    cout << endl;


    //2.4 двонаправлені (bidirectional);

    auto bidirectionalIteratorList = studentsList.rbegin();

    cout << "Reversed list of students emails with bidirectional: " << endl;

    for (; bidirectionalIteratorList != studentsList.rend(); ++bidirectionalIteratorList) {
        std::cout << bidirectionalIteratorList->email << endl;
    }
    cout << endl;


    //1.3 deque - контейнер, зручний для вставки даних на початок або кінець;
    deque<Student> studentsDeque;
    studentsDeque.push_back(student);
    studentsDeque.push_front(same_student);
    studentsDeque.push_back(student1);
    studentsDeque.push_front(student2);


    cout << "Deque of students addresses: " << endl;
    for (const auto& obj : studentsDeque) {
        cout << "Student email: " << obj.address << endl;
    }
    studentsDeque.pop_back();
    cout << endl;


    cout << "Deque of students addresses with deleted last one: " << endl;
    for (const auto& obj : studentsDeque) {
        cout << "Student email: " << obj.address << endl;
    }
    cout << endl;



    //2.3 односпрямовані (forward);
    std::cout << "Elements in the deque using forward iterator: ";
    for (deque<Student>::iterator forwardIterator = studentsDeque.begin(); forwardIterator != studentsDeque.end(); ++forwardIterator) {
        cout << forwardIterator->address << endl;
    }
    cout << endl;


    //1.4 set - набір унікальних елементів, відсортованих в певному порядку;
    set<Student> studentsSet;
    studentsSet.insert(student);
    studentsSet.insert(same_student);
    studentsSet.insert(student1);
    studentsSet.insert(student2);


    cout << "Set of students phone_number: " << endl;
    for (const auto& obj : studentsSet) {
        cout << "Student phone_number: " << obj.phone_number << endl;
    }
    studentsSet.erase(student2);
    cout << endl;

    //delete
    cout << "Set of students phone_numbers with deleted student: " << endl;
    for (const auto& obj : studentsSet) {
        cout << "Student phone_number: " << obj.phone_number << endl;
    }
    cout << endl;

    //find
    cout << "Find student phone_number: " << studentsSet.find(student1)->phone_number << endl;
  

    //1.5 multiset - те ж, що і set, але може містити повторювані копії;
    multiset<Student> studentsMultiSet;
    studentsMultiSet.insert(student);
    studentsMultiSet.insert(same_student);
    studentsMultiSet.insert(student1);
    studentsMultiSet.insert(student2);

    cout << "MultiSet of students address: " << endl;
    for (const auto& obj : studentsMultiSet) {
        cout << "Student address: " << obj.address << endl;
    }
    cout << endl;

    //delete
    studentsMultiSet.erase(student2);

    cout << "MultiSet of students address with deleted student: " << endl;
    for (const auto& obj : studentsMultiSet) {
        cout << "Student address: " << obj.address << endl;
    }
    cout << endl;

    //find
    cout << "Find student phone_number: " << studentsMultiSet.find(student1)->phone_number << endl;


    //1.6 map - забезпечує доступ до значень за ключам;
    map<int, Student> studentMap;

    studentMap[0] = student;
    studentMap[1] = same_student;
    studentMap[2] = student1;
    studentMap[3] = student2;


    std::cout << "Map of students email:"<<endl;
    for (const auto& pair : studentMap) {
        std::cout << "(" << pair.first << ", " << pair.second.email << ") ";
    }
    cout << endl;

    //delete
    studentMap.erase(1);

    cout << "Map of students email with deleted student: " << endl;
    for (const auto& pair : studentMap) {
        std::cout << "(" << pair.first << ", " << pair.second.email << ") ";
    }
    cout << endl;

    //find
    auto iterNotFound = studentMap.find(2);

    // Check if the key was found
    if (iterNotFound != studentMap.end()) {
        std::cout << "Find 1 student email : " << iterNotFound->second.email << std::endl;
    }
    else {
        std::cout << "Student 1 not found." << std::endl;
    }

    //1.7 multimap - те ж, що і map, але допускає повторювані ключі;
    multimap<int, Student> studentMultiMap;

    studentMultiMap.insert(make_pair(0, student));
    studentMultiMap.insert(make_pair(1, same_student));
    studentMultiMap.insert(make_pair(2, student1));
    studentMultiMap.insert(make_pair(3, student2));


    std::cout << "MultiMap of students email:" << endl;
    for (const auto& pair : studentMultiMap) {
        std::cout << "(" << pair.first << ", " << pair.second.email << ") ";
    }
    cout << endl;

    //delete
    studentMultiMap.erase(1);

    cout << "MultiMap of students email with deleted student: " << endl;
    for (const auto& pair : studentMultiMap) {
        std::cout << "(" << pair.first << ", " << pair.second.email << ") ";
    }
    cout << endl;

    
    //find
    auto iterNotFoundMultiMap = studentMultiMap.find(2);

    // Check if the key was found
    if (iterNotFoundMultiMap != studentMultiMap.end()) {
        std::cout << "Find 1 student email : " << iterNotFoundMultiMap->second.email << std::endl;
    }
    else {
        std::cout << "Student 1 not found." << std::endl;
    }

    //1.8 stack - дані додаються в одному порядку, а виймаються у зворотному;
    stack<Student> studentStack;

    studentStack.push(student);
    studentStack.push(same_student);
    studentStack.push(student1);
    studentStack.push(student2);

    std::cout << "Stack of students email:" << endl;
    while (!studentStack.empty()) {
        std::cout << studentStack.top().email << " ";
        studentStack.pop(); 
    }

    //1.9 queue - дані додаються і виймаються в тому ж порядку;
    queue<Student> studentQueue;
    studentQueue.push(student);
    studentQueue.push(same_student);
    studentQueue.push(student1);
    studentQueue.push(student2);

    std::cout << "Front element: " << studentQueue.front().email << std::endl;

    std::cout << "Queue of students email:" << endl;
    while (!studentQueue.empty()) {
        std::cout << studentQueue.front().email << " ";
        studentQueue.pop(); // Remove the front element
    }
    std::cout << std::endl;

    //1.10 priority queue - те ж, що і queue, але може сортувати дані по пріоритету.

    priority_queue<Student> studentPriorityQueue;
    studentPriorityQueue.push(student);
    studentPriorityQueue.push(same_student);
    studentPriorityQueue.push(student1);
    studentPriorityQueue.push(student2);

    std::cout << "Top element: " << studentPriorityQueue.top().email << std::endl;

    std::cout << "Priority Queue of students email:" << endl;
    while (!studentPriorityQueue.empty()) {
        cout << studentPriorityQueue.top().email << " ";
        studentPriorityQueue.pop(); // Remove the front element
    }
    cout << endl;


}

