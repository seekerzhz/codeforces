#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    int cnt = 0;
    while(n!=0) cnt++,n/=2;
    cout << cnt*2+1 << endl;
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