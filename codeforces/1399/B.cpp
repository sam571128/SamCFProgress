#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);


void solve(){
     int n;
     cin >> n;
     int a[n], b[n];
     for(auto &x : a) cin >> x;
     for(auto &x : b) cin >> x;
     int am = *min_element(a,a+n), bm = *min_element(b,b+n);
     int ans = 0;
     for(int i = 0; i < n;i++){
       ans += max(a[i]-am,b[i]-bm);
     }
     cout << ans << '\n';
}

signed main()
{
    fastio
    int t;
    cin >> t;
    while(t--) solve();
    
}