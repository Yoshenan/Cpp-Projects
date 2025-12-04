#include<iostream>
#include <windows.h>
#include<fstream>
#include<string>
using namespace std;


class Student{
    public:
  string Name;
  string ID;
  int age;

  void input(){
    cout<<"Enter Name: "<<endl;
    cin>>Name;
    cout<<"Enter ID: "<<endl;
    cin>>ID;
    cout<<"Enter age: "<<endl;
    cin>>age;
    }

    void display(){

    cout<<Name<<" /nName:"<<ID<<"ID:"<<"age:"<<age<<endl;

    }
};


void add_student(){

   Student s;
   s.input();
   ofstream file("student.txt" ,ios::app);
   if (file.is_open()){
    file<<s.ID <<","<<s.Name<<","<<s.age<<","<<endl;
    file.close();
    cout<<"Student Added"<<endl;}

    else{
        cout<<"Cant open file"<<endl;
    }

};

void open_student(){
  ifstream file("student.txt");
  string line;
  if (file.is_open()){

        cout<<"Student record found"<<endl;
        while (getline(file , line)){
            cout<<line<<endl;}
        file.close();
  }
  else{
        cout<<"No records"<<endl;

  }
}

void search_student(){
   string id;
   cout<<"Enter search id"<<endl;
   cin>>id;
   bool found = false;

    ifstream file("student.txt");
    string line;

    if (file.is_open()){
         while(getline(file , line)){
        if (line.find(id) == 0 ) {

            cout<<"Record found"<<line<<endl;
            found =true;
            break;
        }

    }
    file.close();
    if (!found){
            cout<<"not found"<<endl;

    } else{
      cout<<"no records found"<<endl;

    }


    }




}




int main()
{
    char choice;
    cout<<"---------------------------"<<endl;
    cout<<"1- Add Student Record"      <<endl;
    cout<<"2- Open Student Record"     <<endl;
    cout<<"3- Search Student Account"  <<endl;
    cout<<"4-Exit"                     <<endl;
    cout<<"---------------------------"<<endl;
    cin>>choice;


    switch(choice){
    case '1': add_student();
        break;
    case '2': open_student();
        break;
    case '3': search_student();
        break;
    case '4':
        break;
    default:
        cout<<"You entered invalid"<<endl;

    }


}
