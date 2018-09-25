//Christopher Owen Team H
//assignment Lab 3

#include <iostream>
#include <string>
using namespace std;

void reverse(string revStr){
  string tempStr;
  tempStr = "";
  for (int i = 0; i < revStr.length(); i++) {
    tempStr = revStr[i] + tempStr;
  }
  cout << "The string after reversing: " << tempStr <<endl;

}

int main() {
  string stringOne, stringTwo, mainStr, revStr;
  cout << "Enter First string: ";

  getline(cin, stringOne);  //add conditional

  cout << "Enter a Second string: ";

  getline(cin, stringTwo);  //add contidional statement.

  mainStr = stringOne + stringTwo;

  cout << "The String before reversing: " << mainStr << endl;

  reverse(mainStr);


  //have input for a a string to reverse here.



  return 0;
}
