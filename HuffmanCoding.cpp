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

int n;
int cnt[N];
char item[] = {'A', 'N', 'P', '.', 'L', 'C', 'M'};

int get(char x) {
    if (x == 'A') return 1;
    if (x == '.' || x == 'N') return 3;
    return 4;
}

void solve(void) {
    cin >> n;
    rep(i, 1, n) {
        char c; cin >> c;
        cnt[c - 'A' + 100]++;
    }

    int res = 0;
    for (char c : item) {
        // cout << c << ' ';
        int value = cnt[c - 'A' + 100];
        int heso = get(c);
        res += value * heso;
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