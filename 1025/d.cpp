#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void dij(int n, vector<int>v[] , vector<array<int, 2>>&dis) {
    dis[1][0] = 0;
    queue<pair <int,int> >q;
    q.push({1,0});
    while(q.size()) {
        auto [x,d] = q.front();
        q.pop();
        for(auto &son : v[x]) {
            auto now = d+1;
            if(now < dis[son][d%2]) {
                q.push({son,now});
                dis[son][d%2] = now;
            }
        }
    }
    return ;
}

void solve() {
    int n,m,l;
    cin >> n >> m >> l;
//    cout << n << " " << m << " " << l << endl;
    vector<int> a(l,0);
    ll odds = 0x3f3f3f3f+1;
    ll sum = 0;
    for(auto &i:a) cin >> i,sum+=i , i%2?odds = min(odds,(ll)i) :1;
    vector<int> v[n+1];
    for(int i = 0 ; i < m ; i++ ) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
    }
    vector<array<int, 2>> dis(n+1,{0x3fffffff,0x3fffffff})  ;
    dij(n, v, dis);
    
    //for(int i = 1 ; i <= n ; i++) {int x=dis[i][0] ; cout << x <<  " ";}
    cout << endl;
    //for(int i = 1 ; i <= n ; i++) {int x=dis[i][1] ; cout << x <<  " ";}
    cout << endl;
    
    for(int i = 1 ; i <= n ; i++) {
        auto greet = [&](int p) { 
            if(dis[i][p] > 2e5) return 0;
            if(dis[i][p]%2 == sum%2) {
                if(sum>=dis[i][p]) return 1;
                else return 0;
            } else {
                if(odds < 1e4 && sum-odds >=dis[i][p]) return 1;
                else return 0;
            }
        };
        cout << max(greet(0),greet(1));
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