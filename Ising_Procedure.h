//
// Created by ycx on 2021-07-03.
//

#ifndef DNA_ISING_MODEL_ISING_PROCEDURE_H
#define DNA_ISING_MODEL_ISING_PROCEDURE_H

#include <cmath>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <iostream>
#include "utility.h"
using namespace std;

#define consecutive_number 15

vector<int> annealing(vector<int>, long double);
bool check_for_long_range_existence(const vector<int>&);

#endif //DNA_ISING_MODEL_ISING_PROCEDURE_H
