#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int end;

    Activity(int s, int e) : start(s), end(e) {}
};

bool compare(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Activity> activities;

    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        activities.push_back(Activity(s, t));
    }

    sort(activities.begin(), activities.end(), compare);

    int count = 0;
    int lastEndTime = 0;

    for(int i = 0; i < n; i++) {
        if(activities[i].start >= lastEndTime) {
            count++;
            lastEndTime = activities[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
