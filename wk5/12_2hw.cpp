//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector <int> allNums; // To hold a character
  string testing;
  int test, test2;
  fstream inFile1; // input File stream object
  fstream inFile2;
  fstream outFile; // output File stream object

  inFile1.open("/Users/cj/dev/school/int-cpp/wk5/input1.txt");  //open input file
  inFile2.open("/Users/cj/dev/school/int-cpp/wk5/input2.txt");  //open input file
  outFile.open("/Users/cj/dev/school/int-cpp/wk5/output.txt"); //open output file

getline(inFile1, testing);

  if(inFile1){ //check to see if output and input file exist
    getline(inFile1, testing);
    cout << "Contents in file 1 are: " << endl;
    cout << testing << endl;
    test = stoi(testing);
    allNums.push_back(test);
    while (inFile1){
      getline(inFile1, testing);
      cout << testing << endl;
      test = stoi(testing);
      allNums.push_back(test);

    }

    inFile1.close();
  } else {
      cout << "File 1 could not be opened.\n";
      return 0;
  }

  if(inFile2){ //check to see if output and input file exist
    getline(inFile2, testing);
    cout << "Contents in file 2 are: " << endl;
    cout << testing << endl;
    test2 = stoi(testing);
    allNums.push_back(test2);

    while (inFile2){
      getline(inFile2, testing);
      cout << testing << endl;
      test2 = stoi(testing);
      allNums.push_back(test2);

    }
    inFile2.close();
  } else {
      cout << "File 2 could not be opened.\n";
      return 0;
  }

  //sort through vector

  //output vector to file

  return 0;
}
