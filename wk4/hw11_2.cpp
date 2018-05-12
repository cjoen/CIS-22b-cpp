//Christopher Owen Team H
//assignment 11.2 week 4

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct  player {
  string name;
  int number;
  int score;
};

//request data for each player
void getData (player *p) {
  cout << "Please enter a name for the player: ";
  cin >> p->name;
  cout << "Please enter a player number: ";
  cin >> p->number;
  cout << "Please enter the players score: ";
  cin >> p->score;
}

int main() {
  //define main variables
  int SIZE = 12;
  player team[SIZE];
  player winner;
  int scoreSum = 0;

  //loop through player array getting and processing data
  for (int i = 0; i < SIZE; i++) {
    getData(&team[i]);
    scoreSum += team[i].score;
    if (team[i].score > winner.score) {
      winner = team[i];
    }
  }

  //outputting processed data.
  cout << "Sum of scores: " << scoreSum << endl;
  cout << "The winner is: " << winner.name << " player number: " << winner.number << endl;

  return 0;
}
