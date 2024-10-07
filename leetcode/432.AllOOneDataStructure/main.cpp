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
#include <list>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Node {
public:
    unordered_set<string> s;
    int val;
    Node(): val(-1), s(0){}
    Node(int x): val(x), s(0) {}
};

class AllOne {
    list<Node*> dll; // doubly linked list
    unordered_map<string, int> map;
public:
    AllOne() {}

    void inc(string key) {
        if (map.find(key) == map.end()) { // new string
            map[key] = 1;
            auto it = find_if(dll.begin(), dll.end(), [](Node* n) {
                return n->val == 1;
            });
            if (it == dll.end()) { // node 1 not found
                Node* newNode = new Node(1);
                newNode->s.insert(key);
                dll.push_front(newNode);
            } else {
                (*it)->s.insert(key);
            }
        } else { // existing string
            int prevVal = map[key];
            map[key]++;
            // find node containing key
            auto it = find_if(dll.begin(), dll.end(), [prevVal](Node* n) {
                return n->val == prevVal;
            });
            (*it)->s.erase(key);
            // find nextNode
            auto newit = find_if(dll.begin(), dll.end(), [prevVal](Node* n) {
                return n->val == prevVal + 1;
            });
            if (newit == dll.end()) { // not found
                Node* newNode = new Node(prevVal + 1);
                newNode->s.insert(key);
                dll.insert(next(it), newNode); // insert newNode after it
            } else {
                (*newit)->s.insert(key);
            }
            if ((*it)->s.empty()) dll.erase(it); // erase previous node if empty
        }
    }

    void dec(string key) {
        // key guaranteed to exist
        int prevVal = map[key];
        map[key]--;
        // find cur node that contains key
        auto it = find_if(dll.begin(), dll.end(), [prevVal](Node *n) {
            return n->val == prevVal;
        });
        (*it)->s.erase(key); // erase key from node
        if (prevVal - 1 == 0) { // if key value is now 0
            map.erase(key);
            if ((*it)->s.empty()) dll.erase(it); // delete cur node if it is empty after key removal
            return;
        }

        // otherwise move the key to node with prevVal - 1
        auto newit = find_if(dll.begin(), dll.end(), [prevVal](Node *n) {
            return n->val == prevVal - 1;
        });
        if (newit == dll.end()) { // not found
            Node* newNode = new Node(prevVal - 1);
            newNode->s.insert(key);
            if (it == dll.begin()) {
                dll.push_front(newNode);
            } else {
                dll.insert(it, newNode); // insert newNode before it
            }
        } else {
            (*newit)->s.insert(key);
        }
        if ((*it)->s.empty()) dll.erase(it); // delete cur node if it is empty after key removal
    }

    string getMaxKey() {
        if (dll.empty()) return "";
        return *dll.back()->s.begin();
    }

    string getMinKey() {
        if (dll.empty()) return "";
        return *dll.front()->s.begin();
    }

//    void print() {
//        cout << "Printing dll: " << "\n";
//        for (auto x : dll) {
//            cout << x->val << "\n";
//            for (string s : x->s) {
//                cout << s << " ";
//            }
//            cout << "\n";
//        }
//    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    fast();
    AllOne* obj = new AllOne();
//    obj->inc("hello");
//    cout << obj->getMaxKey() << "\n";
//    cout << obj->getMinKey() << "\n";
//    obj->inc("hello");
//    cout << obj->getMaxKey() << "\n";
//    cout << obj->getMinKey() << "\n";
//    obj->inc("leet");
//    cout << obj->getMaxKey() << "\n";
//    cout << obj->getMinKey() << "\n";
//    obj->dec("hello");
//    obj->dec("hello");
//    cout << obj->getMaxKey() << "\n";
//    cout << obj->getMinKey() << "\n";

//    free(obj);
//    obj = new AllOne();
//    obj->inc("a");
//    obj->inc("b");
//    obj->inc("b");
//    obj->inc("b");
//    obj->inc("b");
//    obj->dec("b");
//    obj->dec("b");
//    cout << obj->getMaxKey() << "\n"; // b
//    cout << obj->getMinKey() << "\n"; // a

    free(obj);
    obj = new AllOne();
    obj->inc("a");
    obj->print();
    obj->inc("b");
    obj->inc("b");
    obj->inc("c");
    obj->inc("c");
    obj->print();
    obj->inc("c");
    obj->dec("b");
    obj->dec("b");
    obj->dec("a");
    obj->print();
//    obj->dec("b");
//    obj->dec("b");
//    obj->dec("b");
//    cout << obj->getMaxKey() << "\n"; // c
//    cout << obj->getMinKey() << "\n"; // c

    return 0;
}

