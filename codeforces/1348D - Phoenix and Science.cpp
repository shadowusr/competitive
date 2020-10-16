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

/*
 Observation: we don't care about mass of bacteria at all.
 During each night we can increase total count by some number in range [current number of bacterias; current number of bacterias * 2].
 Therefore an optimal solution is to split all bacterias each night until we can do that and carefully handle the end of this process.
 This idea can be expressed with use of the following example.
 Test: 29
 Changes for each night: (1) +2 +4 +8 +14
 Bacteria splits:         -   1  2  4  6
 */

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        int grate = 1; // current growth rate
        int cnt = 1;
        vector<int> ans;
        while (true) {
            if (n - cnt >= grate && n - cnt <= grate << 1) {
                // cout << (n - cnt - grate) << endl;
                ans.push_back(n - cnt - grate);
                break;
            }
            grate <<= 1;
            if (cnt + grate * 2 > n) {
                int rest = n - cnt;
                int tmpGrate = rest / 2 - grate / 2;
                // cout << rest / 2 << " " << rest / 2 + (rest % 2) << endl;

                // cout << tmpGrate << " " << (rest % 2) << endl;
                ans.push_back(tmpGrate);
                ans.push_back(rest % 2);
                break;
            }
            // cout << (grate >> 1) << " ";
            ans.push_back(grate >> 1);
            cnt += grate;
        }

        cout << ans.size() << endl;
        for (auto item : ans) {
            cout << item << " ";
        }
        cout << endl;
    }
}