/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Triangle
 
 NAME:
 IDE:
 
 */

#include <iostream>

using namespace std;

const int MAXTBLSIZE = 100;  // the maximum table size is 100


int main( void )
{
    string fileName[] = {"T0.txt", "T1.txt", "T2.txt", "T3.txt", "T4.txt", "T5.txt", "T6.txt", ""};
    int trg[MAXTBLSIZE][MAXTBLSIZE] = {0};
    int trgSize;     // triangle size (number of rows)
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time
    
    // test loop: takes the names of 7 input files from an array
    for (int i = 0; choice == 1 && fileName[i] != ""; i++)
    {
        readTrg(fileName[i], trg, trgSize);
        printTrg(table, trgSize);
        findPath(); // needs parameters
        printPath(); // needs parameters
        
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }
    
    return 0;
}   // main


/** Save the output below
 
 
 */