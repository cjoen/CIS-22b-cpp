//Christopher Owen Team H
//assignment 12.1 week 6

#include <string>
#include <iostream>
using namespace std;

  // Employee info class
class personalInfo
{
   private:
      string name;
      string address;
      int age;
      string phone;
   public:
      void setName(string);
      void setAddr(string);
      void setAge(int);
      void setPhone(string);
      string getName() const;
      string getAddr() const;
      int getAge() const;
      string getPhone() const;
      personalInfo();
};

//constructor function
personalInfo::personalInfo(){
  name = "";
  address = "";
  age = 0;
  phone = "";
}


// functions to set data for EmployeeInfo
void personalInfo::setName(string n)
{
   name = n;
}

void personalInfo::setAddr(string addr)
{
   address = addr;
}

void personalInfo::setAge(int a)
{
   age = a;
}

void personalInfo::setPhone(string p)
{
   phone = p;
}

string personalInfo::getName() const
{
   return name;
}

string personalInfo::getAddr() const
{
   return address;
}

int personalInfo::getAge() const
{
   return age;
}

string personalInfo::getPhone() const
{
   return phone;
}

void displayClass(personalInfo &i, string role){
  cout << "My" << role << "Information: " << endl;
  cout << "Name: " << i.getName() << endl;
  cout << "Address: " << i.getAddr() << endl;
  cout << "Age: " << i.getAge() << endl;
  cout << "Phone: " << i.getPhone() << endl;
  cout << endl;
}

void getClassInfo(personalInfo &i, string role){
  string tempName, tempAddr, tempPhone;
  int tempAge;
  cout << "This program will store your" << role  << "Information" << endl;
  cout << "Please enter your" << role << "Name: ";
  cin.ignore();
  getline(cin, tempName);

  cout << "Please enter your" << role << "Address: ";
  getline(cin, tempAddr);
  cout << "Please enter your" << role << "Age: ";
  cin >> tempAge;
  cout << "Please enter your" << role << "Phone number: ";
  cin >> tempPhone;
  cout << endl;

  i.setName(tempName);
  i.setAddr(tempAddr);
  i.setAge(tempAge);
  i.setPhone(tempPhone);

}

int main() {
   personalInfo my;
   personalInfo frend;
   personalInfo family;

   getClassInfo(my, " ");
   getClassInfo(frend, " Friends ");
   getClassInfo(family, " Family Members ");


   displayClass(my, " ");
   displayClass(frend, " Friends ");
   displayClass(family, " Family Members ");





  return 0;
}
