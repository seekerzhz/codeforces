#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

const ll mod = 998244353;

ll qkp(ll x, ll n) {
    ll res = 1;
    while(n>0) {
        if(n&1) {
            res = res*x%mod;
        }
        x=  x*x%mod;
        n >>= 1;
    }
    return res;
}

vector<ll>work(const vector<ll>a, const vector<ll>b) {
    ll maxi[2] = {0,0} , maxn[2] = {0,0};
    ll n = a.size();
    vector<ll>x(n);
    for(ll i = 0 ; i < n ; i++) {
        if(a[i] >= maxn[0]) {
            maxn[0] = a[i];
            maxi[0] = i;
        }
        if(b[i] >= maxn[1]) {
            maxn[1] = b[i];
            maxi[1] = i;
        }
        if(maxn[0] > maxn[1])
            x[i] = qkp(2,maxn[0]) + qkp(2,b[i-maxi[0]]);
        else if(maxn[0] == maxn[1]) {
            if(b[i-maxi[0]] > a[i-maxi[1]]) {
            x[i] = qkp(2,maxn[0]) + qkp(2,b[i-maxi[0]]);
            }
            else x[i] = qkp(2,maxn[1]) + qkp(2,a[i-maxi[1]]);
        }
        else x[i] = qkp(2,maxn[1]) + qkp(2,a[i-maxi[1]]);
        x[i]%=mod;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<ll>a(n) , b(n);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;
    auto t1 = work(a,b) ;
    for(auto i:t1) cout << i << " ";
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