#include <iostream>
using namespace std;


class Booking {
    public:
    int id;
    string from;
    string to ;
    int guest_no;
 void set_booking(int id , string from , string to , int guest_no){
   this -> id = id ;
   this -> from = from;
   this -> to = to;
   this -> guest_no = guest_no;

 }
 void get_booking(){
  cout<<"Your Booking id :"<<id <<endl;
  cout<<"Date from:"<<from<<"to:"<<to<<endl;
  cout<<"Number of guests:"<<guest_no<<endl;


 }

};

class Room : public Booking
{
public:
    int id;
    string room_type;
 void set_room(int id , string room_type){
     this -> id = id;
     this -> room_type = room_type;
 }

 void get_room(){

    cout<<"Your room id:"<<id<<endl;
    cout<<"Your room type:"<<room_type<<endl;

 }
};

class Guest : public Booking{
 public:
     string name;
     int age;
     string surname;
void set_guest(string name , string surname , int age){
  this->name = name;
  this ->surname = surname;
  this ->age = age;
}

void get_guest(){
   cout<<"Guest name:"<<name<<endl;
   cout<<"Guest surname:"<<surname<<endl;
   cout<<"Guest Age:"<<age<<endl;
}

};

class Payment : public Booking{
 public:
     string cardNumber;
     int amount;

void set_payment(string cardNumber , int amount){
  this->cardNumber = cardNumber;
  this ->amount = amount;

}

void get_payment(){
   cout<<"Amount:"<<amount<<endl;
   cout<<"Card Number:"<<cardNumber<<endl;
}

};

int main(){
    Guest guest;
    Room room;
    room.set_booking(247 , "1-9-2025" , "2-9-2025",4);
    room.set_room(245 , "Family Deluxe");
    room.get_booking();
    room.get_room();




}

