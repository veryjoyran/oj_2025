#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> pos(n + 1);  
    
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    
    int ans = 1;  
    
    for(int i = 2; i <= n; i++) {
        if(pos[i] < pos[i - 1]) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}