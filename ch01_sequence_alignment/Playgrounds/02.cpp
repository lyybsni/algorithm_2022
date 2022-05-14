#include <iostream>
#include <string.h>
using namespace std;

int map[25][25] = {0};

/**
 * @brief Solution 1.
 * Compare the two choices from each of the direction.
 * The complexity is O(mn), which is already the optimal solution in this situation.
 */
void solve(int x, int y, int** down, int** right) {
    int result = map[x][y];
    if (x > 0) {
        if (down[x-1][y] + map[x-1][y] > result) {
            result = down[x-1][y] + map[x-1][y];
        }
    }
    if (y > 0) {
        if (right[x][y-1] + map[x][y-1] > result) {
            result = right[x][y-1] + map[x][y-1];
        }
    }
    map[x][y] = result;
}

int main() {

    // deal with inputs
    int m, n;
    cin >> n >> m;

    int** down = new int*[n];
    for(int i = 0; i < 25; i++) {
        down[i] = new int[25];
        for(int j = 0; j < 25; j++) {
            down[i][j] = 0;
        }
    }

    int** right = new int*[25];
    for(int i = 0; i < 25; i++) {
        right[i] = new int[25];
        for(int j = 0; j < 25; j++) {
            right[i][j] = 0;
        }
    }

    // feed in the real data
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m+1; j++) {
            cin >> temp;
            down[i][j] = temp;
        }
    }

    string ignored;
    cin >> ignored;

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m; j++) {
            cin >> temp;
            right[i][j] = temp;
        }
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            solve(i, j, down, right);
        }
    }

    cout << map[n][m] << endl;
    
    return 0;
}