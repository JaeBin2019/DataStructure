#include <iostream>
using namespace std;
#define N 3

// https://codingcoding.tistory.com/736     Static 함수 및 변수

class Employee
{
    int num;
    string ename;
    float salary;
    string dept;
    static int count; // Whenever an Object is created   count++

public:
    Employee();
    Employee(int num);
    Employee(int num, string ename, float salary, string dept) : num(num), ename(ename), salary(salary), dept(dept)
    {
        count++;
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

    int getSalary() { return this->salary; }
    friend ostream &operator<<(ostream &stream, Employee &e);
};

// 정적 멤버 변수(static 변수)는 생성자에서 초기화되지 않으며,
// 객체 초기화에 종속되지 않아 명시적으로 클래스 외부에서 값을 할당합니다.
// 초기화되지 않으면 링커에서 오류가 발생합니다.
int Employee::count = 0;

Employee::Employee()
{
    count++;
}

Employee::Employee(int num)
{
    count++;
    this->num = num;
}

ostream &operator<<(ostream &stream, Employee &e)
{
    stream << "num : " << e.num << endl;
    stream << "ename : " << e.ename << endl;
    stream << "salary : " << e.salary << endl;
    stream << "dept : " << e.dept << endl;

    return stream;
}

class EmpTable
{
    int top;
    Employee data[N];

public:
    void initializeEmployee();
    void showEmployee();
};

void EmpTable::initializeEmployee()
{
    int num;
    string ename;
    float salary;
    string dept;
    for (int i = 0; i < N; i++)
    {
        cin >> num >> ename >> salary >> dept;
        data[i] = Employee(num, ename, salary, dept);
    }
    cout << endl;
}
void EmpTable::showEmployee()
{
    for (int i = 0; i < N; i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    int n = N;
    EmpTable empt;
    empt.initializeEmployee();
    empt.showEmployee();
    system("pause");
}
