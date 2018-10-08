//Christopher Owen Team H
//assignment 8.1

#include <iostream>
#include <vector>
using namespace std;

int linear_search( int pick ){
  int comp_count = 0;
  int pool [20] = {101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600};
  int index;
  for (index = 0; index < 20; index++) {
    if (pick == pool[index]) {
      cout << "The linear seach made " << comp_count << " comparisons." << endl;
      return 0;
    } else {
      comp_count = comp_count+1;
    }
  }
    return comp_count;
}

int binary_search (int pick) {
  int array [20] = {101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600};
  int first = 0,             // First array element
      last = 20,       // Last array element
      middle,                // Mid point of search
      position = -1;
  int comp_count = 0;
  int value = pick;        // Position of search value
  bool found = false;        // Flag

  while (!found && first <= last)
  {
     middle = (first + last) / 2;     // Calculate mid point
     if (array[middle] == value)      // If value is found at mid
     {
        found = true;
        position = middle;
     }
     else if (array[middle] > value)  // If value is in lower half
        last = middle - 1;
     else
        first = middle + 1;           // If value is in upper half
    comp_count = comp_count + 1;
  }

   cout << "The binary seach made " << comp_count << " comparisons. " << endl;
   return 0;
 }


int main() {
  int index, picked_num, lin_search;
  int pool [20] = {101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600};

  cout << "Choose a number to be searched from the following: " << endl;
  for (index = 0; index < 20; index++) {
    cout << pool[index] << ", ";
  }
  cout << endl;
  cin >> picked_num;
  cout << "searching for " << picked_num << endl;

  linear_search(picked_num);
  binary_search (picked_num);

  return 0;
}
