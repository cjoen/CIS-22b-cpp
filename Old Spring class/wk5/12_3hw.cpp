//Christopher Owen Team H
//assignment 12.3 Team H week 5

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getFlength(fstream &file, string fileName){
  int count = 0;
  string line;
  file.open(fileName);
  if (file){
    getline(file, line);
    while (file){
      getline(file, line);
      count+=1;
    }
  } else {
    cout << "error opening the file";
  }
  file.close();
  return count;
}



int main() {
  string inFilename, ifn, line; // To hold the file name
  int lineCount;
  fstream inFile; // input File stream object

  cout << "Please enter a file name to copy from: ";
  cin >> inFilename;  //enter input file neme
  ifn = inFilename;  //delete before turning in.

  lineCount = getFlength(inFile, ifn);

  inFile.open(ifn);
  if (inFile){
    if (lineCount <= 10){
      cout << "The entire file is displayed" << endl;
    }
    for (int i = lineCount; i > 0; --i) {
      if(i <= 10) {
        getline(inFile, line);
        cout << line << endl;
      } else {
        getline(inFile, line);
        continue;
      }
    }
  } else {
    cout << "Error reading the file" << endl;
  }

  return 0;
}
