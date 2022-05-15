#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Affine Gap Problem.
 * 
 * This question is tricky in removing the extra edges from O(n^3) to O(n^2).
 * This solution has a strong assertions that the extension fee is lower or equal to the opening fee.
 * Since the "equality" condition on CAS part will choose a gap over a match.
 */

int point[1005][1005] = {0};
int backtrack[1005][1005] = {0};

int award, miss, gap, extension;

// simplify the comparison
bool compareAndSwap(int& from, int& to) {
    if (from <= to) {       // noted that, when we encounter a consecutive gap over a match
                            // using "equal" sign to avoid stopping a non-match
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
    if (backtrack[x-1][y] == 3) p3 += gap - extension;
    if (compareAndSwap(current, p3)) {
        backtrack[x][y] = 3;
    }

    int p4 = point[x][y - 1] - gap ;
    if (backtrack[x][y-1] == 4) p4 += gap - extension;
    if (compareAndSwap(current, p4)) {
        backtrack[x][y] = 4;
    }

    point[x][y] = current;
}

pair<string, string> backtrackResult(const string a, const string b) {
    int x = a.size(), y = b.size();

    string a_prime = "", b_prime = "";
    while (backtrack[x][y] != 0) {
        if (backtrack[x][y] < 3) {
            a_prime = a[x - 1] + a_prime;
            b_prime = b[y - 1] + b_prime;
            x--;
            y--;
        } else if (backtrack[x][y] == 4) {
            a_prime = '-' + a_prime;
            b_prime = b[y - 1] + b_prime;
            y--;
        } else {
            a_prime = a[x - 1] + a_prime;
            b_prime = '-' + b_prime;
            x--;
        }
    }

    return pair(a_prime, b_prime);
}

int main() {
    cin >> award >> miss >> gap >> extension;

    string a, b;
    cin >> a >> b;

    int x = a.size(), y = b.size();

    // noted there is always a deduction for blank case
    for (int i = 1; i <= x; i++) {
        point[i][0] = - gap + extension * (i-1) * -1;
        backtrack[i][0] = 3;
    }
    for (int i = 1; i <= y; i++) {
        point[0][i] = - gap + extension * (i-1) * -1;
        backtrack[0][i] = 4;
    }

    // do what we do in the LCS problem
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            solve(a, b, i, j);
        }
    }

    cout << point[x][y] << endl;
    pair<string, string> bac = backtrackResult(a, b);
    cout << bac.first << endl << bac.second << endl;

    return 0;
}