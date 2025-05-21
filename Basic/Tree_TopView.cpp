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
#define p2i pair<int,pii>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;


struct Tree {
    int value;
    
    Tree *R, *L;
    Tree(int x) {
        value = x;
        L = R = NULL;
    }
};

int n;
int res[N];

Tree *add(Tree *root, int x) {
    if (!root) return new Tree(x);
    
    if (x <= root->value) root->L = add(root->L, x);
    else root->R = add(root->R, x);

    return root;
}

void sol(Tree *root) {
    if (!root) return ;

    res[++n] = root->value;
    
    if (root->R) sol(root->R);

    if (root->L && !root->R) sol(root->L);
}

void solve(void) {
    Tree* root = NULL;

    int _; cin >> _;
    rep(i, 1, _) {
        int x; cin >> x;
        root = add(root, x);
    }

    sol(root);
    sort(res + 1, res + 1 + n);
    

    rep(i, 1, n + 1) cout << res[i] << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}