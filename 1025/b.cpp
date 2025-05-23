#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#define INPUT(from) freopen(from, "r", stdin)
#else
#define INPUT(from) ((void)0)
#endif
typedef long long ll;

int work(int a, int b) {
    int res = 0;
    while(a!=1) a=(a+1)/2,res++;
    while(b!=1) b=(b+1)/2,res++;
    return res;
}

// 3322 23 13 12 11

void solve() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    a = min(n-a+1,a);
    b = min(m-b+1,b);
    cout << min(work(a,m),work(n,b))+1 << endl;
}

int main() {
    INPUT("in.txt");
    cout << "hello world" << endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
     cin >> tc; 
     while(tc--) solve(); 
     return 0;
    
}