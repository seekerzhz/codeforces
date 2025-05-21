#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    int t;
    cout << "mul 999999999" << endl;
    cin >> t;
    cout << "digit" << endl; 
    cin >> t;
    if (n != 81) {
        cout << "add " << n - 81 << endl;
        cin >> t;
    }

    cout << "!" << endl;
    cin >> t;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
        solve();
    return 0;
}