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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool ab = false, ba = false;
    for (int i = 0; i < s.length() - 1; i++) { // case when AB goes before BA
        if (!ab && s[i] == 'A' && s[i + 1] == 'B') {
            ab = true;
            i++;
        } else if (ab && !ba && s[i] == 'B' && s[i + 1] == 'A') {
            ba = true;
        }
    }
    if (ab && ba) {
        cout << "YES\n";
        return 0;
    }

    ab = false, ba = false;
    for (int i = 0; i < s.length() - 1; i++) { // case when BA goes before AB
        if (!ba && s[i] == 'B' && s[i + 1] == 'A') {
            ba = true;
            i++;
        } else if (ba && !ab && s[i] == 'A' && s[i + 1] == 'B') {
            ab = true;
        }
    }

    if (ab && ba) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}