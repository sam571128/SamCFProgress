#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    int cnt = 0, lst = 0;
    bool ok = true;
    int arr[n], idx = -1;
    for(auto &x : arr) cin >> x;
    bool sort = true;
    for(int i = n;i;i--){
        if(arr[i] <arr[i-1]){
            idx = i, sort = false;
            break;
        }
    }
    if(sort){
        cout << 0 << "\n";
        return;
    }
    for(int i = 0;i <= idx;i++){
        if(arr[i] > x) swap(arr[i],x), cnt++;
        if(i!=n-1&&arr[i] > arr[i+1]){
            ok = false;
        }
    }
    cout << (ok ? cnt : -1) << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}