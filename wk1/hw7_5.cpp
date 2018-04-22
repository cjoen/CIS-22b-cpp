//Christopher Owen Team H
//assignment 7.5

#include <iostream>
#include <vector>
using namespace std;

int main() {
  //setting global variables
  int NUM_INPUT;
  vector <int> nums(NUM_INPUT);
  int index;

  //asking for the amount of input numbers
  cout << "How many numbers would you like to have? ";
  cin >> NUM_INPUT;

  // looping through the requested amount of times.
  for (index = 0; index < NUM_INPUT; index++) {
    int num_in;
    cout << "enter a number between 10 and 100: ";
    cin >> num_in ;

    //conditionals to make sure numbers are within range
    if (num_in>=10 && num_in<=100) {
      nums.push_back(num_in);
    } else {
      //resulting error message and backcount.
      cout << "Invalid. ";
      index = index-1 ;
    }

  }

// outputting the numbers within the range.
  cout << "Here are the numbers entered:" << '\n';
  for (index = 0; index < NUM_INPUT; index++) {

    cout << nums[index] << '\n';

  }


  return 0;
}
