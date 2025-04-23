#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> towerTops;

    for (int i = 0; i < n; ++i) {
        int cubeSize;
        cin >> cubeSize;

        auto it = towerTops.upper_bound(cubeSize);

        if (it != towerTops.end()) {
            towerTops.erase(it);
        }

        towerTops.insert(cubeSize);
    }

    cout << towerTops.size() << endl;

    return 0;
}