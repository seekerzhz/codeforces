#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

const int maxn = 5007;
const int INF = 1e9;


int dp[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i:a) cin >> i;
    int g0 = a[0];
    for (int i = 1; i < n; ++i)
        g0 = __gcd(g0, a[i]);

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = a[i] / g0;

    // 如果已经有 1，则 n - cnt(1) 即为答案
    int ones = count(b.begin(), b.end(), 1);
    if (ones > 0) {
        cout << n - ones << '\n';
        return ;
    }

    int maxn = *max_element(b.begin(), b.end());
    vector<int> dp(maxn + 1, INF);

    for (int num : b) {
        if (num <= maxn && dp[num] > 1)
            dp[num] = 1;

        for (int d = 1; d <= maxn ; ++d) {
            if (dp[d] != INF) {
                int g = __gcd(d, num);
                if (g <= maxn && dp[g] > dp[d] + 1)
                    dp[g] = dp[d] + 1;
            }
        }
    }

    int m;
    if (dp[1] == INF)
        m = n;
    else
        m = dp[1];

    int ans = n + m - 2;
    cout << ans << endl;
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