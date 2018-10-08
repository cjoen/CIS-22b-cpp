//Christopher Owen Team H
//assignment 11.1 Week 4

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct MovieData {
    string title;
    string director;
    int year;
    int runTime; //in minutes
    double prodCosts;
    double yearRev;
};

void fillStruct (MovieData *m){
  cout << "Please enter the data of your favourit movie below " << endl;
  cout << "Please enter the movie Title: ";
  cin >> m->title;
  cout << "Please enter the movie director: ";
  cin >> m->director;
  cout << "Please enter the movie year: ";
  cin >> m->year;
  cout << "Please enter the movie runtime (in minutes): ";
  cin >> m->runTime;
  cout << "Please enter the movie production cost: ";
  cin >> m->prodCosts;
  cout << "Please enter the First year revenue: ";
  cin >> m->yearRev;

}

void printStruct(MovieData *m){
  //do you just print each .value of each element in struct
  cout << "Title   : " << m->title << endl;
  cout << "Director   : " << m->director << endl;
  cout << "Released   : " << m->year << endl;
  cout << "Runtime  : " << m->runTime << " minutes" << endl;
  cout << "Production cost : $" << m->prodCosts << ".00" << endl;
  cout << "First Year Revenue : $" << m->yearRev << ".00" << endl;

  double profits = m->yearRev - m->prodCosts;
  if (profits > 0){
    cout << "The first year profit : $" << profits << ".00" << endl << endl;
  } else {
    cout << "The first year loss : $" << profits << ".00" << endl << endl;
  }

}

int main() {

// set structure data fields
    MovieData movie1, movie2;

// get movie data using a function.
  fillStruct(&movie1);
  fillStruct(&movie2);

  //print movie data using print function
  printStruct(&movie1);
  printStruct(&movie2);



  return 0;
}
