#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void Insert(list<int> &l, int num) {
    l.push_front(num);
}

void Delete(list<int> &l, int target) {
    auto it = find(l.begin(), l.end(), target);
    if (it != l.end()) {
        l.erase(it);
    }
}

void DeleteFirst(list<int> &l) {
    l.pop_front();
}

void DeleteLast(list<int> &l) {
    l.pop_back();
}

int main() {
    int n;
    cin >> n;
    list<int> l;

    while (n--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int num;
            cin >> num;
            Insert(l, num);
        } else if (command == "delete") {
            int num;
            cin >> num;
            Delete(l, num);
        } else if (command == "deleteFirst") {
            DeleteFirst(l);
        } else if (command == "deleteLast") {
            DeleteLast(l);
        }
    }

    bool first = true;
    for (int val : l) {
        if (!first) cout << " ";
        cout << val;
        first = false;
    }
    cout << endl;

    return 0;
}
