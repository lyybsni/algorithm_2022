#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

string welcome = "Please select the chapter to be checked: \n \
                    >> Enter 1 - for Chapter 1: Sequence Alignment \n";

string chapter1 = "Please select the question number to be checked: \n \
                    >> Enter 1 - for Coin \n \
                    >> Enter 2 - for Grid \n \
                    >> Enter 3 - for LCS \n \
                    >> Enter 4 - for DAG \n ";

string path = "../";
string chapter1_path = "ch01_sequence_alignment/";

int main() {
    cout << welcome;

    int chapter_selection;
    cin >> chapter_selection;

    string* ref;
    switch(chapter_selection) {
        case 1: cout << chapter1; ref = &chapter1_path;
        default: break;
    }

    int problem_selection;
    cin >> problem_selection;

    string filePrefix = (problem_selection < 10) ? string("0").append(to_string(problem_selection)) : to_string(problem_selection);

    ifstream inputInstream(path.append(*ref).append("Inputs/").append(filePrefix).append("txt"));
    ifstream outputInstream(path.append(*ref).append("Outputs/").append(filePrefix).append("txt"));

    /**
     * TODO:
     * @brief The main logic of create a new process to run the target executable.
     * The console input and output stream should be reached and used for comparison.
     */

    inputInstream.close();
    outputInstream.close();

}