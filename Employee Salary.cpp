#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Employee{
public:

    virtual double CalculateSalary() const = 0 ;
    virtual void displayInfo() const = 0;
    virtual ~Employee() {};

    Employee(string n , int i , double b) : name(n) , id(i) , baseSalary(b) {}


protected:
    string name;
    int id;
    double baseSalary;


};

class Manager : public Employee{
protected:
    int teamSize;
    double bonus;

public:

    Manager(string n , int i , double b , int t , double bon ) : Employee(n,i,b) , teamSize(t), bonus(bon) {}

    double CalculateSalary() const override {
     return baseSalary + bonus + (teamSize * 100);
    }

    void displayInfo()const  override {
     cout <<"Name: "<<name <<endl;
     cout<<"ID : "<<id<<endl;
     cout<<"Base Salary: " <<baseSalary<<endl;
     cout<<"Team Size : "<<teamSize<<endl;
     cout<<"Bonus : "<<bonus<<endl;
     cout<<"Total Salary : "<<CalculateSalary()<<endl;



    }




};

class Engineer : public Employee{
    protected:
    int overtimeHours;
    double overtimeRate;

public:

    Engineer(string n , int i , double b , int h , double r ) : Employee(n,i,b) , overtimeHours(h) , overtimeRate(r) {}

    double CalculateSalary() const override{
     return baseSalary + (overtimeHours * overtimeRate);
    }
  void displayInfo() const  override{
     cout <<"Name: "<<name <<endl;
     cout<<"ID : "<<id<<endl;
     cout<<"Base Salary: " <<baseSalary<<endl;
     cout<<"Overtime Hours : "<<overtimeHours<<endl;
     cout<<"Overtime Rate: "<<overtimeRate<<endl;
     cout<<"Total Salary : "<<CalculateSalary()<<endl;



    }


};

class Intern : public Employee{

    protected:
    double stipend;

public:

    Intern(string n , int i , double b ,  double s ) : Employee(n,i,b) , stipend(s) {}

    double CalculateSalary() const override{
     return stipend;
    }

    void displayInfo() const  override{
     cout <<"Name: "<<name <<endl;
     cout<<"ID : "<<id<<endl;
     cout<<"Base Salary: " <<baseSalary<<endl;
     cout<<"stipend: "<<stipend<<endl;
     cout<<"Total Salary : "<<CalculateSalary()<<endl;



    }






};




int main(){
    vector<Employee*> employees;

    employees.push_back(new Manager("Alice", 101, 5000, 5, 1200));
    employees.push_back(new Engineer("Bob", 102, 4000, 10,150));
    employees.push_back(new Intern("Charlie", 103, 1500, 40));

    cout << "=== Employee Salary Details ===" << endl;

    // Loop through and display info
    for (auto emp : employees) {
        emp->displayInfo();
        cout << "Total Salary: $" << emp->CalculateSalary() << endl;
        cout << "--------------------------------------" << endl;
    }

    // Cleanup memory
    for (auto emp : employees)
        delete emp;

    return 0;
}
