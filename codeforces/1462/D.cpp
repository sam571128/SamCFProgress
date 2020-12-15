#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(auto &x : arr) cin >> x;
    int pref[n+1] = {};
    for(int i = 0;i < n;i++){
        pref[i+1] = pref[i]+arr[i];
    }
    map<int,int> dp[n+1];
    for(int i = 0;i < n;i++){
        for(int j = i+1; j <= n;j++){
            if(i==0){
                dp[j][pref[j]-pref[i]] = 1;
            }else if(dp[i][pref[j]-pref[i]]){
                dp[j][pref[j]-pref[i]] = dp[i][pref[j]-pref[i]]+1;
            }
        }
    }
    int ma = 0;
    for(auto [a,b] : dp[n]){
        ma = max(ma,b);
    }
    cout << n-ma << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}