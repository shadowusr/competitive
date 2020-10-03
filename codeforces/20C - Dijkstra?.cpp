#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pair<long long, long long> > > g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;
        b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    vector<long long> d(n, numeric_limits<long long>::max()), p(n, -1);
    vector<bool> used(n, false);

    d[0] = 0;

    auto comp = [](auto a, auto b) { return a.second > b.second; };
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, decltype(comp)> q(comp); // first - vertex, second - distance
    q.push({0, 0});

    for (int i = 0; i < n; i++) {
        // handling used vertices
        while (!q.empty() && used[q.top().first]) q.pop();
        if (q.empty()) break;

        long long curr = q.top().first;
        // looking for the unused vertex with min distance

        for (auto v : g[curr]) {
            if (used[v.first]) continue;
            if (d[curr] + v.second < d[v.first]) {
                d[v.first] = d[curr] + v.second;
                p[v.first] = curr;
                q.push({v.first, d[v.first]});
            }
        }
        used[curr] = true;
    }

    if (d[n - 1] == numeric_limits<long long>::max()) {
        cout << "-1\n";
    } else {
        vector<long long> ans;
        int curr = n - 1;
        while (p[curr] != -1) {
            ans.push_back(curr + 1);
            curr = p[curr];
        }
        ans.push_back(1);
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        };
    }
}