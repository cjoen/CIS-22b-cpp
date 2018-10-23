/**
 CIS 22B: Homework 2C
 2D Arrays

 Project: Triangle

 NAME: Christopher Owen
 IDE: Clion

 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>



using namespace std;

const int MAXTBLSIZE = 100;  // the maximum table size is 100

int readTrg (string fileName, int trg[][MAXTBLSIZE], int trgSize);
void printTrg(int table[][MAXTBLSIZE], int trgSize);
void findPath(int trg[][MAXTBLSIZE], int trgSize);
//void printPath();


int main( void )
{
    string fileName[] = {"/Users/cj/dev/school/DA_Clion_cpp/t0.txt", "/Users/cj/dev/school/DA_Clion_cpp/t1.txt", "/Users/cj/dev/school/DA_Clion_cpp/t2.txt", "/Users/cj/dev/school/DA_Clion_cpp/t3.txt", "/Users/cj/dev/school/DA_Clion_cpp/t4.txt", "/Users/cj/dev/school/DA_Clion_cpp/t5.txt", "/Users/cj/dev/school/DA_Clion_cpp/t6.txt", ""};
    int trg[MAXTBLSIZE][MAXTBLSIZE] = {0}; // triangle created in a 2-d array
    int trgSize;     // triangle size (number of rows)
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time

    // test loop: takes the names of 7 input files from an array
    for (int i = 0; choice == 1 && fileName[i] != ""; i++)
    {

        trgSize = readTrg(fileName[i], trg, trgSize);
        cout << "Triangle size: " << trgSize << endl;
        if(trgSize <= 15)
            printTrg(trg, trgSize);
        findPath(trg, trgSize);
        //printPath(); // needs parameters

        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }

    return 0;
}

// read the triangle into a 2-d array
int readTrg (string fileName, int trg[][MAXTBLSIZE], int trgSize){
    ifstream inputFile;

    inputFile.open(fileName.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    int c = 0;

    inputFile >> trgSize;
    int i = 0;
    while(inputFile >> trg[c][i]){
        if (i == c){
            i = 0;
            c++;
        } else {
            i++;
        }
    }


    if ( c == MAXTBLSIZE && !inputFile.eof())
    {
        cout << "\n\tThe input file  \"" << fileName
             << "\" is too big: \n\tit has more than "
             << MAXTBLSIZE << " items!\n";
        exit(EXIT_FAILURE);
    }
    // close the input file
    inputFile.close();


    return trgSize;
}

//print the 2-d array to display the triangle
void printTrg (int table[][MAXTBLSIZE], int trgSize){

    for (int r = 0; r < trgSize; ++r) {
        for (int c = 0; c <= r ; ++c) {
            cout << table[r][c] << " ";
        }
        cout << endl;

    }

    cout << endl;
}

//this functions finds the greatest sum and then finds the path that made the sum
void findPath(int trg[][MAXTBLSIZE], int trgSize){

    //I used only one array because I didn't think it was necessary to have two.

    //calculate maximum sum
    int numOne = trg[0][0];
    for(int i = 1; i < trgSize; i++) {
        trg[i][0] = trg[i][0] + trg[i-1][0];
        trg[i][i] = trg[i][i] + trg[i-1][i-1];

        for (int j = 1; j < i; j++){

            if (trg[i][j] + trg[i-1][j-1] >= trg[i][j] + trg[i-1][j]) {
                trg[i][j] = trg[i][j] + trg[i - 1][j - 1];
            }else{
                trg[i][j] = trg[i][j] + trg[i - 1][j];
            }
        }
    }

    int max=trg[trgSize-1][0];
    int maxPos;
    for(int i=1;i<trgSize;i++)
    {
        if(max<trg[trgSize-1][i]) {
            max = trg[trgSize - 1][i];
            maxPos = i;
        }
    }


    //find exact path and print path
    int tempMax = max;
    int d = maxPos;
    string paths[trgSize];

    for (int k = trgSize-1; 0 < k ; --k) {
        if(d > 0 && trg[k-1][d-1] > trg[k-1][d]){
            paths[k] = "( " + to_string(k) + ", " + to_string(d) + ") - " + to_string(tempMax-trg[k-1][d-1]);
            tempMax = trg[k-1][d-1];
            --d;
        } else {
            paths[k] = "( " + to_string(k) + ", " + to_string(d) + ") - " + to_string(tempMax-trg[k-1][d]);
            tempMax = trg[k-1][d];
        }

    }
    paths[0] = "( 0, 0) - " + to_string(numOne);
    for (int p = 0; p < trgSize ; ++p) {
        cout << paths[p] << endl;
    }


    cout << "-------------" << endl;
    cout << "         " << max << endl;

}

//void printPath (){

//}


/** Save the output below

/Users/cj/dev/school/DA_Clion_cpp/cmake-build-debug/DA_Clion_cpp
Triangle size: 5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

( 0, 0) - 7
( 1, 0) - 3
( 2, 0) - 8
( 3, 1) - 7
( 4, 1) - 5
-------------
         30
Please enter 1 to continue 0 to stop
1
Triangle size: 6
88
97 26
39 16 47
94 25 66 4
64 49 20 36 27
37 87 29 37 10 40

( 0, 0) - 88
( 1, 0) - 97
( 2, 0) - 39
( 3, 0) - 94
( 4, 0) - 64
( 5, 1) - 87
-------------
         469
Please enter 1 to continue 0 to stop
1
Triangle size: 10
65
40 52
69 95 15
84 75 42 14
52 85 0 87 66
7 20 52 14 32 73
28 26 91 52 72 65 29
52 7 95 68 69 78 31 73
50 5 47 40 91 39 30 55 5
44 83 36 28 53 9 64 37 47 15

( 0, 0) - 65
( 1, 1) - 52
( 2, 1) - 95
( 3, 1) - 75
( 4, 1) - 85
( 5, 2) - 52
( 6, 2) - 91
( 7, 3) - 68
( 8, 4) - 91
( 9, 4) - 53
-------------
         727
Please enter 1 to continue 0 to stop
1
Triangle size: 15
74
67 51
64 47 54
69 97 1 31
89 14 11 3 72
68 21 70 46 87 68
5 6 6 29 51 40 71
18 38 15 10 53 19 55 7
9 70 16 78 89 66 84 7 83
80 19 22 82 19 40 44 35 44 35
85 54 22 16 92 43 21 59 25 18 94
30 19 19 2 33 54 93 95 76 66 43 46
93 36 12 43 26 47 55 26 54 27 23 11 67
51 86 88 42 37 92 61 36 25 18 24 17 16 69
6 14 10 61 86 52 79 37 96 83 47 44 83 88 20

( 0, 0) - 74
( 1, 0) - 67
( 2, 0) - 64
( 3, 0) - 69
( 4, 0) - 89
( 5, 0) - 68
( 6, 1) - 6
( 7, 2) - 15
( 8, 3) - 78
( 9, 3) - 82
( 10, 4) - 92
( 11, 5) - 54
( 12, 5) - 47
( 13, 5) - 92
( 14, 6) - 79
-------------
         976
Please enter 1 to continue 0 to stop
1
Triangle size: 30
( 0, 0) - 30
( 1, 0) - 47
( 2, 1) - 65
( 3, 2) - 94
( 4, 2) - 34
( 5, 2) - 29
( 6, 3) - 98
( 7, 4) - 49
( 8, 5) - 60
( 9, 6) - 96
( 10, 7) - 64
( 11, 8) - 81
( 12, 9) - 83
( 13, 9) - 43
( 14, 9) - 77
( 15, 10) - 73
( 16, 10) - 79
( 17, 10) - 88
( 18, 10) - 87
( 19, 10) - 80
( 20, 10) - 32
( 21, 11) - 85
( 22, 11) - 44
( 23, 12) - 82
( 24, 12) - 88
( 25, 12) - 98
( 26, 13) - 92
( 27, 14) - 63
( 28, 15) - 95
( 29, 15) - 99
-------------
         2135
Please enter 1 to continue 0 to stop
1
Triangle size: 60
( 0, 0) - 46
( 1, 1) - 64
( 2, 1) - 53
( 3, 1) - 56
( 4, 1) - 81
( 5, 2) - 98
( 6, 3) - 85
( 7, 3) - 57
( 8, 4) - 56
( 9, 4) - 39
( 10, 4) - 71
( 11, 4) - 94
( 12, 5) - 51
( 13, 6) - 99
( 14, 6) - 91
( 15, 7) - 92
( 16, 7) - 89
( 17, 8) - 74
( 18, 9) - 54
( 19, 10) - 71
( 20, 10) - 31
( 21, 11) - 82
( 22, 12) - 45
( 23, 13) - 88
( 24, 13) - 67
( 25, 14) - 72
( 26, 15) - 88
( 27, 15) - 94
( 28, 16) - 64
( 29, 17) - 91
( 30, 18) - 85
( 31, 18) - 86
( 32, 19) - 58
( 33, 20) - 76
( 34, 21) - 66
( 35, 22) - 96
( 36, 23) - 82
( 37, 24) - 92
( 38, 25) - 90
( 39, 25) - 99
( 40, 26) - 49
( 41, 26) - 73
( 42, 27) - 66
( 43, 27) - 69
( 44, 27) - 79
( 45, 27) - 62
( 46, 27) - 95
( 47, 27) - 43
( 48, 27) - 95
( 49, 27) - 81
( 50, 27) - 87
( 51, 28) - 74
( 52, 29) - 77
( 53, 30) - 95
( 54, 31) - 63
( 55, 32) - 85
( 56, 32) - 74
( 57, 33) - 78
( 58, 34) - 79
( 59, 34) - 69
-------------
         4466
Please enter 1 to continue 0 to stop
1
Triangle size: 100
( 0, 0) - 63
( 1, 0) - 65
( 2, 0) - 23
( 3, 0) - 95
( 4, 0) - 63
( 5, 0) - 41
( 6, 1) - 61
( 7, 1) - 86
( 8, 1) - 54
( 9, 1) - 84
( 10, 1) - 78
( 11, 1) - 31
( 12, 1) - 70
( 13, 1) - 83
( 14, 1) - 84
( 15, 2) - 91
( 16, 2) - 55
( 17, 3) - 94
( 18, 3) - 91
( 19, 3) - 78
( 20, 3) - 91
( 21, 3) - 50
( 22, 3) - 92
( 23, 4) - 90
( 24, 5) - 51
( 25, 6) - 58
( 26, 6) - 52
( 27, 6) - 70
( 28, 6) - 84
( 29, 6) - 82
( 30, 6) - 87
( 31, 6) - 90
( 32, 6) - 1
( 33, 6) - 49
( 34, 6) - 73
( 35, 6) - 64
( 36, 6) - 76
( 37, 6) - 76
( 38, 7) - 71
( 39, 7) - 96
( 40, 7) - 46
( 41, 7) - 77
( 42, 7) - 66
( 43, 7) - 73
( 44, 7) - 77
( 45, 8) - 65
( 46, 9) - 50
( 47, 10) - 77
( 48, 10) - 59
( 49, 10) - 64
( 50, 10) - 69
( 51, 10) - 96
( 52, 11) - 80
( 53, 11) - 78
( 54, 12) - 56
( 55, 13) - 50
( 56, 13) - 93
( 57, 13) - 51
( 58, 13) - 39
( 59, 14) - 41
( 60, 14) - 99
( 61, 15) - 69
( 62, 15) - 99
( 63, 16) - 82
( 64, 16) - 66
( 65, 16) - 96
( 66, 16) - 68
( 67, 16) - 91
( 68, 17) - 84
( 69, 18) - 78
( 70, 18) - 84
( 71, 18) - 75
( 72, 18) - 82
( 73, 19) - 84
( 74, 20) - 79
( 75, 21) - 43
( 76, 21) - 52
( 77, 21) - 78
( 78, 21) - 87
( 79, 21) - 96
( 80, 22) - 45
( 81, 22) - 88
( 82, 22) - 78
( 83, 22) - 39
( 84, 23) - 98
( 85, 24) - 74
( 86, 24) - 98
( 87, 24) - 92
( 88, 25) - 57
( 89, 26) - 55
( 90, 27) - 86
( 91, 28) - 97
( 92, 29) - 43
( 93, 30) - 70
( 94, 30) - 85
( 95, 30) - 98
( 96, 31) - 63
( 97, 32) - 81
( 98, 32) - 82
( 99, 32) - 57
-------------
         7178
Please enter 1 to continue 0 to stop
1

Process finished with exit code 0


 */
