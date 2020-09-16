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
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    if (a[2] / 2 > a[0] + a[1]) {
        cout << a[0] + a[1];
    } else {
        cout << (a[0] + a[1] + a[2]) / 3;
    }
}


/*
Table Decorations

You have r red, g green and b blue balloons. To decorate a single table for the banquet you need exactly three balloons. Three balloons attached to some table shouldn't have the same color. What maximum number t of tables can be decorated if we know number of balloons of each color?

Your task is to write a program that for given values r, g and b will find the maximum number t of tables, that can be decorated in the required manner.

Input
The single line contains three integers r, g and b (0 ≤ r, g, b ≤ 2·109) — the number of red, green and blue baloons respectively. The numbers are separated by exactly one space.

Output
Print a single integer t — the maximum number of tables that can be decorated in the required manner.

Examples
input
5 4 3
output
4
input
1 1 1
output
1
input
2 3 3
output
2

Solution
There are two cases:
1) If count of the certain color A divided by 2 outnumbers sum of all other balloons, it means that the optimal strategy is combining 2 balloons of this color A with other colors. We will run out of other colors sooner, than of color A.
2) Otherwise the answer is just (r + g + b) / 3. We can guarantee that such number is achievable because previous condition cuts off all impossible cases.
 */