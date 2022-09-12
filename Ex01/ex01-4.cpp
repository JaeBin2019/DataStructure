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

void initializeEmployee(Employee *emp[], int n)
{
    int num;
    string ename;
    float salary;
    string dept;
    for (int i = 0; i < n; i++)
    {
        cin >> num >> ename >> salary >> dept;
        emp[i] = new Employee(num, ename, salary, dept);
    }
    cout << endl;
}
void showEmployee(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *emp[i] << endl;
    }
}

void showSalaryAverage(Employee *emp[], int n)
{
    float min, max, sum = 0;
    min = emp[0]->getSalary();
    max = emp[0]->getSalary();
    for (int i = 0; i < n; i++)
    {
        float salary = emp[i]->getSalary();
        if (min > salary)
            min = salary;

        if (max < salary)
            max = salary;
        sum += salary;
    }
    float avg = sum / n;
    cout << "min : " << min << endl;
    cout << "max : " << max << endl;
    cout << "avg : " << avg << endl;
}

int main()
{
    int n = N;
    Employee *emp[N];
    initializeEmployee(emp, n);
    showEmployee(emp, n);
    showSalaryAverage(emp, n);
    system("pause");
}
