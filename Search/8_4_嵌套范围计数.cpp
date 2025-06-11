#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
     vector<int> tree;
    int size;

    FenwickTree(int n) : size(n) {
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (++idx; idx <= size; idx += idx & -idx) { 
            tree[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) { 
            sum += tree[idx];
        }
        return sum;
    }

    int queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1); 
    }
};

struct Range {
    int left, right, original_idx;
};

int main() {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

    int n;
     cin >> n;

     vector<Range> ranges(n);
     vector<int> coords; 

    for (int i = 0; i < n; ++i) {
         cin >> ranges[i].left >> ranges[i].right;
        ranges[i].original_idx = i;
        coords.push_back(ranges[i].left);
        coords.push_back(ranges[i].right);
    }

     sort(coords.begin(), coords.end());
    coords.erase( unique(coords.begin(), coords.end()), coords.end());

     map<int, int> coord_to_compressed;
    for (int i = 0; i < coords.size(); ++i) {
        coord_to_compressed[coords[i]] = i; 
    }

    for (int i = 0; i < n; ++i) {
        ranges[i].left = coord_to_compressed[ranges[i].left];
        ranges[i].right = coord_to_compressed[ranges[i].right];
    }

    int max_compressed_coord = coords.size(); 

     vector<int> contains_count(n, 0);
     vector<int> contained_by_count(n, 0);

     vector<Range> sorted_ranges = ranges;

     sort(sorted_ranges.begin(), sorted_ranges.end(), [](const Range& a, const Range& b) {
        if (a.left != b.left) {
            return a.left < b.left;
        }
        return a.right > b.right;
    });

    FenwickTree ft_contains(max_compressed_coord);
    for (int i = n - 1; i >= 0; --i) {
        contains_count[sorted_ranges[i].original_idx] = ft_contains.query(sorted_ranges[i].right);
        ft_contains.update(sorted_ranges[i].right, 1);
    }


    FenwickTree ft_contained_by(max_compressed_coord);
    for (int i = 0; i < n; ++i) {

        contained_by_count[sorted_ranges[i].original_idx] = ft_contained_by.queryRange(sorted_ranges[i].right, max_compressed_coord - 1);
        ft_contained_by.update(sorted_ranges[i].right, 1);
    }

    for (int i = 0; i < n; ++i) {
         cout << contains_count[i] << (i == n - 1 ? "" : " ");
    }
     cout <<  endl;

    for (int i = 0; i < n; ++i) {
         cout << contained_by_count[i] << (i == n - 1 ? "" : " ");
    }
     cout <<  endl;

    return 0;
}
