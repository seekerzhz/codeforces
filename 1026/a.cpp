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
    vector<int >a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin() , a.end());
    int mo = -1,me = -1, maxo=-1,maxe = -1;
    for(int i = 0 ; i < n ; i++) {
        if(a[i]%2) {
            if(mo == -1) mo = i;
            maxo = i;
        } else {
            if(me == -1) me = i;
            maxe = i;
        }
    }
  //  printf("%d %d %d %d \n",mo,me,maxo,maxe);
    int ans = n;
    if(mo != -1) {
        ans = min(ans, n - (maxo - mo + 1) );
    } 
    if(me != -1 ) {
        ans = min(ans, n - (maxe - me + 1) );
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