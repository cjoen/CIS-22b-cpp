//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string inFilename, outFilename, Fname, Lname, fullName; // To hold the file name
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

  inFile.open(inFilename);  //open input file
  outFile.open(outFilename); //open output file
  if(inFile){ //check to see if output and input file exist
    while (inFile){
      getline(inFile, line);
      if (line.find("#N#") != std::string::npos){
        string newLine;
        newLine = line.replace(line.find("#N#"), Fname.length(), Fname);
        outFile << newLine << endl;
      } else {
        outFile << line << endl;
      }
    }

    inFile.close();  //close input file
    outFile.close(); //close output file
    return 0;
  } else {
      cout << inFilename << " could not be opened.\n";
      return 0;
  }

}
