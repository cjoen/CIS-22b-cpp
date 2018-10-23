/**
 CIS 22B: Homework 2B
 2D Arrays

 This program calls a function that takes a table of quizzes and calculates
 and stores the average of each quiz.

 For the data shown below, the averages should be:
    10.00, 8.00, 9.00, 9.00, 7.00, 7.75, 9.25, 9.50

 Find and fix the errors. Run the program and save the output
 as a comment at the end of the program.

 NAME: Christopher Owen
*/

#include <iostream>
#include <iomanip>


using namespace std;

const int STU = 5;
const int QUIZZES = 10;

void calcQuizAvg(double table[][QUIZZES], double nStu, int nQuiz,  double qAvg[] );

int main()
{
    double stu     = 4; //  actual number of students
    int quizzes = 8; //  a total of 8 quizzes
    double table [STU] [QUIZZES] =
            {
                    {10,  8,  9, 10,  4,  7, 10,  9},
                    {10,  8,  9,  8,  6,  8,  9, 10},
                    {10,  8,  9,  8,  9,  8,  8,  9},
                    {10,  8,  9, 10,  9,  8, 10, 10},
            };
    double qAvg[STU];

    calcQuizAvg( table, stu, quizzes, qAvg );

    for (int i = 0; i < quizzes; i++)
        cout << fixed << setprecision(2) << qAvg[i] << " ";
    cout << endl;

    return 0;
}   // main

/*********************************************************************
 This function takes a table of quizzes and calculates and stores the
 average of each quiz
 PRE: - table[][] - has data
      - nStu
      - nQuiz
      - qAvg[] - empty
 POST: qAvg[] - contains the average for each quiz
 */
void calcQuizAvg(double table[][QUIZZES], double nStu, int nQuiz, double qAvg[] )
{

    for( int c = 0; c < nQuiz; c++ )
    {
        double sum = 0;

        for( int r = 0; r < nStu; r++ )
        {
            sum += table[r][c];
        }

        qAvg[c] = sum/nStu;

    }
}


/** Save the correct output below

 /Users/cj/dev/school/DA_Clion_cpp/cmake-build-debug/DA_Clion_cpp
10.00 8.00 9.00 9.00 7.00 7.75 9.25 9.50

Process finished with exit code 0

*/
