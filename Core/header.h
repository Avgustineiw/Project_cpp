#pragma once
#include "readFromCSV.h"
#include "respondentToPoint.h"

#include <vector>
#include <iostream>
#include <ctime>

const string CSV_PATH = "/Users/avgustine/Project_cpp/music_health_data.csv";
const string OUTPUT_PATH = "/Users/avgustine/Project_cpp/output.csv";


void InitializeProgram()
{
  vector<vector<string>> data;
  vector<Respondent> respondents;

  srand(time(NULL));

  ReadFromCSV(CSV_PATH, data);
  DataToRespondent(data, respondents);

  ofstream output_file(OUTPUT_PATH);
  
  for (size_t i = 0; i < respondents.size(); i++) {
    // cout << respondents[i];
    double x = 0, y = 0;
    x = respondentToPoint(respondents[i]).GetX();
    y = respondentToPoint(respondents[i]).GetY();
    if (y != 0) {
      output_file << x << "," << y << "," << (rand() & 1) + 1 << '\n';
    }
  }
}
