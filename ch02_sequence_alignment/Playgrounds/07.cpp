#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Edit distance.
 * 
 * Same to the global alignment, where the case is the award = 0, miss = 1, gap = 1.
 * Only need to calculate the number of hyphens and missing items and output.
 */

int point[1005][1005] = {0};
int backtrack[1005][1005] = {0};

// simplify the comparison
bool compareAndSwap(int& from, int& to) {
    if (from < to) {
        int temp = from;
        from = to;
        to = temp;
        return true;
    }
    return false;
}

// four states moving
void solve(const string a, const string b, int x, int y) {
    int current = INT_MIN;

    if (a[x - 1] == b[y - 1]) {
        int p1 = point[x - 1][y - 1] + 1;
        if (compareAndSwap(current, p1)) {
            backtrack[x][y] = 1;
        }
    } else {
        int p2 = point[x - 1][y - 1] - 1;
        if (compareAndSwap(current, p2)) {
            backtrack[x][y] = 2;
        }
    }

    int p3 = point[x - 1][y] - 1;
    if (compareAndSwap(current, p3)) {
        backtrack[x][y] = 3;
    }

    int p4 = point[x][y - 1] - 1;
    if (compareAndSwap(current, p4)) {
        backtrack[x][y] = 4;
    }

    point[x][y] = current;
}

int backtrackResult(const string a, const string b) {
    int x = a.size(), y = b.size();

    int result = 0;
    while (x > 0 || y > 0) {
        result++;
        if (backtrack[x][y] == 1) {
            x--;
            y--;
            result--;
        } else if (backtrack[x][y] == 2) {
            x--;
            y--;
        } else if (backtrack[x][y] == 4) {
            y--;
        } else {
            x--;
        }
    }

    return result;
}

int main() {
    // cin >> award >> miss >> gap;

    string a, b;
    cin >> a >> b;

    int x = a.size(), y = b.size();

    // noted there is always a deduction for blank case
    for (int i = 1; i <= x; i++) {
        point[i][0] = 1 * i * -1;
        backtrack[i][0] = 3;
    }
    for (int i = 1; i <= y; i++) {
        point[0][i] = 1 * i * -1;
        backtrack[0][i] = 4;
    }

    // do what we do in the LCS problem
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            solve(a, b, i, j);
        }
    }

    // cout << point[x][y] << endl;
    
    int bac = backtrackResult(a, b);
    cout << bac << endl ;

    return 0;
}