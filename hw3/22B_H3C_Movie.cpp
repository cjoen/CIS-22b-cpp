/**
 CIS 22B: Homework 3C

 Survey Statistics

 NAME: Christopher Owen
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
int *readSurveyData(const string &filename, int &n);
void insertionSort(int *pAry, int *pLast);
void writeArray(string filename, int *pAry, int *pLast, int &n);
double calcAvg(int *pAry, int *pLast);
double calcMedian(int *pAry, int *pLast, int &n);
void displayStats(int n, double avg, double median);

int main()
{

    string inFileName[]  = {"moviesurvey.txt", "moviestats.txt", "survey.txt", "testempty.txt", ""};
    string outFileName[] = {"surveyOut.txt", "statsOut.txt", "out.txt", "testemptyOut.txt", ""};
    int choice = 1;  // to stop the program to allow the user to see the results one file at a time

    int n;
    int *pAry;
    double avg, median;

    // test loop: takes the names of 4 input files from an array
    for (int i = 0; choice == 1 && inFileName[i] != ""; i++)
    {
        pAry = readSurveyData("/Users/cj/dev/school/DA_Clion_cpp/" + inFileName[i], n);
        int *pLast = pAry + n - 1;
        insertionSort(pAry, pLast);
        writeArray(outFileName[i], pAry, pLast, n);
        avg = calcAvg(pAry, pLast);
        median = calcMedian(pAry, pLast, n);
        displayStats(n, avg, median);

        delete [] pAry;
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }

#ifdef _MSC_VER
    cout << _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n";
#endif

    return 0;
}

/***************************************************************
 This function reads data from an input file into a dynamically
 allocated array
 filename - the name of the input file
 n - the array size (an output parameter)
 Return - the dynamically allocated array
 */
int *readSurveyData(const string &filename, int &n)
{
    ifstream inputFile;

    inputFile.open(filename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    inputFile >> n;

    int * fileData;
    fileData = new int [n];
    int i = 0;
    while(inputFile >> fileData[i]){
        i++;
    }

    // close the input file
    inputFile.close();


    return fileData;
}

/***************************************************************
 This function performs an ascending order insertion sort on
 array.
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void insertionSort(int *pAry, int *pLast)
{
    for (int *curr = pAry + 1; curr <= pLast; curr++)
    {
        int hold = *curr;                       // copy current element to hold
        int *back = curr - 1;
        while (back >= pAry && hold < *back)   // search where to insert the current element
        {
            *(back + 1) = *back;                // shift to the right
            back--;
        }
        *(back + 1) = hold;                     // put hold back to the array
    }
}

/***************************************************************
 This function writes the contents of array to a file
 filename - name of the output file
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void writeArray(string filename, int *pAry, int *pLast, int &n)
{
    ofstream outputFile;
    outputFile.open(filename.c_str());


    outputFile << n << endl;
    cout << "Array Length: " << n << endl;
    cout << "Ordered Array: ";
    for(int *pW = pAry; pW <= pLast; pW++ ) {
        cout << *pW << " ";
        outputFile << *pW << endl;
    }

    outputFile.close();
    cout << endl;
}

/***************************************************************
 This function calculates and returns the average of the numbers
 in array
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
double calcAvg(int *pAry, int *pLast)
{
    double avg = 0;
    int count = 0;

    for(int *pW = pAry; pW <= pLast; pW++ ) {
        avg += *pW;
        count++;
    }

    return avg/count;
}

/***************************************************************
 This function calculates and returns the median of the numbers
 in array
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
double calcMedian(int *pAry, int *pLast, int &n)
{
    double median = 0;
    double m1, m2;
    if(n%2 == 1){
        median = *pAry + n/2;
    } else {

        m1 = pAry[(n)/2];
        m2 = pAry[(n)/2 - 1];
        median = (m1+m2)/2;
    }
    return median;
}

/***************************************************************
 This function displays the movie statistics
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
void displayStats(int n, double avg, double median)
{
    cout << "Average: " << avg << endl;
    cout << "Median: " << median << endl;

}


/***************************************************************
 Save the OUTPUT below

/Users/cj/dev/school/DA_Clion_cpp/cmake-build-debug/DA_Clion_cpp
Array Length: 5
Ordered Array: 5 5 7 8 11
Average: 7.2
Median: 7
Please enter 1 to continue 0 to stop
1
Array Length: 6
Ordered Array: 7 7 7 8 9 10
Average: 8
Median: 7.5
Please enter 1 to continue 0 to stop
1
Array Length: 26
Ordered Array: 2 2 2 3 3 8 8 8 8 8 8 8 9 11 12 12 12 13 19 21 21 21 23 23 23 25
Average: 12.0385
Median: 10
Please enter 1 to continue 0 to stop
1

	Please check the name of the input file and
	try again later!

Process finished with exit code 1

 */
