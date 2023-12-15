#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//5. Створити шаблон класу з не менше ніж п’ятьома шаблонними даними та методами. Продемонструвати його застосування.
template <typename T, typename U, typename V, typename W>
class MyTemplate {
private:
    T data1;
    U data2;
    V data3;
    W data4;
public:
    MyTemplate(T t, U u, V v, W w)
        : data1(t), data2(u), data3(v), data4(w) {}

    void display() const {
        cout << "MyTemplate values: " << data1 << ", " << data2 << ", " << data3 << ", " << endl;
        data4.display();
    }

};
