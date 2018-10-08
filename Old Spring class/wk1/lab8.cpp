//Christopher Owen Team H
//assignment Lab 1

#include <iostream>
#include <vector>
using namespace std;



int main() {
  int Temp[2][12];
  int index;
  int highs[12] = {89, 95, 76, 66, 68, 87, 85, 83, 76, 65, 63, 60};
  int lows[12] = {78, 80, 70, 60, 60, 77, 75, 70, 68, 62, 60, 55};
  for ( index = 0; index < 12; index++) {
    Temp[0][index] = highs[index];
    Temp[1][index] = lows[index];
    cout << Temp[0][index];
  }


  return 0;
}
