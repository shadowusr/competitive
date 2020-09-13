#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <iomanip>

#define MOD 1000000007

using namespace std;

int n, k, d;

int mem[110][2];

int solve(int sum, bool valid) {
    if (mem[sum][valid] != -1) {
        return mem[sum][valid];
    }
    if (sum == 0) {
        mem[sum][valid] = valid;
        return valid;
    }

    int ans = 0;
    for (int i = 1; i <= min(k, sum); i++) {
        ans = (ans + solve(sum - i, valid || (i >= d))) % MOD;
    }

    mem[sum][valid] = ans;
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 110; i++) {
        mem[i][0] = mem[i][1] = -1;
    }

    cin >> n >> k >> d;
    cout << solve(n, false) << endl;
}