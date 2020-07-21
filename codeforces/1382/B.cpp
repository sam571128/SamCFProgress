#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &x : a) cin >> x;
    int turn = 1;
    for(int i = 0;i < n-1;i++){
        if(a[i]==1) turn^=1;
        else break;
    }
    cout << (turn ? "First\n" : "Second\n");
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}