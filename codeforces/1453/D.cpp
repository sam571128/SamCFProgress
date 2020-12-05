#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n%2){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    while(n){
        int tmp = 2;
        ans.push_back(1);
        while(tmp*2+2 <= n) tmp = tmp*2+2, ans.push_back(0);
        n -= tmp;
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}