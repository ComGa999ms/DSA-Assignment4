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

const int N = 1e7 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

int n, m;
int L[N], R[N];

void solve(void) {
    cin >> n >> m;
    rep(i, 1, n) {
        L[i] = i - 1;
        R[i] = i + 1;
    }

    L[1] = n;
    R[n] = 1;

    while (m-- ) {
        int u, v;
        cin >> u >> v;

        if (u == v) continue;
        int lx = L[u], rx = R[u];

        R[lx] = rx;
        L[rx] = lx;

        int ri = R[v]; 
        L[u] = v;
        R[u] = ri;
        R[v] = u;
        L[ri] = u;
    }

    int cur = 1;
    rep(i, 1, n) {
        cout << cur << ' ';
        cur = R[cur];
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}