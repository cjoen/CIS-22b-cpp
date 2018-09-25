//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string inFilename, outFilename, ifn, ofn; // To hold the file name
  char ch; // To hold a character
  ifstream inFile; // input File stream object
  ofstream outFile; // output File stream object

  cout << "Please enter a file name to copy from: ";
  cin >> inFilename;  //enter input file neme
  ifn = "/Users/cj/dev/school/int-cpp/wk5/" + inFilename;  //delete before turning in.

  cout << "Please enter a file name to copy to: ";
  cin >> outFilename; // enter output file name
  ofn = "/Users/cj/dev/school/int-cpp/wk5/" + outFilename; //delete before turning in.

  inFile.open(ifn);  //open input file
  outFile.open(ofn); //open output file
  if(inFile){ //check to see if output and input file exist
    inFile.get(ch);

    while (inFile){
      outFile.put(ch);
      cout << ch;
      inFile.get(ch);
    }

    cout << "Sucessfully copied!\n";
    inFile.close();  //close input file
    outFile.close(); //close output file
  } else {
      cout << inFilename << " could not be opened.\n";
      return 0;
  }

}
