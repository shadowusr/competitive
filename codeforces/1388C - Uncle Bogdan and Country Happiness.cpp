#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;

int n, m, a, b;
vector<int> living, happ, needed, limit, happA, uhapA, used, parent; // happA = happy available in certain city, limit = total number of people we can get from the city, needed = total number of people needed for on city, i.e. people who will come through this city & those who live there
vector<vector<int>> g;

int dfs(int curr) {
    used[curr] = true;

    int cnt = living[curr];
    for (auto item : g[curr]) {
        if (used[item]) continue;
        cnt += dfs(item);
    }
    needed[curr] = cnt;
    return cnt;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        living.clear(); living.resize(n);
        happ.clear(); happ.resize(n);
        needed.clear(); needed.resize(n);
        limit.clear(); limit.resize(n);
        happA.clear(); happA.resize(n);
        uhapA.clear(); uhapA.resize(n);
        used.clear(); used.resize(n);
        parent.clear(); parent.resize(n);

        g.clear();
        g.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> living[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> happ[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        dfs(0);
        used = vector<int>(n);

        queue<int> q;
        q.push(0);
        limit[0] = m - living[0];

        happA[0] = max(0, happ[0]) + abs(needed[0] - happ[0]) / 2;
        uhapA[0] = needed[0] - happA[0];

        bool err = false;
        if (needed[0] > m) {
            err = true;
        }
        while (!q.empty() && !err) {
            int curr = q.front();
            q.pop();
            used[curr] = true;

            for (auto item : g[curr]) {
                if (used[item]) continue;
                parent[item] = curr;
                q.push(item);
            }

            if (abs(happ[curr]) % 2 != needed[curr] % 2) { // parity mismatch
                err = true; break;
            }
            if (abs(happ[curr]) > needed[curr]) { // not enough people to make such score
                err = true; break;
            }
            happA[curr] = max(0, happ[curr]) + abs(needed[curr] - abs(happ[curr])) / 2;
            uhapA[curr] = needed[curr] - happA[curr];

            if (curr == 0) continue;

            int p = parent[curr];
            if (limit[p] - needed[curr] < 0) { // not enough people
                err = true; break;
            }
            limit[p] -= needed[curr];
            limit[curr] = needed[curr] - living[curr];

            happA[p] -= happA[curr];
            if (happA[p] < 0) {
                err = true; break;
            }
            if (uhapA[p] >= uhapA[curr]) {
                uhapA[p] -= uhapA[curr];
            } else if (happA[p] + uhapA[p] >= uhapA[curr]) {
                happA[p] -= uhapA[curr] - uhapA[p];
                uhapA[p] = 0;
            } else {
                err = true; break;
            }
        }
        if (err) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

