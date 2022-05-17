#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

string ignored;

/**
 * @brief HMM probability with hidden path.
 * 
 * This question is about to use C++ I/O. No special calculation.
 */


vector<string> tokens(char tokenList[]) {
    string tokens = string(tokenList);
    
    vector<string> result;

    while (tokens.find(" ") != -1) {
        string sub = tokens.substr(0, tokens.find(" "));
        tokens = tokens.substr(tokens.find(" ") + 1);
        if (sub.size() > 0) {
            result.push_back(sub);
        }
    }
    result.push_back(tokens);

    return result;
}

double probablity(string pathFrom, string pathTo, map<string, map<string, double> > matrix) {
    int size = matrix.size();

    double result = 1;

    for (int i = 0; i < pathFrom.size(); i++) {
        // to deal the character into string..
        // very stupid method here lol
        string tokenFrom = string(new char[2]{pathFrom[i]});
        string tokenTo = string(new char[2]{pathTo[i]});
        result = result * matrix[tokenFrom][tokenTo];
    }

    return result;
}


int main() {

    string path;
    char states[150];
    
    cin >> path >> ignored;

    cin.ignore();
    cin.getline(states, 150);
    cin.ignore();

    vector<string> list = tokens(states);

    cin >> ignored;

    string path_new;
    cin >> path_new >> ignored;

    char states_new[150];    
    cin.ignore();
    cin.getline(states_new, 150);
    cin.ignore();

    vector<string> list_new = tokens(states_new);

    cin >> ignored;
    cout << "Ignored:" << ignored << endl;

    map<string, map<string, double> > matrix;

    // input for the first line
    cin.ignore();
    cin.getline(states_new, 150);

    // input for the matrix
    cout << list_new[0] << " " << list_new[1] << endl;
    for (int i = 0; i < list_new.size(); i++) {
        cin.ignore();
        cin.getline(states, 150);

        vector<string> newlist = tokens(states);
        for (auto k: newlist) {
            cout << k << endl;
        }
        
        for (int j = 0; j < newlist.size(); j++) {
            matrix[list[j]][list_new[i]] = stod(newlist[j]);
        }
    }

    cout << probablity(path, path_new, matrix) << endl;

    return 0;
}