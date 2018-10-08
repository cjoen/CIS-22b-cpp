//Christopher Owen Team H
//assignment 12.1 week 6

#include <string>
#include <iostream>
using namespace std;

  // Employee info class
class EmployeeInfo
{
   private:
      string employeeName;
      double hourlyRate;
      double hoursWorked;
   public:
      void setName(string);
      void setRate(double);
      void setHours(double);
      string getName() const;
      double getRate() const;
      double getHours() const;
      double calculatePay() const;
      EmployeeInfo();
};

//constructor function
EmployeeInfo::EmployeeInfo(){
  employeeName = "";
  hourlyRate = 0.0;
  hoursWorked = 0.0;
}


// functions to set data for EmployeeInfo
void EmployeeInfo::setName(string n)
{
   employeeName = n;
}

void EmployeeInfo::setRate(double r)
{
   hourlyRate = r;
}

void EmployeeInfo::setHours(double h)
{
   hoursWorked = h;
}

// setting get functions for EmployeeInfo
string EmployeeInfo::getName() const
{
   return employeeName;
}

double EmployeeInfo::getRate() const
{
   return hourlyRate;
}

double EmployeeInfo::getHours() const
{
   return hoursWorked;
}

double EmployeeInfo::calculatePay() const
{
   return hourlyRate * hoursWorked;
}


int main() {
   EmployeeInfo worker;     // Define an instance of the Rectangle class
   string workerName;
   double hourRate;  // Local variable for width
   double hourWork; // Local variable for length

   //MAKE SURE TO ADD CHECK FOR NEGATIVE INPUT
   cout << "This program will calculate the pay for an Employee \n";
   cout << "What is the employee name? ";
   getline(cin, workerName);

   while(workerName != "stop"){

     cout << "What is the pay rate per hour? ";
     cin >> hourRate;

     while (hourRate < 0){
       cout << "Invalid hourly rate. ";
       cout << "Please enter positive numbers only: ";
       cin >> hourRate;
     }

     cout << "What are the number of hours worked? ";
     cin >> hourWork;

     while (hourWork < 0){
       cout << "Invalid amount of hours. ";
       cout << "Please enter positive numbers only: ";
       cin >> hourWork;
     }

     worker.setName(workerName);
     worker.setRate(hourRate);
     worker.setHours(hourWork);

     // Display the rectangle's data.
     cout << "Here is the employees pay" << endl;
     cout << "Name: " << worker.getName() << endl;
     cout << "Weekly pay: " << worker.calculatePay();
     cout << endl << endl;

     cout << "What is the employee name? (stop to exit):";
     cin >> workerName;

   }

  return 0;
}
