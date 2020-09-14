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

#define MOD 1000000007

int k;

int mem[100100], psum[100100] = {0};

int solve(int len) {
    if (len == k) {
        return 2;
    }
    if (len < k) {
        return 1;
    }

    if (mem[len] != -1) {
        return mem[len];
    }

    int ans = 0;

    ans = (ans + solve(len - k)) % MOD;
    ans = (ans + solve(len - 1)) % MOD;

    mem[len] = ans;

    return ans;
}

int main() {

    memset(mem, -1, 100100 * sizeof(int));



    int t, a, b;
    cin >> t >> k;

    for (int i = 1; i <= 100000; i++) {
        psum[i] = ((long long) psum[i - 1] + solve(i)) % MOD;
    }

    while (t--) {
        cin >> a >> b;
        int ans = psum[b] - psum[a - 1];
        if (ans < 0) ans += MOD;
        cout << ans << endl;
    }
}