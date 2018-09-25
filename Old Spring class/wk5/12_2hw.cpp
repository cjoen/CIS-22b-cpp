//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string testing1, testing2;
  int test, test2;
  fstream inFile1; // input File stream object
  fstream inFile2;
  fstream outFile; // output File stream object

  inFile1.open("/Users/cj/dev/school/int-cpp/wk5/input1.txt");  //open input file
  inFile2.open("/Users/cj/dev/school/int-cpp/wk5/input2.txt");  //open input file
  outFile.open("/Users/cj/dev/school/int-cpp/wk5/output.txt"); //open output file
  getline(inFile1, testing1);
  getline(inFile2, testing2);
  test = stoi(testing1);
  test2 = stoi(testing2);


  while (inFile1 || inFile2){

    if (test > test2){
      cout << test2 << endl;
      getline(inFile2, testing2);
    } else if (test2 > test){
      cout << test << endl;
      getline(inFile1, testing1);
    } else if (test2 == test){
      cout << test2 << endl;
      getline(inFile2, testing2);
    } else if(test){
      cout << test << endl;
      getline(inFile1, testing1);
    } else if(test2){
      cout << test2 << endl;
      getline(inFile2, testing2);
    } else {
      cout << "completed" << endl;

    }
  }


  //sort through vector

  //output vector to file

  return 0;
}
