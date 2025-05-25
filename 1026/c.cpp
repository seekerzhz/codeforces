#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    vector<pair<int,int> >inf(n) , can(n);
    for(auto &[x,y]:inf) cin >> x >> y;

    for(int i = 0 ; i < n ; i++ ) {
        can[i] = {0,0};
        if(i) can[i] = can[i-1];
        switch (a[i])
        {
        case 1:
            can[i].first++;
            can[i].second++;
            break;
        case -1:
            can[i].second++;
            break;
        }
        can[i] = {max(can[i].first,inf[i].first), min(can[i].second,inf[i].second)};
        if(can[i].first > can[i].second) {
            cout << -1 << endl;
            return ;
        }
    }
    /*
    for(auto [x,y]:can) {
        printf ("%d %d \n",x,y);
    }
    cout << endl;*/
    auto [bef_x,bef_y] = can[n-1];
    auto bef= min(bef_x,bef_y);
    for(int i = n-1 ; i >= 1 ; i--) {
        switch (a[i])
        {
        case 1:
            bef--;
            break;
        case -1:
            if(can[i-1].first==bef) a[i] = 0;
            else a[i] = 1 , bef--;
            break;
        }
    }
    if(a[0]==-1) {
        if(bef) a[0] = 1;
        else a[0] = 0;
    } 
    for(auto i:a) {
        cout << i << " ";
    }
    cout << endl;   
    return;

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