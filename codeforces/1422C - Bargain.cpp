#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int main() {
    string n;
    long long ns;
    cin >> n;
    ns = n.size();
    long long ans = 0;
    long long power = 1;

    for (long long i = ns - 1; i > 0; i--) {
        // removing from the start
        ans = ((i * (i + 1) / 2) % MOD * ((n[i] - '0') * power) % MOD + ans) % MOD;

        power = (power * 10) % MOD;
    }

    long long k = 0;
    power = 1;
    for (long long i = ns - 2; i >= 0; i--) {
        // removing from the end
        k = (power * (ns - i - 1) + k) % MOD;
        ans = (k * (n[i] - '0') + ans) % MOD;

        power = (power * 10) % MOD;
    }

    cout << ans << endl;
}

