#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);


void solve(){
      int n;
      cin >> n;
      int a[n];
      for(auto &x : a) cin >> x;
      sort(a,a+n);
      for(int i = 1; i < n;i++){
        if(a[i]-a[i-1]>1){
          cout << "No\n";
          return;
        }
      }
      cout << "Yes\n";
}

int main()
{
    fastio
    int t;
    cin >> t;
    while(t--) solve();
    
}