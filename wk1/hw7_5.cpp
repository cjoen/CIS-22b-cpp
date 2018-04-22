//Christopher Owen Team H
//assignment 7.5

#include <iostream>
#include <vector>
using namespace std;

int main() {
  //setting global variables
  int NUM_INPUT;
  vector <int> nums;
  int index;

  //asking for the amount of input numbers
  cout << "How many numbers would you like to have? ";
  cin >> NUM_INPUT;

while ( nums.size() < NUM_INPUT) {
      int num_in;
      cout << "Enter a number between 10 and 100: ";
      cin >> num_in ;
        if (10 < num_in && num_in < 100 && nums.size() < 1){
          nums.push_back(num_in);
        } else {
          cout << "Invalid.  " << endl;
        }
      }

    cout << "Here are the numbers entered:" << '\n';
    for (index = 0; index < NUM_INPUT; index++) {

      cout << nums[index] << '\n';

    }


  return 0;
}
