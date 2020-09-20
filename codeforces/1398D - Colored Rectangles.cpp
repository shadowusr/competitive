#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

// Idea: solve for prefixes of arrays, i.e. dp state is defined by 3 indexes. solve(r, g, b) = max ans for first r, g, b, elements respectively

int mem[210][210][210] = {0};

vector<int> rv, gv, bv;

int solve(int r, int g, int b) {
    if (mem[r + 1][g + 1][b + 1] > 0) {
        return mem[r + 1][g + 1][b + 1];
    }
    if ((r < 0) + (g < 0) + (b < 0) > 1) { // only one number left
        return 0;
    }
    if (r < 0) {
        mem[r + 1][g + 1][b + 1] = gv[g] * bv[b] + solve(r, g - 1, b - 1);
        return mem[r + 1][g + 1][b + 1];
    }
    if (g < 0) {
        mem[r + 1][g + 1][b + 1] = rv[r] * bv[b] + solve(r - 1, g, b - 1);
        return mem[r + 1][g + 1][b + 1];
    }
    if (b < 0) {
        mem[r + 1][g + 1][b + 1] = rv[r] * gv[g] + solve(r - 1, g - 1, b);
        return mem[r + 1][g + 1][b + 1];
    }

    int ans = 0;

    ans = max(ans, rv[r] * gv[g] + solve(r - 1, g - 1, b));
    ans = max(ans, rv[r] * bv[b] + solve(r - 1, g, b - 1));
    ans = max(ans, gv[g] * bv[b] + solve(r, g - 1, b - 1));

    mem[r + 1][g + 1][b + 1] = ans;
    return mem[r + 1][g + 1][b + 1];
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    rv = vector<int>(r);
    gv = vector<int>(g);
    bv = vector<int>(b);
    for (int i = 0; i < r; i++) {
        cin >> rv[i];
    }
    for (int i = 0; i < g; i++) {
        cin >> gv[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> bv[i];
    }

    sort(rv.begin(), rv.end());
    sort(gv.begin(), gv.end());
    sort(bv.begin(), bv.end());

    cout << solve(r - 1, g - 1, b - 1) << endl;
}
