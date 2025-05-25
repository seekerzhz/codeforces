#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

struct Edge {
    int to;
    int w;
};

bool judge(int x, vector<vector<Edge>> g, vector<int> b) {
    int n = b.size() - 1;
    vector<bool> flag(n + 1, 0);
    vector<int> battery(n + 1, -1);

    queue<int> q;
    q.push(1);
    flag[1] = 1;
    battery[1] = min(x, b[1]);

    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        for (const auto& edge : g[top]) {
            if (edge.w <= battery[top]) {
                auto v = edge.to;
                auto new_battery = battery[top] + b[v];
                new_battery = min(new_battery, x); // 上限是x
                if (!flag[v] || new_battery > battery[v]) {
                    flag[v] = true;
                    battery[v] = new_battery;
                    q.push(v);
                }
            }
        }
    }

    return flag[n];
}

int work(int n, int m, vector<int> b, vector<tuple<int, int, int>> edges) {
    vector<vector<Edge>> g(n + 1);
    for (auto [u, v, w] : edges) {
        g[u].push_back({v, w});
    }

    int l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (judge(mid, g, b)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> b[i];
        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }

        cout << work(n, m, b, edges) << '\n';
}

int main() {
    INPUT("in.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve(); 
    return 0;
    
}
