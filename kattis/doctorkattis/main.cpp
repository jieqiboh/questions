#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

#define umap unordered_map

struct sortDesc {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs>rhs;
    }
};

int main() {
    umap<string, pair<int, int>> cats; // name, id, infection level
    map<int, map<int, string>, sortDesc> q; // infection lvl, id, name

    int num; cin >> num; cin.ignore();

    int id = 0;
    while (num--) {
        ios::sync_with_stdio(false); cin.tie(NULL);

        int op; cin >> op;

        string name; int value;
        if (op == 0) { // Arrive at Clinic
            cin >> name >> value;
            cats.insert({name, make_pair(id, value)});

            q[value].insert(make_pair(id, name));
            id++;
        } else if (op == 1) { // Update Infection Level
            cin >> name >> value;

            int tmpId = cats[name].first;
            int tmpInfectionlvl = cats[name].second;
            cats[name].second = tmpInfectionlvl + value; // update cats entry
            q[tmpInfectionlvl].erase(tmpId); // erase entry from tmpInfectionLvl
            if (q[tmpInfectionlvl].empty()) {
                q.erase(tmpInfectionlvl);
            }

            q[tmpInfectionlvl+value].insert(make_pair(tmpId, name));
        } else if (op == 2) { // Treated
            cin >> name;
            int tmpId = cats[name].first;
            int tmpInfectionlvl = cats[name].second;
            cats.erase(name);
            q[tmpInfectionlvl].erase(tmpId);

            if (q[tmpInfectionlvl].empty()) {
                q.erase(tmpInfectionlvl);
            }
        } else if (op == 3) {
            if (q.empty()) {
                cout << "The clinic is empty" << endl;
            } else {
                auto& x = q.begin()->second;

                cout << x.begin()->second << endl;
            }


        }
    }
    return 0;
}

