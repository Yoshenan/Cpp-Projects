#include <iostream>
#include <string>
using namespace std;

class Model {

public:
    Model* next;
    int year;
    double price;
    string model;


    Model(string m , int y , double p){
      model = m;
      year = y;
      price = p;
      next = nullptr;

    }


};


class Vehicle{
public:
    string brand;
    Model* head;



    Vehicle(string  b){
      brand = b;
      head = nullptr;

    }

    void createModel(string m , int y,double p){


     Model*  newModel = new Model(m , y, p);

     if(head == nullptr){
            head = newModel;
     } else{
         Model* temp = head;
         while(temp-> next != nullptr ){
            temp = temp-> next;
         }
         temp->next = newModel;
     }

    }

    void Display(){
        Model* temp = head;
        cout << "Vehicle Models:\n";
        while (temp != nullptr) {
            cout << " - " << temp->model
                 << " (" << temp->year
                 << ") RM" << temp->price << endl;
            temp = temp->next;
        }
    }

};















int main(){





  Vehicle v1("BMW");
  v1.createModel("5 Series",2017 , 450000);
  v1.createModel("6  Series",2017 , 400000);
  v1.createModel("7 Series",2017 , 750000);
  v1.createModel("5 Series",2017 , 300000);
  v1.Display();


  return 0;





}
