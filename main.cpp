
#include "utility.h"
#include "Input_Output.h"
#include "image.h"
#include "Ising_Procedure.h"

using namespace std;

//#define check_long_range_correlation
#define long_range_correlation_alpha
//#define test_alpha
#define test_beta

double Alpha = 1.0; // use alpha equals 1.0 to improve the efficiency of the annealing
                    // may result small degree of discrepancy
double Beta = 2.5;

int main() {

    vector<int> DNA_sequence = digitalization();
    output_file(DNA_sequence, source_digit);
    vector<int> annealing_DNA_sequence;
    long double current_best_hamiltonian = Hamiltonian_calculation(DNA_sequence);
    int count = 0;

    cout << "Original Hamiltonian: " << current_best_hamiltonian << endl;

#ifdef long_range_correlation_alpha
    annealing_DNA_sequence = annealing(DNA_sequence, current_best_hamiltonian);
#endif

#ifdef check_long_range_correlation
    #ifdef test_alpha
    for (; Alpha < 2.0; Alpha += 0.05) {
        annealing_DNA_sequence = annealing(DNA_sequence, current_best_hamiltonian);
        cout << "Hamiltonian of the current configuration: " << Hamiltonian_calculation(annealing_DNA_sequence) << endl;
        if (check_for_long_range_existence(annealing_DNA_sequence)) {
            cout << "correct Alpha is " << Alpha << endl;
            break;
        }
    }
    #endif

    #ifdef test_beta
    for (; Beta < 5.0; Beta += 0.5) {
        annealing_DNA_sequence = annealing(DNA_sequence, current_best_hamiltonian);
        cout << "Hamiltonian of the current configuration: " << Hamiltonian_calculation(annealing_DNA_sequence) << endl;
        if (check_for_long_range_existence(annealing_DNA_sequence)) {
            cout << "correct Beta is " << Beta << endl;
            break;
        }
    }
    #endif
#endif
    //generate output file
    output_file(annealing_DNA_sequence, output_path);

    //output messages
    output_message(annealing_DNA_sequence,count);

    //generate image
    generate_image(annealing_DNA_sequence);

    return 0;
}

