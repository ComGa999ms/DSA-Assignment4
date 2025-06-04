#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define vii vector<int>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;

Node* Insert(Node* root, int data) {
    if (root == NULL) return new Node(data);
    
    if (data <= root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    
    return root;
}

int n;
map<int, int> m;

void Magic(Node* root) {
    if (root == NULL) return;
    
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (q.size()) {
        auto [cur, pos] = q.front(); q.pop();
        
        if (m.find(pos) == m.end()) {
            m[pos] = cur->data;
        }
        if (cur->right) q.push(make_pair(cur->right, pos - 1));
        if (cur->left) q.push(make_pair(cur->left, pos + 1));
    }
}

void solve(void) {
    cin >> n;
    rep(i, 1, n) {
        int x; cin >> x;
        root = Insert(root, x);
    }
    
    Magic(root);

    vii res;
    for (auto T : m) res.push_back(T.se);

    sort(all(res));
    for (auto T : res) cout << T << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}