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

multiset <pii> Set;
string s;
int n, cnt[256], a[N];
vector <int> adj[N];
int res = 0, Size;

void dfs(int u, int high) {
    bool check = 0;

    for (int v : adj[u]) {
        check = 1;
        dfs(v, high + 1);
    }

    if (!check) {
        res += a[u] * high;
    }
}

void solve(void) {
    cin >> Size >> s;

    for (int T : s) cnt[T]++;
    rep(i, 0, 255) if (cnt[i]) {
        ++n;
        Set.insert(pii(cnt[i], n));
        a[n] = cnt[i];
    }

    if (sz(Set) == 1) {
        ++n;
        Set.insert(pii(0, n));
        a[n] = 0;
    }

    while (sz(Set) > 1) {
        pii t1 = *Set.begin(); Set.erase(Set.begin());
        pii t2 = *Set.begin(); Set.erase(Set.begin());

        ++n;

        int newValue = t1.fi + t2.fi;
        adj[n].push_back(t1.se);
        adj[n].push_back(t1.se);

        Set.insert(pii(newValue, n));
    }

    dfs(n, 0);
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}