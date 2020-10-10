#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

/*
 D. Returning Home
 Solution:
 It's clear that if we build a graph by connecting start, end and all teleports together and run dijkstra, we'll get an answer. Weights of edges are computed
 as min between two option: travel by x or travel by y. Weights between the last point and others are computed differently, because we can't teleport there and
 have to go through the whole path.

 Now, we need to optimise this approach. It's sufficient to connect each vertex only with up to 4 nearest neighbors by x and y (nearest from the top, bottom, left and right).
 Also, it's easier not to include end point in the graph, because we can't teleport there and therefore can't consider it 'nearest' by looking only at its coords.
 The overall algorithm looks as follows:
 1. Build a graph consisting of start and teleports as vertices and connecting up to 4 nearest vertices.
 2. Find min distances between the start point and all teleports using Dijkstra.
 3. Find an answer by iterating over all vertices and computing the distance between them and the end.
 */

using namespace std;

pair<int, int> st, en, tmp;
vector<pair<int, int> >  ys, xs;
unordered_map<int, int> ym, xm;

int dist(int a, int b) {
    return min(abs(xs[xm[a]].first - xs[xm[b]].first), abs(ys[ym[a]].first - ys[ym[b]].first));
}

bool alreadyAdded(const vector<pair<int, int> > &vv, int item) {
    for (auto tt : vv) {
        if (tt.first == item) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    cin >> st.first >> st.second >> en.first >> en.second;

    // first means coordinate, second vertex
    xs.emplace_back(st.first, 0);
    ys.emplace_back(st.second, 0);

    for (int i = 0; i < m; i++) {
        cin >> tmp.first >> tmp.second;
        xs.emplace_back(tmp.first, i + 1);
        ys.emplace_back(tmp.second, i + 1);
    }
    sort(xs.begin(), xs.end(), [](auto a, auto b) {return a.first < b.first;});
    sort(ys.begin(), ys.end(), [](auto a, auto b) {return a.first < b.first;});

    for (int i = 0; i < xs.size(); i++) {
        ym[ys[i].second] = i;
        xm[xs[i].second] = i;
    }

    // first - vertex, second - weight
    vector<vector<pair<int, int> > > g(m + 1);
    // Building a graph
    for (int i = 0; i < m + 1; i++) {
        int xpos = xm[i], ypos = ym[i];
        if (xpos > 0) g[i].push_back({xs[xpos - 1].second, dist(i, xs[xpos - 1].second)});
        if (xpos < xs.size() - 1 && !alreadyAdded(g[i], xs[xpos + 1].second)) g[i].push_back({xs[xpos + 1].second, dist(i, xs[xpos + 1].second)});
        if (ypos > 0 && !alreadyAdded(g[i], ys[ypos - 1].second)) g[i].push_back({ys[ypos - 1].second, dist(i, ys[ypos - 1].second)});
        if (ypos < ys.size() - 1 && !alreadyAdded(g[i], ys[ypos + 1].second)) g[i].push_back({ys[ypos + 1].second, dist(i, ys[ypos + 1].second)});
    }


    // Now just dijkstra on this graph
    vector<int> d(m + 1, numeric_limits<int>::max());
    vector<bool> used(m + 1, false);
    d[0] = 0;
    auto comp = [](pair<int, int> a, pair<int, int> b) { return a.second >= b.second; }; // first is vertex, second is distance
    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> q(comp);
    q.push({0, 0});
    for (int i = 0; i < m + 1; i++) {
        /*int curr = -1;
        for (int j = 0; j < m + 1; j++) { // here we are looking for an unvisited vertex with min distance
            if (used[j]) continue;
            if (curr == -1 || d[curr] > d[j]) curr = j;
        }*/
        while (!q.empty() && used[q.top().first]) q.pop();
        if (q.empty()) break;
        int curr = q.top().first;

        for (auto item : g[curr]) {
            if (d[item.first] > d[curr] + item.second) {
                d[item.first] = d[curr] + item.second;
                q.push({item.first, d[item.first]});
            }
        }
        used[curr] = true;
    }

    int minD = numeric_limits<int>::max();
    for (int i = 0; i < m + 1; i++) {
        minD = min(minD, d[i] + abs(xs[xm[i]].first - en.first) + abs(ys[ym[i]].first - en.second));
    }

    cout << minD;
}


/*
84 5
67 59 41 2
39 56
7 2
15 3
74 18
22 7
 */

/*
 100 5
 1 1 4 3
 5 1
 5 6
 2 6
 2 3
 4 3
Ans: 0

92 3
92 71 4 11
51 90
36 46
1 6
Ans: 68
 */