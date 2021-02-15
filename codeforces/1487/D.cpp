#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int num = (int)sqrt(2*n+1);
    int ans = num-1-num/2;
    num = num-(num+1)%2;
    if((num*num-1)/2+1 > n) ans--;

    cout << ans << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}
//c = b+1
//2b+1 = a^2
//k^2 <= 2*n+1
//k-k/2-1