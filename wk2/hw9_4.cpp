//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <string>
using namespace std;

double getAverage(double array[][1], int size) {
   int i, sum = 0;
   double avg;

   for (i = 0; i < size; ++i) {
      sum += array[i][1];
   }
   avg = double(sum) / size;

   return avg;
}

void arrangeArr(double array[][1], int size)
{
   bool swap;
   double temp;

   do
   {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (array[count][1] > array[count + 1][1])
         {
            temp = array[count][1];
            array[count][1] = array[count + 1][1];
            array[count + 1][1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

int main() {
  double scoreLength, scoreAvg, *arrLen;
  double average;
  arrLen = &scoreLength;
  cout << "How many test scores will you enter?";
  cin >> *arrLen;

  double scoreArr[*arrLen][2];
  string students[*arrLen];


  for (int count = 0; count < scoreLength; count++) {
    int temp;
    cout << "Enter Student " << count+1 << "\'s last name: ";
    cin >> *(students + count);
    cout << "Enter the students test score: ";
    cin >> temp;
    if (temp >= 0){
      scoreArr[count][1] = temp;
      scoreArr [count][0] = count;
    } else {
      cout << "Negative scores are not allowed." << endl;
      cout << "Please enter another score for this test: ";
      cin >> scoreArr[count][1];
      scoreArr [count][0] = count;
    }
  }

//  average = getAverage(scoreArr, scoreLength);
//  arrangeArr(scoreArr, scoreLength);

  cout << "The test scores in ascending order, and their average, are:\n";
  cout << "Score \n-------- \n";
  for (int count = 0; count < scoreLength; count++) {
    cout << scoreArr[count][1]<< " ";
    cout << endl;
  }
  cout << "The average score is :" << average << endl;

  return 0;
}
