//Christopher Owen Team H
//assignment 10.2 week 3

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

int main() {
  string numbers;
  int strSum, strHi, strLow;
  strHi = 0;
  strLow = 9;
  //prompt to user
  cout << "Enter a series of digits with no spaces between them.";
  //store string
  getline(cin, numbers);

  for (int i = 0; i < numbers.length(); i++) {
    int tempDigit = atoi(numbers[i]);
    if (strHi < tempDigit ){
      strHi = tempDigit;
    }
    if (strLow > tempDigit){
      strLow = tempDigit;
    }
    strSum = tempDigit + strSum;
  }

  cout << "Largest number: " << strHi << endl;
  cout << "Smallest number: " << strLow << endl;
  cout << "Total sum: " << strSum << endl;

  //find sum of digits

  //find largers digit

  //find smallest digit


  return 0;
}
