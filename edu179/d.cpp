#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end(), [](ll x, ll y) {
        return x / 100 < y / 100;
    });

    int pair_count = (n + 1) / 2;
    vector<vector<ll>> res;
    res.reserve(n); 

    int l = 0, r = m - 1;

    for (int k = 0; k < pair_count && l < r; ++k) {
        ll x = a[l++];
        ll y = a[r--];
        res.push_back({x, y, x, y, x, y});
        res.push_back({y, x, y, x, y, x});
    }

    if (l == r && res.size() < n) {
        ll x = a[l];
        res.push_back({x, x, x, x, x, x});
    }

    while ((int)res.size() < n) {
        res.push_back({0, 0, 0, 0, 0, 0});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    INPUT("in.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
    
}