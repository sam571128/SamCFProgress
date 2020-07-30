#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int tmp = n/4+(n%4?1:0);
    for(int i = 0;i < n;i++){
        if(i>=n-tmp) cout << '8';
        else cout << '9';
    }
    cout << "\n";
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}