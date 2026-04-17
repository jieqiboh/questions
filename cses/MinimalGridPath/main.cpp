#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>
using ll = long long;
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <ranges>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> grid(n);
    for (auto& row : grid) std::cin >> row;
    std::vector<std::pair<int, int>> positions{{0, 0}};
    while (!positions.empty()) {
        auto newEnd= unique(positions.begin(), positions.end());
        positions.erase(newEnd, positions.end());
        char minc = 'z';
        for (auto &p : positions) {
            char c = grid[p.first][p.second];
            if (c < minc) minc = c;
        }
        std::cout << minc;
        decltype(positions) nextPositions;
        for (auto [r, c] : positions)
            if (grid[r][c] == minc) {
                if (r + 1 < n) nextPositions.emplace_back(r + 1, c);
                if (c + 1 < n) nextPositions.emplace_back(r, c + 1);
            }
        positions = std::move(nextPositions);
    }
}
