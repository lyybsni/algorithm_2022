#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief Multiple Alignment.
 * The space actually is storing the data in a linear format, rather than n-d array.
 * However, to deal with higher level (4, 5, ...), the generation of the permutation will be necessary,
 * and the problem will grow in polinomial complexity, i.e. O(n^d), which is not acceptable though.
 */

int pointSpace[100005] = {0};
int backtrack[100005] = {0};

long getIndex(int x, int y, int z) {
    return 10000 * x + 100 * y + z;
}

void solve(string a, string b, string c, int x, int y, int z) {

    int current = pointSpace[getIndex(x, y, z)];
    if (pointSpace[getIndex(x, y, z-1)] > current) {
        current = pointSpace[getIndex(x, y, z-1)];
        backtrack[getIndex(x, y, z)] = 2;
    }
    
    if (pointSpace[getIndex(x, y-1, z)] > current) {
        current = pointSpace[getIndex(x, y-1, z)];
        backtrack[getIndex(x, y, z)] = 3;
    }
    
    if (pointSpace[getIndex(x-1, y, z)] > current) {
        current = pointSpace[getIndex(x-1, y, z)];
        backtrack[getIndex(x, y, z)] = 4;
    } 
    
    if (pointSpace[getIndex(x, y-1, z-1)] > current) {
        current = pointSpace[getIndex(x, y-1, z-1)];
        backtrack[getIndex(x, y, z)] = 5;
    }

    if (pointSpace[getIndex(x-1, y-1, z)] > current) {
        current = pointSpace[getIndex(x-1, y-1, z)];
        backtrack[getIndex(x, y, z)] = 6;
    }

    if (pointSpace[getIndex(x-1, y, z-1)] > current) {
        current = pointSpace[getIndex(x-1, y, z-1)];
        backtrack[getIndex(x, y, z)] = 7;
    }
    
    if ((a[x-1] == b [y-1] && b[y-1] == c[z-1]) || pointSpace[getIndex(x - 1, y - 1, z - 1)] >= current){
        current = pointSpace[getIndex(x-1, y-1, z-1)] + (a[x-1] == b [y-1] && b[y-1] == c[z-1]);
        backtrack[getIndex(x, y, z)] = 1;       // hit
    }

    pointSpace[getIndex(x, y, z)] = current;
}

string* backtrackResult(string a, string b, string c) {
    int x = a.size(), y = b.size(), z = c.size();

    string result_a = "", result_b = "", result_c = "";
    while (x > 0 || y > 0 || z > 0) {
        switch (backtrack[getIndex(x, y, z)]) {
        case 1:
            result_a = a[x - 1] + result_a;
            result_b = b[y - 1] + result_b;
            result_c = c[z - 1] + result_c;
            x--;
            y--;
            z--;
            break;
        case 6:
            result_a = a[x - 1] + result_a;
            result_b = b[y - 1] + result_b;
            result_c = "_" + result_c;
            x--;
            y--;
            break;
        case 7:
            result_a = a[x - 1] + result_a;
            result_b = "_" + result_b;
            result_c = c[z - 1] + result_c;
            x--;
            z--;
            break;
        case 5:
            result_a = "_" + result_a;
            result_b = b[y - 1] + result_b;
            result_c = c[z - 1] + result_c;
            y--;
            z--;
            break;
        case 4:
            result_a = a[x - 1] + result_a;
            result_b = "_" + result_b;
            result_c = "_" + result_c;
            x--;
            break;
        case 2:
            result_a = "_" + result_a;
            result_b = "_" + result_b;
            result_c = c[z - 1] + result_c;
            z--;
            break;
        case 3:
            result_a = "_" + result_a;
            result_b = b[y - 1] + result_b;
            result_c = "_" + result_c;
            y--;
            break;

        } 
    }

    return new string[3] {result_a, result_b, result_c};
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 100005; i++) {
        pointSpace[i] = 0;
    }

    for (int i = 0; i <= 10; i++) {
        backtrack[getIndex(i, 0, 0)] = 4;
        backtrack[getIndex(0, i, 0)] = 3;
        backtrack[getIndex(0, 0, i)] = 2;

        for (int j = 0; j <= 10; j++) {
            backtrack[getIndex(i, j, 0)] = 6;
            backtrack[getIndex(0, i, j)] = 5;
            backtrack[getIndex(j, 0, i)] = 7;
        }
    }

    int x = a.size(), y = b.size(), z = c.size();
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                solve(a, b, c, i, j, k);
            }
        }
    }

    string* output = backtrackResult(a, b, c);
    std::cout << pointSpace[getIndex(x, y, z)] << endl;
    std::cout << output[0] << endl << output[1] << endl << output[2] << endl;

    return 0;
}