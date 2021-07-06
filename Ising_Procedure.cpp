//
// Created by ycx on 2021-07-03.
//

#include "Ising_Procedure.h"

vector<int> annealing(vector<int> DNA_sequence, long double current_best_hamiltonian){
    auto begin_time = std::chrono::high_resolution_clock::now();
    int count = 0;
    vector<int> annealing_DNA_sequence = DNA_sequence;

    while (true) {

        srand(time(nullptr));
        //annealing judgement:
        /*?std::uniform_real_distribution::operator(),? cplusplus.com.
                 * [Online]. Available: http://www.cplusplus.com/reference/random/uniform_real_distribution/operator()/.
                 * [Accessed: 17-Apr-2021]. */
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine random_generator(seed);
        std::uniform_real_distribution<double> distribution(0, 1);
        // above random number generation is changed based on the example of /++ reference.com

        //annealing flip position
        int pos_first_flip = rand() % DNA_sequence.size();
        int pos_second_flip = rand() % DNA_sequence.size();

        //annealing flip
        annealing_DNA_sequence[pos_first_flip] *= -1;
        double probability = 0.5 + 1.0 / abs(pos_first_flip - pos_second_flip);

        double random_number = distribution(random_generator);

        if (random_number < probability) annealing_DNA_sequence[pos_second_flip] *= -1;

        //The effect of multithreading is not significant under small amount of DNA bases (even slower); therefore,
        //multithreading will only enable until the significant amount of DNA bases
        if (annealing_DNA_sequence.size() < multithreading_threshold) {
            annealing_hamiltonian = Hamiltonian_calculation(annealing_DNA_sequence);
        }else{
            multithreading_Hamiltonian_calculation(annealing_DNA_sequence);
        }


        if (annealing_hamiltonian < current_best_hamiltonian){
            current_best_hamiltonian = annealing_hamiltonian;
            DNA_sequence = annealing_DNA_sequence;
        }else{
            double random_number_for_annealing = distribution(random_generator);
            if (random_number_for_annealing < exp(-1 * Beta * (annealing_hamiltonian - current_best_hamiltonian))){
                current_best_hamiltonian = annealing_hamiltonian;
                DNA_sequence = annealing_DNA_sequence;
            }else{
                annealing_DNA_sequence = DNA_sequence;
            }
        }

        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> wall_clock = std::chrono::duration_cast<std::chrono::duration<double>>(
                current_time - begin_time);
        count++;

        //cout << count << " " << wall_clock.count() << endl;
        if (wall_clock.count() > 600) {
            cout << "Number of Annealing: " << count << endl;
            break;
        }
    }

    return annealing_DNA_sequence;
}

bool check_for_long_range_existence(const vector<int>& annealing_DNA_sequence){
    bool white_long_range = false, black_long_range = false;
    int count_consecutive_white = 0, count_consecutive_black = 0;
    int last_spin = -1;
    for (const auto& it_spin : annealing_DNA_sequence){
        if (it_spin == last_spin){
            if (it_spin == 1) {
                count_consecutive_black ++;
                if (count_consecutive_black == consecutive_number) black_long_range = true;
            }
            else {
                count_consecutive_white ++;
                if (count_consecutive_white == consecutive_number) white_long_range = true;
            }
        }else {
            if (it_spin == 1) count_consecutive_black = 0;
            else count_consecutive_white = 0;
        }

        if (black_long_range && white_long_range){
            return true;
        }

        last_spin = it_spin;
    }
    return false;

}