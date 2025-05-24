#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;
const int inf  = 2e9+1;

void bfs(int n, vector<int> v[], vector<array<int, 2>>& dis) {
    dis.assign(n + 1, {inf,inf});
    dis[1][0] = 0;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto [x, p] = q.front();
        q.pop();
        for (auto& son : v[x]) {
            int new_p = 1 - p; // 切换奇偶性
            if (dis[son][new_p] > dis[x][p] + 1) {
                dis[son][new_p] = dis[x][p] + 1;
                q.push({son, new_p});
            }
        }
    }
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(l);
    int sum = 0, min_odd = inf ;
    for (auto& i : a) {
        cin >> i;
        sum += i;
        if (i % 2) min_odd = min(min_odd, i);
    }
    bool has_odd = (min_odd != inf );

    vector<int> v[n + 1];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<array<int, 2>> dis;
    bfs(n, v, dis);

    for (int i = 1; i <= n; ++i) {
        bool found = false;
        for (int p : {0, 1}) {
            auto s = sum;
            if (p != sum % 2) {
                if (!has_odd) continue;
                s -= min_odd;
            }
            if (s >= 0 && dis[i][p] <= s) {
                found = true;
                break;
            }
        }
        cout << found;
    }
    cout << endl;
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