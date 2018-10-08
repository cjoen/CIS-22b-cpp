/***
 22B - PROGRAM 1C:

 Changed by: Christopher Owen
 IDE: CLion

 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>


using namespace std;

int readData(string code[], int population[], string country[], int maxSize);
string getSearch();
int binarySearch(const string array[], int numElems, string value);
void writeData (string code[], int population[], string country[], int searchCount[], int actSize);

int main()
{
    //Defining initial variables
    const int maxSize = 200;
    int actSize;
    string code [maxSize];
    int population [maxSize];
    string country [maxSize];
    int searchCount [maxSize] = {0};

    //Import Data and save the size of the list of imported countries
    actSize = readData(code, population, country, maxSize);

    cout << "This program finds the name and population of a country code that is entered." << endl;

    char again;

    //Interactive loop for choosing to run the program again
    do {

        string search;
        int foundPos;

        //prompt user to input a country code
        search = getSearch();

        //find the position of the country using binary search
        foundPos = binarySearch(code, actSize, search);

        //store and count search history
        if (foundPos == -1) {
            cout << "Unable to find country code.\n";
        } else {
            cout << "Name: " << country[foundPos] << endl;
            cout << "Population: " << population[foundPos] << endl;
            searchCount[foundPos] += 1;
        }

        cout << "would you like to go again? (Y/N)";
        cin >> again;
        cin.ignore();
    } while (again == 'y' || again == 'Y');

    //output country list and searchcount to external file called 'results.txt'
    writeData(code, population, country, searchCount, actSize);

}


//readData takes in data from a file and place it in parallel arrays
int readData(string code[], int population[], string country[], int maxSize) {
    string inputfilename = "/Users/cj/dev/school/DA_Clion_cpp/countries.txt";
    ifstream inputFile;

    inputFile.open(inputfilename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    int c = 0;

    while(c < maxSize && !inputFile.eof()) {
        inputFile >> code[c];
        inputFile >> population[c];
        getline(inputFile, country[c]);
        c++;
    }

    if ( c == maxSize && !inputFile.eof())
    {
        cout << "\n\tThe input file  \"" << inputfilename
             << "\" is too big: \n\tit has more than "
             << maxSize << " items!\n";
        exit(EXIT_FAILURE);
    }
    // close the input file
    inputFile.close();

    return c;

}

// request user to input a new search
string getSearch(){
    string search;

    cout << "please enter a country code of your choice:";
    cin >> search;
    cin.ignore();
    return search;

}

// Binary search to find position of country
int binarySearch(const string array[], int numElems, string value)
{
    int first = 0,		 // First array element
            last = numElems - 1, // Last array element
            middle,				 // Midpoint of search
            position = -1;		 // Position of search value
    bool found = false;

    while ( !found && first <= last)
    {
        middle = (first + last) / 2;  // Calculate midpoint
        if (array[middle] == value)	  // If value is found at mid
        {
            position = middle;
            found = true;
        }
        else if (array[middle] > value) { // If value is in lower half
            last = middle - 1;
        }else {
            first = middle + 1;            // If value is in upper half
        }
    }
    return position;
}

//write country data and search counts to results file
void writeData (string code[], int population[], string country[], int searchCount[], int actSize){
    ofstream outputFile;
    outputFile.open("/Users/cj/dev/school/DA_Clion_cpp/results.txt");

    for (int i = 0; i < actSize ; i++) {
        outputFile << searchCount[i] << " " << code[i] << " " << country[i] << " (" << population[i] << ") \n";
    }

    outputFile.close();

    cout << "Successfully written to 'results.txt' " << endl;


}





/****************** OUTPUT

 /Users/cj/dev/school/DA_Clion_cpp/cmake-build-debug/DA_Clion_cpp
This program finds the name and population of a country code that is entered.
please enter a country code of your choice:FJ
Name:  Figi
Population: 893354
would you like to go again? (Y/N)y
please enter a country code of your choice:BR
Name:  Brazil
Population: 186112794
would you like to go again? (Y/N)y
please enter a country code of your choice:US
Name:  United States
Population: 295734134
would you like to go again? (Y/N)y
please enter a country code of your choice:BR
Name:  Brazil
Population: 186112794
would you like to go again? (Y/N)y
please enter a country code of your choice:FJ
Name:  Figi
Population: 893354
would you like to go again? (Y/N)Y
please enter a country code of your choice:LI
Name:  Liechtenstein
Population: 33717
would you like to go again? (Y/N)Y
please enter a country code of your choice:US
Name:  United States
Population: 295734134
would you like to go again? (Y/N)Y
please enter a country code of your choice:BR
Name:  Brazil
Population: 186112794
would you like to go again? (Y/N)n
Successfully written to 'results.txt'

Process finished with exit code 0

 */
