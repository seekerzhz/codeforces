#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    auto t1 = min(a,c) , t2 = min(b,d);
    if(t1 >= t2) {
        puts("Gellyfish");
    } else puts("Flower");
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