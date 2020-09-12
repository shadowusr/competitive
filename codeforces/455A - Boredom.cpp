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

unordered_map<int, int> m;

unsigned long long mem[100100];

unsigned long long solve(int i) {
    if (mem[i] != -1) {
        return mem[i];
    }
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return m[1];
    }
    mem[i] = max(solve(i - 1), solve(i - 2) + m[i] * (unsigned long long) i);
    return mem[i];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, tmp;
    cin >> n;

    memset(mem, -1, 100100 * sizeof(unsigned long long));

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (m.find(tmp) == m.end()) {
            m[tmp] = 0;
        }
        m[tmp]++;
    }

    cout << solve(100050);
}