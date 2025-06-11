#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(int f) : ch(0), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        if(a->freq != b->freq) {
            return a->freq > b->freq;
        }
        return a->ch > b->ch;
    }
};

void calculateDepth(Node* root, map<char, int>& depths, int depth = 0) {
    if(!root) return;

    if(!root->left && !root->right) {
        depths[root->ch] = depth;
        return;
    }

    calculateDepth(root->left, depths, depth + 1);
    calculateDepth(root->right, depths, depth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if(s.length() == 1) {
        cout << 1 << endl;
        return 0;
    }

    map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }

    if(freq.size() == 1) {
        cout << s.length() << endl;
        return 0;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;


    for(auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }


    while(pq.size() > 1) {
        Node* x = pq.top(); pq.pop();
        Node* y = pq.top(); pq.pop();

        Node* z = new Node(x->freq + y->freq);
        z->left = x;
        z->right = y;

        pq.push(z);
    }
    Node* root = pq.top();
    map<char, int> depths;
    calculateDepth(root, depths);

    long long totalLength = 0;
    for(auto& p : freq) {
        char c = p.first;
        int f = p.second;
        totalLength += f * depths[c];
    }

    cout << totalLength << endl;

    return 0;
}
