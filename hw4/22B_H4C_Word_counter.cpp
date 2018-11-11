/**
 CIS 22B: Homework 4C

 Structures and Strings
 Project: Text Analyzer: Word Count

 NAME: Christopher Owen
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

const bool DE_BUG = false;  // when done debugging change the DE_BUG flag to false

/* Define a struct named Word with the following fields:

 1. word, a string
 2. cnt, an integer

 */
struct Word{
    string word;
    int ctn = 0;
};


/* Define a struct named WordStats with the following fields:

 1. list, an array of ARY_SIZE Word structures defined above
 2. noWords, an integer, for the number of distinct words
 3. maxLength, an integer, for the longest word's length
 4. highFreq, an integer, for the highest frequency

 */

struct WordStats {
    Word list[100] = {};
    int noWords = 0,
    maxLength = 0,
    highFreq = 0;
};



// Function prototypes
void printWelcome(void);
void readWords(string inFilename, WordStats *stats);
void insertionSort(Word ary[], int size);
void printHighestFreq( const WordStats *stats, ofstream& fout);
void writeFile( string outFilename, const WordStats *stats);
void printEnd(void);
void readWords (string inFilename, WordStats *stats);

int main()
{
    string inFilename[] = {"/Users/cj/dev/school/DA_TestingEnviroment/song_row.txt", "/Users/cj/dev/school/DA_TestingEnviroment/song_ten.txt", "/Users/cj/dev/school/DA_TestingEnviroment/test.txt", ""};
    string outFilename = "";

    // use the following data for testing
    // insertionSort, writeFile, and printprintHigestFreq function


    printWelcome();

    for (int i = 0; inFilename[i] != ""; i++)
    {
        WordStats stats;
        //this is where you run code on each file
        outFilename = inFilename[i].substr(0,inFilename[i].length() - 4) + "_OUT.txt";

        cout << "Read data from: " << inFilename[i] << endl;
        readWords(inFilename[i], &stats);

        insertionSort(stats.list, stats.noWords);
        writeFile(outFilename, &stats);
        //printHighestFreq(&stats, );
        // generate the output file name
        cout << "Write report to: " << outFilename << endl << endl;
    }
    printEnd();

    return 0;
}
/**************************************************
 this uses the file stream to read each word at a time and add it to the word list.
 */
void readWords (string inFilename, WordStats *stats){
    ifstream inputFile;

    inputFile.open(inFilename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    string word;

    while(inputFile >> word){
        for (int i = 0; i < word.length(); ++i) {

            if (ispunct(word[i]) || isspace(word[i])) {
                word.erase(i--, 1);
            } else if(isupper(word[i])){
                word[i] = tolower(word[i]);
            }
        }


        bool found = false;

        for (int j = 0; j < (*stats).noWords ; ++j) {
            if (word.compare((*stats).list[j].word) == 0 ){
                (*stats).list[j].ctn++;

                found = true;
            }
        }

        if(!found){
            Word temp = {word, 1};
            (*stats).list[(*stats).noWords] = temp;
            if (1 > (*stats).highFreq) {
                (*stats).highFreq = 1;
            }
            (*stats).noWords++;
        }
        if (word.length() > (*stats).maxLength) {
            (*stats).maxLength = word.length();
        }



    }

    inputFile.close();

}

/**************************************************
 This sorts through the list sorting it a word at a time
 */
void insertionSort(Word ary[], int size)
{
    for (int i = 0; i < size; i++ )
    {
        for (int j = 0;j < size - 1; j++)
        {
            if (ary[j + 1].word.compare(ary[j].word))
            {
                struct Word x = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = x;
            }


        }

    }
    if (DE_BUG)
        cout << "\tDEBUG: This is the insertionSort function" << endl;

}


/**************************************************
  this function returns the highest frequency for words
 */
void printHighestFreq( const WordStats *stats, ofstream& fileout)
{
    int highFreq = (*stats).highFreq;

    for (int i = 0; i < (*stats).noWords; i++) {
        if ((*stats).list[i].ctn > highFreq) {
            highFreq = (*stats).list[i].ctn;
        } else {
            continue;
        }
    }

    fileout << "The highest frequency word is appeared: " << highFreq << " times"<<endl;


    if (DE_BUG)
        cout << "\tDEBUG: This is the printHigestFreq function" << endl;
}

/**************************************************
 This function writes all the code to a new txt file
 */
void writeFile( string outFilename, const WordStats *stats)
{

    ofstream fileout;
    fileout.open(outFilename);

    if (fileout.fail())
    {
        cout << "The output file failed to open.\n";
        exit(-1);
    }

    fileout << (*stats).noWords << " word" << endl;
    fileout << "Maximum length: " << (*stats).maxLength << endl;
    fileout << "Highest frequency: " << (*stats).highFreq << endl << endl;

    for (int i = 0; i < (*stats).noWords; i++) {
        fileout << (*stats).list[i].ctn << " " << (*stats).list[i].word << endl;
    }

    fileout << endl;

    printHighestFreq(stats, fileout);

    fileout.close();


    if (DE_BUG)
        cout << "\tDEBUG: This is the writeFile function" << endl;
}

/**************************************************
 This function displays a welcome message and briefly
 explains the purpuse of this program.
 */
void printWelcome(void)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the welcome function\n" << endl;
    cout << "\t\tHomework 4C\n\tText Analyzer: Word Count\n\n";
    cout << "Developer: " << "Christopher Owen" << endl;

}

/**************************************************
 This function displays an end of the program message
 */
void printEnd(void)
{
    if (DE_BUG)
        cout << "\tDEBUG: This is the end of the program function\n" << endl;
}
/***************************************************************
 Save the OUTPUT below

	DEBUG: This is the welcome function

 Homework 4C
	Text Analyzer: Word Count

 Read data from: song_row.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:

 Read data from: song_ten.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:

 Read data from: test.txt
	DEBUG: This is the insertionSort function
	DEBUG: This is the writeFile function
	DEBUG: This is the printHigestFreq function
 Write report to:

	DEBUG: This is the end of the program function

 Program ended with exit code: 0

 ******************************************************************

 /Users/cj/dev/school/DA_TestingEnviroment/cmake-build-debug/DA_TestingEnviroment
		Homework 4C
	Text Analyzer: Word Count

Developer: Christopher Owen
Read data from: /Users/cj/dev/school/DA_TestingEnviroment/song_row.txt
Write report to: /Users/cj/dev/school/DA_TestingEnviroment/song_row_OUT.txt

Read data from: /Users/cj/dev/school/DA_TestingEnviroment/song_ten.txt
Write report to: /Users/cj/dev/school/DA_TestingEnviroment/song_ten_OUT.txt

Read data from: /Users/cj/dev/school/DA_TestingEnviroment/test.txt
Write report to: /Users/cj/dev/school/DA_TestingEnviroment/test_OUT.txt


Process finished with exit code 0


 */
