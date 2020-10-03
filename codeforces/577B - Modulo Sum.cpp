#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <unordered_map>

using namespace std;

int main() {
    // const int MAX = 1010;
    int n, m, tmp;
    cin >> n >> m;
    vector<bool> sum(m, false);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;

        unordered_map<int, bool> used;
        if (!sum[tmp % m]) used[tmp % m] = true;

        sum[tmp % m] = true;
        for (int j = 0; j < m; j++) {
            if (!sum[j] || sum[(j + tmp) % m] || used[j]) continue;
            used[(j + tmp) % m] = true;
            sum[(j + tmp) % m] = true;
        }
        if (sum[0]) {
            cout << "YES\n";
            return 0;
        }
     }

    cout << "NO\n";
}

// This solution can be improved: https://codeforces.com/blog/entry/20226