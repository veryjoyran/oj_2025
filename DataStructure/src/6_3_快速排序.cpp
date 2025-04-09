#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<char> V(N);
vector<int> Num(N);
vector<int> order(N);
bool stable_flag = true;

int Partition(int p, int r) {
    int x = Num[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(Num[j] <= x) {
            i++;
            swap(Num[i], Num[j]);
            swap(V[i], V[j]);
            swap(order[i], order[j]);

        }
    }
    swap(Num[i+1], Num[r]);
    swap(V[i+1], V[r]);
    swap(order[i+1], order[r]);

    if(i+1 < r && Num[i+1] == Num[r] && order[i+1] > order[r]) {
        stable_flag = false;
    }
    return i+1;
}

void Quicksort(int p, int r) {
    if(p < r) {
        int q = Partition(p, r);
        Quicksort(p, q-1);
        Quicksort(q+1, r);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> V[i] >> Num[i];
        order[i] = i;
    }

    Quicksort(1, n);

    for(int i=2; i<=n; i++) {
        if(Num[i] == Num[i-1] && order[i] < order[i-1]) {
            stable_flag = false;
            break;
        }
    }

    cout << (stable_flag ? "Stable" : "Not stable") << endl;
    for(int i=1; i<=n; i++) {
        cout << V[i] << " " << Num[i] << endl;
    }
    return 0;
}