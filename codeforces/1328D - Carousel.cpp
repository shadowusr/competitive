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
    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;
        vector<int> t(k), r(k);
        int c = 0, minC = 0;
        bool opt = false;
        bool allTheSame = true;
        for (int i = 0; i < k; i++) {
            cin >> t[i];

            if (i > 0 && t[i - 1] == t[i] && k % 2 && !opt) {
                opt = true;
            } else {
                c = !c;
                minC = max(minC, c);
            }
            if (i > 0 && t[i - 1] != t[i]) {
                allTheSame = false;
            }
            r[i] = c + 1;
        }
        if (k % 2 && t[0] != t[k - 1] && t[k - 2] != t[k - 1] && r[k - 2] != r[0]) {
            r[k - 1] = 3;
            minC = 2;
        }
        if (allTheSame) {
            cout << 1 << endl;
        } else {
            cout << minC + 1 << endl;
        }
        for (auto item : r) {
            if (allTheSame) {
                cout << "1 ";
            } else {
                cout << item << " ";
            }
        }
        cout << endl;
    }
}