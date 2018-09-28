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
    int list[100] = {40, 30, 50, 13, 35, 48, 26, 31, 18, 33};
    int length = 10;

    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    // SEARCH 20 times
    for (int i = 0; i < 2 * length; i++)
    {
        // generate a random target within the range 1 to 100
        int target = rand() % 99 + 10;
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

40 30 50 13 35 48 26 31 18 33
86 NOT found!
44 NOT found!
87 NOT found!
93 NOT found!
95 NOT found!
90 NOT found!
34 NOT found!
54 NOT found!
63 NOT found!
47 NOT found!
82 NOT found!
27 NOT found!
97 NOT found!
81 NOT found!
73 NOT found!
39 NOT found!
44 NOT found!
26 FOUND at location: 6
107 NOT found!
47 NOT found!

Process finished with exit code 0


 */
