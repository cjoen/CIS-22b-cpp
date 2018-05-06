//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
using namespace std;

bool passwdChk(string passwd){
  int lower, numb;
  lower=0;
  numb=0;
  for (int i = 0; i < passwd.length(); i++) {
    if(islower(passwd[i])){
        lower++;
    } else if(isdigit(passwd[i])) {
      numb++;
    } else {
      return false;
    }
  }
  if (numb == 6 && lower == 4){
    return true;
  }
}

int main() {
  // input section of code.
  string passwd;
  bool passCheck;
  passCheck = false;
  cout << "Enter a password consisting of exactly 4 lower case letters and 6 digits: ";
  getline(cin, passwd);
  while(passCheck == false){   //while loop checks the existence of input and validates it.
    if( 10 > passwd.length() > 10) {
      cout << "Invalid password. ";
      cout << "Please enter a password with exactly 4 lower case letters and 6 digits" << endl;
      cout << "For example, 1234abcd56 is valid. Please enter again: ";
      getline(cin, passwd);
    } else if (passwdChk(passwd) == false) {
      cout << "Invalid password. ";
      cout << "Please enter a password with exactly 4 lower case letters and 6 digits" << endl;
      cout << "For example, 1234abcd56 is valid. Please enter again: ";
      getline(cin, passwd);
    } else {
      passCheck = true;
    }
  }

  cout << "The number of lower case letters in the password is 4" << endl;
  cout <<"The number of digits in the password is 6" << endl;


  return 0;

}
