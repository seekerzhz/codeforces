#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

vector<ll> mp(5e5+7) , lef(5e5+7) , ri(5e5+7) , head(5e5+7);
void solve() {
    int n;
    cin >> n;
    for(int i = 0 ; i <= n+5 ; i++) {
        mp[i] = 0,lef[i] = 0 , ri[i] = 0 , head[i] = 0;
    }
    vector<ll>a(n+2,0);
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if(a[i]==a[i-1]) head[i] = head[i-1];
        else head[i] = i;
        if(head[i]==i) {
            lef[i] = (i-1)*a[i];
        } else lef[i] = lef[head[i]];
    }
    for(int i = n ; i >= 1 ; i--) {
        if(a[i]==a[i+1]) head[i] = head[i+1];
        else head[i] = i;
        if(head[i]==i) {
            ri[i] = (n-i)*a[i];
        } else ri[i] = ri[head[i]];
    }
    ll ans = a[1]*n;
    for(int i = 1 ; i <= n ; i++) {
        ll res = lef[i] + ri[i];
        ans = min(ans,res);
    }
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