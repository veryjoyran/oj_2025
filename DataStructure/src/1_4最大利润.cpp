#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n);

    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    int minR = R[0];
    int maxProfit = -1000;

    for (int i = 1; i < n; i++) {
        maxProfit = max(maxProfit, R[i] - minR);
        minR = min(minR, R[i]);
    }

    cout << maxProfit << endl;

    return 0;
}
