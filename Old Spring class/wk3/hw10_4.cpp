//Christopher Owen Team H
//assignment 10.4 week 3

#include <string>
#include <iostream>
using namespace std;

int main() {
  string dateStr;

  cout << "Enter a date in the form mm/dd/yyyy: ";
  getline(cin, dateStr);

  for (int i = 0; i < dateStr.length(); i++) {
    if (dateStr[i] == "/"){

    } else {
      continue;
    }
  }


  return 0;
}
