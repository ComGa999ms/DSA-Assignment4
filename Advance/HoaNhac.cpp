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

int n;
int h[N];

void solve(void) {
    cin >> n;
    rep(i, 1, n) cin >> h[i];

    int res = 0;
    stack <pii> st;

    rep(i, 1, n) {
        int cnt = 1;
        while (sz(st) && st.top().fi <= h[i]) {
            res += st.top().se;
            if (h[i] == st.top().fi) cnt += st.top().se;
            st.pop();
        }
        
        if (sz(st)) ++res;
        st.push(pii(h[i], cnt));
    }
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