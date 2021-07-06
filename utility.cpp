//
// Created by ycx on 2021-06-28.
//

#include "utility.h"

long double annealing_hamiltonian;
std::mutex mtx;

long double Hamiltonian_calculation(const vector<int>& DNA_sequence){
    //assume J = 1, Alpha = 1
    long double hamiltonian(0);
    for (int i = 0; i < DNA_sequence.size(); i ++){
        for (int j = i; j < DNA_sequence.size() && j < i + DNA_sequence.size() / 6; j ++){
            if (i == j) continue;
            int distance = abs(i - j);
            //double power_decay = pow(distance,-Alpha);
            double power_decay = 1.0 / distance;
            hamiltonian -= power_decay * DNA_sequence[i] * DNA_sequence[j];
        }
    }
    return hamiltonian;
}

void annealing_Hamiltonian_multithread(const vector<int>& DNA_sequence, int begin, int thread_index){
    //assume J = 1
    for (int i = begin; i < thread_index; i ++){
        for (int j = i + 1; j < DNA_sequence.size(); j ++){
            //if (i == j) continue;
            int distance = abs(i - j);
            double power_decay = pow(distance,-Alpha);
            mtx.lock();
            annealing_hamiltonian -= power_decay * DNA_sequence[i] * DNA_sequence[j];
            mtx.unlock();
        }
    }
}

void multithreading_Hamiltonian_calculation(const vector<int>& annealing_DNA_sequence){
    std::thread Hamiltonian_thread1(annealing_Hamiltonian_multithread,annealing_DNA_sequence,0, annealing_DNA_sequence.size()/4);
    std::thread Hamiltonian_thread2(annealing_Hamiltonian_multithread,annealing_DNA_sequence,annealing_DNA_sequence.size()/4, annealing_DNA_sequence.size()/2);
    std::thread Hamiltonian_thread3(annealing_Hamiltonian_multithread,annealing_DNA_sequence,annealing_DNA_sequence.size()/2, 3 * annealing_DNA_sequence.size()/4);
    std::thread Hamiltonian_thread4(annealing_Hamiltonian_multithread,annealing_DNA_sequence,3 * annealing_DNA_sequence.size()/4, annealing_DNA_sequence.size());

    Hamiltonian_thread1.join();
    Hamiltonian_thread2.join();
    Hamiltonian_thread3.join();
    Hamiltonian_thread4.join();
}