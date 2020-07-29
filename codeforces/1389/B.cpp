#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n,k,z;
    cin >> n >> k >> z;
    int a[n];
    for(auto &x : a) cin >> x;
    int ans = 0;
    for(int i = 0;i <= k;i++) ans += a[i];
    int ind = k, tmp = ans,tmp2 = ans-a[k];;
    for(int i = 0;i < z&&ind >= 2;i++){
        tmp -= a[ind]+a[ind-1];
        ind-=2;
        int ma = 0;
        for(int j = 0;j < ind;j++){
            ma = max(ma,a[j]+a[j+1]);
        }
        ans = max(ans,tmp+ma*(i+1));
    }
    ind = k-1; 
    for(int i = 0;i < z&&ind>=1;i++){
        if(i) tmp2-=a[ind]+a[ind-1], ind-=2;
        int ma = 0;
        for(int j = 0;j < ind;j++){
            ma = max(ma,a[j]+a[j+1]);
        }
        ans = max(ans,tmp2+ma*i+(ind>=1?a[ind-1]:0));
    }
    cout << ans << "\n";
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}