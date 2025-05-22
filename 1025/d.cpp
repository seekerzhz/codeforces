#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    int n,m,l;
    cin >> n >> m >> l;
    cout << n << " " << m << " " << l << endl;
    vector<int> a(l,0);
    for(auto &i:a) cin >> i;
    for(auto &i:a) cout << i << " ";
    cout << endl;
    vector<int> v[n+1];
    for(int i = 0 ; i < m ; i++ ) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
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