#include<bits/stdc++.h>
using namespace std;

struct Item {
    double value;
    double weight;
    double ratio;

    Item(double v, double w) : value(v), weight(w) {
        ratio = v / w;
    }
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<Item> items;

    for(int i = 0; i < N; i++) {
        double v, w;
        cin >> v >> w;
        items.push_back(Item(v, w));
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    double remainingWeight = W;

    for(int i = 0; i < N; i++) {
        if(remainingWeight <= 0) break;

        if(items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            double fraction = remainingWeight / items[i].weight;
            totalValue += items[i].value * fraction;
            remainingWeight = 0;
        }
    }

    cout << fixed << setprecision(6) << totalValue << endl;

    return 0;
}
