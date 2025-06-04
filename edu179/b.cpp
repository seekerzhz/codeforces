#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    vector<int>f(11,1);
    for(int i = 2 ; i<= 10 ; i++) f[i] = f[i-1] + f[i-2]; 
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++) {
        vector<int>a(3);
        for(auto &i:a) cin >> i;
        sort(a.begin() , a.end());
        //for(auto i:a) cout << i << " ";
        if(a[0] >= f[n] && a[1] >= f[n] && a[2] >= f[n] + f[n-1]) {
            cout << 1;
        } else cout << 0;
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