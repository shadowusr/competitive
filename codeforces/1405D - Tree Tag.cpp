#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

// Returns a vector of distances to all other vertices from the given vertex.
vector<int> bfsDistance(int vertex, vector<vector<int>> g) {
    vector<int> result(g.size(), 0);
    unordered_set<int> visited;

    // A queue of pairs. First element is vertex, the second is distance.
    queue<pair<int, int>> q;
    q.push({vertex, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (visited.find(curr.first) != visited.end()) {
            continue;
        }
        result[curr.first] = curr.second;
        visited.insert(curr.first);
        for (auto adjacent : g[curr.first]) {
            if (visited.find(adjacent) != visited.end()) {
                continue;
            }
            q.push({adjacent, curr.second + 1});
        }
    }

    return result;
}

int main() {
    int t, a, b, ad, bd, n, tmp1, tmp2;
    vector<vector<int>> tree;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> ad >> bd;
        tree.clear();
        for (int i = 0; i <= n; i++) {
            tree.push_back(vector<int>());
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> tmp1 >> tmp2;
            tree[tmp1].push_back(tmp2);
            tree[tmp2].push_back(tmp1);
        }

        int aliceToBobDistance = bfsDistance(a, tree)[b];
        // In this case alice can get to bob in the first turn
        if (aliceToBobDistance <= ad) {
            cout << "Alice\n";
            continue;
        }

        // We imply that a tree radius is a sum of two largest distances starting from any node.
        auto tmpDistances = bfsDistance(1, tree);
        int farthestFromFirst = distance(tmpDistances.begin(), max_element(tmpDistances.begin(), tmpDistances.end()));
        tmpDistances = bfsDistance(farthestFromFirst, tree);

        int radius = *max_element(tmpDistances.begin(), tmpDistances.end());
        // In this case alice can go to the centre of the tree and then reach every vertex in one turn
        if (ad * 2 >= radius) {
            cout << "Alice\n";
            continue;
        }

        if (bd > 2 * ad) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}
