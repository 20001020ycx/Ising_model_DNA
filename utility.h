//
// Created by ycx on 2021-06-28.
//

#ifndef DNA_ISING_MODEL_UTILITY_H
#define DNA_ISING_MODEL_UTILITY_H

#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
using namespace std;

#define AT_base 1
#define CG_base -1
/*beta is the inverse of the temperature times Boltzmann constant;
 * however, since we are trying to reach the curie temperature,
 * there is no need for increment*/

#define source_path "/home/ycx/Documents/programming/DNA_Ising_Model/DNA_sequence.txt"
#define output_path "/home/ycx/Documents/programming/DNA_Ising_Model/output_DNA_sequence.txt"
#define source_digit "/home/ycx/Documents/programming/DNA_Ising_Model/input_DNA_sequence.txt"
#define multithreading_threshold 100000

extern double Alpha;
extern double Beta;

extern long double annealing_hamiltonian;
extern std::mutex mtx;

long double Hamiltonian_calculation(const vector<int>&);
void annealing_Hamiltonian_multithread(const vector<int>&, int, int);
void multithreading_Hamiltonian_calculation(const vector<int>&);

#endif //DNA_ISING_MODEL_UTILITY_H
