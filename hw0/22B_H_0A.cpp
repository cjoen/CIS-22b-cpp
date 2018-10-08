/***
 22B - PROGRAM 0A:
 ARRAYS and FUNCTIONS: SEARCHING using the Linear Search function
                          // also known as Sequential Search

 Find and fix errors. Run the program once and save the output as a comment at the end
 of the source file.


 Changed by: Christopher Owen
 IDE: Clion

*/
#include <iostream>

using namespace std;

int  search_Ary(int array[], int size, int target);

int main()
{
    int list[100] = {40, 30, 50, 13, 35, 48, 14, 31, 18, 33};
    int length = 10;

    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    // SEARCH 20 times
    srand(20);
    for (int i = 0; i < 2 * length; i++)
    {
        // generate a random target within the range 1 to 100
        int target = rand() % 100 + 1;
        int location = search_Ary(list, length, target);
        if (location != -1)
            cout << target << " FOUND at location: " << location << endl;
        else
            cout << target << " NOT found!" << endl;
    }

    return 0;
}

/***************************************************
 This function searches a list of integers for a given target
 It returns -1 if not found.
 It returns the index of the first element in the array that is equal to
 the target value.
 */
int search_Ary(int array[], int size, int target)
{
    int index = 0;   // Used as a subscript to search array
    int pos   = -1;  // To record position of search value: -1 means not found

    while (index < size && pos == -1)
    {
        if (array[index] == target) // If the value is found
        {
            pos = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return pos; // Return the position, or -1
}

/************** OUTPUT

/Users/cj/dev/school/DA_Clion_cpp/cmake-build-debug/DA_Clion_cpp
40 30 50 13 35 48 14 31 18 33
41 NOT found!
87 NOT found!
56 NOT found!
38 NOT found!
31 FOUND at location: 7
53 NOT found!
81 NOT found!
50 FOUND at location: 2
50 FOUND at location: 2
35 FOUND at location: 4
72 NOT found!
31 FOUND at location: 7
89 NOT found!
41 NOT found!
94 NOT found!
91 NOT found!
30 FOUND at location: 1
81 NOT found!
72 NOT found!
94 NOT found!

Process finished with exit code 0



 */
