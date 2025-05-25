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
map <int, int> cnt;

void solve(void) {
    cin >> n;
    rep(i, 1, n) cin >> h[i];

    int res = 0;
    stack <int> st;

    rep(i, 1, n) {
        while (sz(st) && st.top() < h[i]) {
            cnt[st.top()]--;
            ++res;
            st.pop();
        }
        
        if (sz(st)) {
            if (h[i] == st.top()) {
                res += cnt[h[i]];
                if (sz(st) > cnt[h[i]]) ++res;
            }
            else ++res;
        }
        st.push(h[i]);
        cnt[h[i]]++;
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