//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
using namespace std;

double getAverage(double *arr, int size) {
   int i, sum = 0;
   double avg;

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}

void arrangeArr(double *arr, int size)
{
   bool swap;
   double temp;

   do
   {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (arr[count] > arr[count + 1])
         {
            temp = arr[count];
            arr[count] = arr[count + 1];
            arr[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

int main() {
  int scoreLength, scoreAvg, *arrLen;
  double average;
  arrLen = &scoreLength;
  cout << "How many test scores will you enter?";
  cin >> *arrLen;

  double scoreArr [*arrLen], * arrPtr;
  arrPtr = scoreArr;

  for (int count = 0; count < scoreLength; count++) {
    double temp;
    cout << "Enter test score " << count+1 << ": ";
    cin >> temp;
    if (temp >= 0){
      *(arrPtr + count) = temp;
    } else {
      cout << "Negative scores are not allowed." << endl;
      cout << "Please enter another score for this test: ";
      cin >> *(arrPtr + count);
    }
  }

  average = getAverage( arrPtr, scoreLength);
  arrangeArr( arrPtr, scoreLength);

  cout << "The test scores in ascending order, and their average, are:\n";
  cout << "Score \n-------- \n";
  for (int count = 0; count < scoreLength; count++) {
    cout << *(arrPtr + count)<< " ";
    cout << endl;
  }
  cout << "The average score is :" << average << endl;

  return 0;
}
