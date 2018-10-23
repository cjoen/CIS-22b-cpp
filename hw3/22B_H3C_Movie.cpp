/**
 CIS 22B: Homework 3C

 Survey Statistics

 NAME:
 */
#include <iostream>
#include <iomanip>
using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
int *readSurveyData(string filename, int &n);
void insertionSort(int *pAry, int *pLast);
void writeArray(string filename, int *pAry, int *pLast);
double calcAvg(int *pAry, int *pLast);
double calcMedian(int *pAry, int *pLast);
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
        pAry = readSurveyData(inFileName[i], n);
        int *pLast = pAry + n - 1;
        insertionSort(pAry, pLast);
        writeArray(outFileName[i], pAry, pLast);
        avg = calcAvg(pAry, pLast);
        median = calcMedian(pAry, pLast);
        displayStats(n, avg, median);


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
int *readSurveyData(string filename, int &n)
{
    return NULL;
}

/***************************************************************
 This function performs an ascending order insertion sort on
 array.
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void insertionSort(int *pAry, int *pLast)
{

}

/***************************************************************
 This function writes the contents of array to a file
 filename - name of the output file
 pList - points to the first element in array
 pLast - points to the last element in array
 */
void writeArray(string filename, int *pAry, int *pLast)
{

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

    return avg;
}

/***************************************************************
 This function calculates and returns the median of the numbers
 in array
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
double calcMedian(int *pAry, int *pLast)
{
    double median = 0;

    return median;
}

/***************************************************************
 This function displays the movie statistics
 pList - points to the first element in the array
 pLast - points to the last element in the array
 */
void displayStats(int n, double avg, double median)
{

}


/***************************************************************
 Save the OUTPUT below


 */

