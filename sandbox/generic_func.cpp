/***



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
    for (int i = 0; i < 2 * length; i++)
    {
        // generate a random target within the range 1 to 100
        int target = rand() % 99 + 10;
        int location = searchAry(array[], target, size);
        if (location = -1)
            cout << target << " FOUND at location: " << location << endl;
        else
            cout << target << " NOT found!" << endl;
    }

    return 0;
}

void readData(string arr1[], string arr2[], int arr3[], int &size, const int maxSize)
{
    string inputfilename = "filename.txt";
    ifstream inputFile;

    // prompt user for filename
    //cout << "\nPlease enter the name of the file that holds the students' scores and IDs: \n";
    //cin >> inputfilename;

    // open the input file
    inputFile.open(inputfilename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    // reading data from the input file into arrays
    int idx = 0;
    while (idx < maxSize && inputFile >> arr1[idx] >> arr2[idx] >> arr3[idx])
    {
        idx++;
    }
    size = idx;
    if ( size == maxSize && !inputFile.eof())
    {
        cout << "\n\tThe input file  \"" << inputfilename
             << "\" is too big: \n\tit has more than "
             << maxSize << " items!\n";
        exit(EXIT_FAILURE);
    }
    // close the input file
    inputFile.close();
}

for (k = 0; k < n; k++) {
  temp = a[k];
  a[k] = a[n-(1+k)];
  a[n-(1+k)] = temp;
}
