//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool openFile(fstream &file, string name) {  //check if file is available
   file.open(name, ios::in);
   if (file.fail())
      return false;
   else
      return true;
}

void parseLine (string *line, string name) {  //point for line
  line.replace(line.find("#N#"), sizeof(name)-1, name);
  return;
}


int main() {
  string inFilename, outFilename, Fname, Lname; // To hold the file name
  string line; // To hold a character
  fstream inFile; // input File stream object
  ofstream outFile; // output File stream object

  cout << "Please enter a file name to copy from: ";
  cin >> inFilename;  //enter input file neme
  cout << "Please enter a file name to copy to: ";
  cin >> outFilename; // enter output file name

  cout << "Please enter your first name:";
  cin >> Fname;
  cout << "Please enter your last name:";
  cin >> Lname;
  fullName = Fname + " " + Lname;

  if (openFileIn(inFile, inFilename)){
    while (inFile){
      getline(inFile, line);
      if (line.find("#N#")){
        parseLine(&line, fullName);
        outFile << line << endl;
      } else {
        outFile << line << endl;
      }
    }
    //function to parse line and add name if "#N#" exists
    //function to output file
    return 0;
  } else {
      cout << inFilename << " could not be opened.\n";
      return 0;
  }

}
