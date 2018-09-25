//Christopher Owen Team H
//assignment [NUMBER][WEEK]

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString (string line){ //take the string and split it on spaces
  getline(cin, line);
  int len = line.length();
  vector<string> subArray;

  for (int j = 0, k = 0; j < len; j++) {
      if (line[j] == ' ') {
          string ch = line.substr(k, j - k);
          k = j+1;
          subArray.push_back(ch);
      }
      if (j == len - 1) {
          string ch = line.substr(k, j - k+1);
          subArray.push_back(ch);
      }
  }
  return subArray;
}

void parseString (string line){ // take the seperated strings and split it on spaces
  vector <string> splitLine;  //have a vector of strings
  splitLine = splitString(line);
  string fullName;
  vector <int> scores;  // have a vector of integers
  double avgScores;
  int sumScores;


  //add all quiz scores to scores vector
  for (int i = 0; i < splitLine.size(); i++) {
    if (std::string::npos != splitLine[i].find_first_of("0123456789")){ //
      scores.push_back(atoi(splitLine[i]));
      sumScores += atoi(splitLine[i]);
    }
  }

  fullName = splitLine[1] + " " + splitLine[0]; //define full name
  avgScores = sumScores/10 ; // calculate avg score

  // output of function
  cout << fullName << " ";
  for (int j = 0; j < scores.size(); j++) {
    cout << score[j] << " ";
  }
  cout << avgScores << endl;

}

int main() {
  string inFilename, fullName; // To hold the file name
  string line; // To hold each line as a string
  fstream inFile; // input File stream object
  inFile.open("/Users/cj/dev/school/int-cpp/midterm/input.txt");  //open input file

  if (inFile) {
    getline(inFile, line);  //get the first line in the input file
    parseString(line); // take the string data and seperate it
      while (inFile){  // loop through all lines of the file
        getline(inFile, line);
        parseString(line);
      }

  } else {
    cout << "Error accessing file";
  }

  inFile.close();  //close input file
  return 0;

}
