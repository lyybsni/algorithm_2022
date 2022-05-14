#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

/**
 * @brief Solution 1.
 * Including a memorization array for reducing the computation.
 * Build the optimal solution from the bottom to the top, which will cost a complexity of
 * O(m*n), where m is the size of the primes, and the n is the money to be queried.
 * 
 * The enhancement can be, to build the tree from the top to the bottom. Though,
 * in the worst situation the complexity is also O(m*n), on average the searching tree will be
 * thinner.
 */
int* resultList = new int[1000];

void getMinimumSize(int target, vector<int> sources) {
    int current = resultList[target];

    for(auto source: sources) {
        if (target >= source) {
            // compare and swap
            if (resultList[target - source] + 1 < current) {
                current = resultList[target - source] + 1;
            }
        }
    }

    resultList[target] = current;
}

int main() {
    int money;
    cin >> money;

    string primes;
    cin >> primes;

    vector<int> primeList;

    // deal with the input
    while (primes.find(",") != -1) {
        primeList.push_back(stoi(primes.substr(0, primes.find(","))));
        primes = primes.substr(primes.find(",") + 1);
    }
    primeList.push_back(stoi(primes));

    // initialization for the memorization array
    resultList[0] = 0;
    for (int i = 1; i < 1000; i++) {
        resultList[i] = 1001;
    }

    // feed in the solve method
    for (int i = 0; i <= money; i++) {
        getMinimumSize(i, primeList);
    }
    
    // output the result in a line
    cout << resultList[money] << endl;

    return 0;
}