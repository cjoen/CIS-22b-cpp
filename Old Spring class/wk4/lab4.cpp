//Christopher Owen Team H
//assignment Lab 4

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct student {
  string name;
  int number;
  int * tests;
  int avgScore;
  char grade;
};

void procData(student *s, int testCount) { // get data for the structure
  //request student information
  cout << "Student name: ";
  cin >> s->name;
  cout << "ID Number: ";
  cin >> s->number;

  //test calculations
  int testSum = 0;
  for (int t = 0; t < testCount; t++) {
    int tempScore;
    cout << "Enter test " << t+1 << " score :";
    cin >> tempScore;

    while( 0 > tempScore || tempScore > 101) {
      cout << "Please enter a non negative number between 1 and 100 :";
      cin >> tempScore;
    }

    s->tests[t] = tempScore;
    testSum+= s->tests[t];
  }
  s->avgScore = testSum/testCount;

  if (100 >= s->avgScore && s->avgScore >= 91) {
    s->grade = 'A';
  } else if (90 >= s->avgScore && s->avgScore >= 81){
    s->grade = 'B';
  } else if (80 >= s->avgScore && s->avgScore >= 71){
    s->grade = 'C';
  } else if (70 >= s->avgScore && s->avgScore >= 61){
    s->grade = 'D';
  } else if (60 >= s->avgScore){
    s->grade = 'F';
  }
}

void printStuc(student *s, int testCount) {
  cout << "Student name: " << s->name << endl;
  cout << "ID Number: " << s->number << endl;
  cout << "Avg. Test Score: " << s->avgScore << endl;
  cout << "Grade: " << s->grade << endl;

}

int main() {
  int SIZE, testCount;
  cout << "How many students?";
  cin >> SIZE;
  cout << "How many tests?";
  cin >> testCount;
  int scores[testCount];
  student classGrades[SIZE];

  //loop through array and get data
  for (int i = 0; i < SIZE; i++) {
    classGrades[i].tests = &scores[testCount];
    procData(&classGrades[i], testCount);
  }

  for (int o = 0; o < SIZE; o++) {
    printStuc(&classGrades[o], testCount);
  }

  return 0;
}
