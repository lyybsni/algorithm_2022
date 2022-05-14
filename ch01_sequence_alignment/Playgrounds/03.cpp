#include <iostream>
#include <string.h>
using namespace std;

int result[1005][1005] = {0};
int backtrace[1005][1005] = {0};

/**
 * @brief Solution 1.
 * 
 * Similar question with the grid question. The complexity is O(xy).
 * However, the result is not the same. To retreive all the LCSs, all paths should be found.
 */

void solve(string a, string b, int x, int y) {
    if (a[x-1] == b[y-1]) {
        result[x][y] = result[x-1][y-1] + 1;
        backtrace[x][y] = 1;
    } else if (result[x-1][y] > result[x][y-1]) {
        result[x][y] = result[x-1][y];
        backtrace[x][y] = 2;
    } else {
        result[x][y] = result[x][y-1];
        backtrace[x][y] = 3;
    }
}

string backtraceResult(string a, string b) {
    int x = a.size();
    int y = b.size();
    string result = "";

    while (backtrace[x][y] > 0) {
        if (backtrace[x][y] == 1) {
            result = a[x-1] + result;
            x -= 1;
            y -= 1;
        } else if (backtrace[x][y] == 2) {
            x -= 1;
        } else {
            y -= 1;
        }
    }

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;

    int x = a.size();
    int y = b.size();

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            solve(a, b, i, j);
        }
    }

    cout << backtraceResult(a, b) << endl;
}