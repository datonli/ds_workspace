#include <iostream>
#include <string>

using namespace std;

class Student 
{
    public:
        Student(int,string,float);
        virtual void display();
    protected:
        int num;
        string name;
        float score;

};

Student::Student(int n,string name,float s)
{
    num = n;
    this->name = name;
    score = s;
}

void Student::display()
{
    cout << "num : " << num << "name : " << name << "score : " << score << endl;
}

class Graduate:public Student
{
    public : 
        Graduate(int,string,float,float);
        void display();
    private:
        float pay;
};

void Graduate::display()
{
    cout << "num : " << num << "name : " << name << "score : " << score << "pay = " << pay << endl;
}

Graduate::Graduate(int n , string name, float s, float p ) :Student(n,name,s),pay(p){}

int main()
{
    Student stud1(1001,"Li",87.5);
    Graduate grad1(2001,"Wang",98.7,343);
    Student *pt = &stud1;
    pt->display();
    pt = &grad1;
    pt->display();
    return 0;
}
