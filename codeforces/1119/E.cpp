#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n;
    cin >> n;
    int arr[n];
    for(auto &x : arr) cin >> x;
    int ans = 0, now = 0;
    for(auto x : arr){
        if(x >= now*2) x -= now*2, ans += now, now = 0;
        else ans += x/2, now -= x/2, x%=2;
        ans += x/3;
        now += x%3;
    }
    cout << ans << '\n';
}