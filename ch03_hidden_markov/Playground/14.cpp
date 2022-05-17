#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

string ignored;

/**
 * @brief HMM probability.
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

double probablity(string path, map<string, map<string, double> > matrix) {
    int size = matrix.size();

    double result = 1/((double) size);

    for (int i = 0; i < path.size() - 1; i++) {
        // to deal the character into string..
        // very stupid method here lol
        string tokenFrom = string(new char[2]{path[i]});
        string tokenTo = string(new char[2]{path[i+1]});
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

    cin >> ignored;

    vector<string> list = tokens(states);
    map<string, map<string, double> > matrix;

    for (auto token: list) {
        matrix[token] = map<string, double>();
    }

    // input for the first line
    cin.ignore();
    cin.getline(states, 150);

    // input for the matrix
    for (int i = 0; i < list.size(); i++) {
        cin.getline(states, 150);

        vector<string> newlist = tokens(states);
        
        for (int j = 1; j < newlist.size(); j++) {
            matrix[list[i]][list[j-1]] = stod(newlist[j]);
        }
    }

    /*
    for (auto i: matrix) {
        map<string, double> temp = i.second;
        for(auto j: temp) {
            cout << i.first << " " << j.first << " " << j.second << endl; 
        }
    }
    */

    cout << probablity(path, matrix) << endl;

    return 0;
}