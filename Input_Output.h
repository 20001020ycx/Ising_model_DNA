//
// Created by ycx on 2021-06-28.
//

#ifndef DNA_ISING_MODEL_INPUT_OUTPUT_H
#define DNA_ISING_MODEL_INPUT_OUTPUT_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> digitalization ();
void output_file (const vector<int>&, const string&);
void output_message(const vector<int>&, const int&);

#endif //DNA_ISING_MODEL_INPUT_OUTPUT_H
