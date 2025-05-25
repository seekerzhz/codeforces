    #include <bits/stdc++.h>

    using namespace std;
    #ifdef LOCAL
    #define INPUT(from) freopen(from, "r", stdin)
    #else
    #define INPUT(from) ((void)0)
    #endif
    typedef long long ll;

    void solve() {
        stack <int> stk;
        string s;
        cin >> s;
        int cnt = 0 ;
        for(auto &i:s) {
            if(i=='(') stk.push(1);
            else stk.pop();

            if(stk.size() ==0) cnt++;
        }
        if(cnt > 1) puts("YES");
        else puts("NO");
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