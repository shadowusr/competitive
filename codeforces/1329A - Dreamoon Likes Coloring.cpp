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

int main() {
    long long n, m;
    long long sum = 0;
    cin >> n >> m;
    vector<int> l(m);

    for (int i = 0; i < m; i++) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n) {
        cout << "-1\n";
        return 0;
    }

    vector<long long> suff(m, 0);
    suff[m - 1] = l[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suff[i] += suff[i + 1] + l[i];
    }

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        // cout << i + 1ull << " " << n - suff[i] + 1 << " " << suff[i] << endl;
        ans[i] = max(i + 1ll, n - suff[i] + 1);
        if (ans[i] + l[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
    }

    for (auto item : ans) {
        cout << item << " ";
    }
    cout << endl;
}
