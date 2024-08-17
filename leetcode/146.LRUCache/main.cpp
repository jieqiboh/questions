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
#include <list>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class LRUCache {
    unordered_map<int, list<pair<int,int>>::iterator> m; // maps keys to iterator pointing to their node in the dll
    list<pair<int, int>> dll; // doubly linked list, with most recently used at the front, key and value
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // ret val of key if exists, else -1
        // set key to MRU
        if (m.find(key) == m.end()) { // doesn't exist
            return -1;
        } else {
            // move the node to the front of the dll
            dll.splice(dll.begin(), dll, m[key]);
            return m[key]->second;
        }
    }

    void put(int key, int value) {
        // if key already exists, move to front of dll and update m
        if (m.find(key) != m.end()) {
            dll.splice(dll.begin(), dll, m[key]);
            m[key]->second = value;
            return;
        }

        // if key doesn't exist and capacity full
        if (dll.size() == capacity) {
            // remove LRU from m and dll, and insert new key in m and dll
            int keyToRemove = dll.back().first;
            m.erase(keyToRemove);
            dll.pop_back();
        }
        // just insert in m and dll
        dll.emplace_front(key, value);
        m[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    fast();

    return 0;
}

