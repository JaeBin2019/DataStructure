#include <iostream>
using namespace std;

// https://codingcoding.tistory.com/736     Static 함수 및 변수

class Employee
{
    int num;
    string ename;
    float salary;
    string dept;
    static int count; // Whenever an Object is created   count++

public:
    Employee()
    {
        count++;
    }
    Employee(int num)
    {
        count++;
        this->num = num;
    }
    Employee(const Employee &e)
    {
        count++;
        this->num = e.num;
        this->ename = e.ename;
        this->salary = e.salary;
        this->dept = e.dept;
    }
    // ~Employee();
    Employee &operator=(const Employee &e)
    {
        this->num = e.num;
        this->ename = e.ename;
        this->salary = e.salary;
        this->dept = e.dept;
        return *this;
    }
    int operator++();

    // Show count value
    static int Show()
    {
        cout << count << endl;
    }
    friend ostream &operator<<(ostream &stream, Employee &e);
};

// 정적 멤버 변수(static 변수)는 생성자에서 초기화되지 않으며,
// 객체 초기화에 종속되지 않아 명시적으로 클래스 외부에서 값을 할당합니다.
// 초기화되지 않으면 링커에서 오류가 발생합니다.
int Employee::count = 0;

ostream &operator<<(ostream &stream, Employee &e)
{
    stream << "num : " << e.num << endl;
    stream << "ename : " << e.ename << endl;
    stream << "salary : " << e.salary << endl;
    stream << "dept : " << e.dept << endl;

    return stream;
}

int main()
{
    Employee sd1;
    Employee sd2(10);
    Employee sd3(sd2);
    Employee::Show();
    sd1.Show();
    Employee sd4 = sd2;
    Employee::Show();
    sd3 = sd2;
    cout << endl;
    cout << sd4;
    Employee::Show();
    system("pause");
}
