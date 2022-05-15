#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Overlap Alignment.
 * 
 * The substrings to be considered are the tail substrings from s, and leading substrings from t.
 * Therefore, by using the "free-taxi" idea, the first line will be initialized as all 0s.
 */

int point[1005][1005] = {0};
int backtrack[1005][1005] = {0};

int award, miss, gap;

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
        int p1 = point[x - 1][y - 1] + award;
        if (compareAndSwap(current, p1)) {
            backtrack[x][y] = 1;
        }
    } else {
        int p2 = point[x - 1][y - 1] - miss;
        if (compareAndSwap(current, p2)) {
            backtrack[x][y] = 2;
        }
    }

    int p3 = point[x - 1][y] - gap;
    if (compareAndSwap(current, p3)) {
        backtrack[x][y] = 3;
    }

    int p4 = point[x][y - 1] - gap;
    if (compareAndSwap(current, p4)) {
        backtrack[x][y] = 4;
    }

    point[x][y] = current;
}

pair<string, string> backtrackResult(const string a, const string b, int target_x, int target_y) {
    int x = target_x, y = target_y;

    string a_prime = "", b_prime = "";
    while (x > 0 && y > 0) {
        if (backtrack[x][y] < 3) {
            a_prime = a[x - 1] + a_prime;
            b_prime = b[y - 1] + b_prime;
            x--;
            y--;
        } else if (backtrack[x][y] == 4) {
            a_prime = '-' + a_prime;
            b_prime = b[y - 1] + b_prime;
            y--;
        } else if (backtrack[x][y] == 3) {
            a_prime = a[x - 1] + a_prime;
            b_prime = '-' + b_prime;
            x--;
        }
    }

    return pair(a_prime, b_prime);
}

int main() {
    cin >> award >> miss >> gap;

    string a, b;
    cin >> a >> b;

    int x = a.size(), y = b.size();

    // still need to initialize the first column
    for (int i = 0; i <= y; i++) {
        point[0][i] = gap * i * -1;
    }

    // do what we do in the LCS problem
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            solve(a, b, i, j);
        }
    }

    int maxPoint = INT_MIN;
    int target_x = 0, target_y = 0;
    
    for (int j = 0; j <= y; j++) {      // avoid no output
        if (maxPoint <= point[x][j]) {
            target_x = x;
            target_y = j;
            maxPoint = point[x][j];
        }
    }

    cout << maxPoint << endl;
    
    pair<string, string> bac = backtrackResult(a, b, target_x, target_y);
    cout << bac.first << endl << bac.second << endl;

    return 0;
}