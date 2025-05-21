#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  int last = 0;
  cin >> last;
  int flag = 1 , sum = last;
  for(int i = 2 ; i <= n ; i++) {
    int now;
    cin >> now;
    if(last==0 &&now == 0) {
        flag = 0;
    }
    last = now;
    sum += now;
  }
  if(flag && sum != n) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main()
{
  int tc;
  cin >> tc;
  while(tc--)
    solve();
  return 0;
}