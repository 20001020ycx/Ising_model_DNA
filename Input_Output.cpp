//
// Created by ycx on 2021-06-28.
//

#include "Input_Output.h"
#include "utility.h"


vector<int> digitalization(){
    vector<int> DNA_sequence;
    ifstream import_txt;
    import_txt.open(source_path);
    string temp_sequence;

    if (import_txt.is_open()){
        while (!import_txt.eof()) {
            string temp;
            import_txt >> temp;
            temp_sequence += temp;
            import_txt.ignore();
        }
    }else{
        cout << "file import fails" << endl;
    }

    for (auto & i : temp_sequence){
        if (i == 'a' || i == 't') DNA_sequence.push_back(AT_base);
        else DNA_sequence.push_back(CG_base);
    }

    return DNA_sequence;
}

void output_file (const vector<int>& annealing_DNA_sequence, const string& file_dest){
    ofstream output_file;
    output_file.open(file_dest);
    string temp_output;
    for (auto & i : annealing_DNA_sequence){
        if (i == 1) temp_output += '1';
        else temp_output += '0';
    }
    output_file << temp_output;
}

void output_message(const vector<int>& annealing_DNA_sequence, const int& count){
    cout << "Current Hamiltonian: " << Hamiltonian_calculation(annealing_DNA_sequence) << endl;
    //cout << "Number of Annealing: " << count << endl;
}