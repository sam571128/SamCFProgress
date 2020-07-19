#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int l,r,m;
    cin >> l >> r >> m;
    for(int i = l;i <= r;i++){
        int n = (m+(r-l))/i;
        if(n>0&&n*i>=m-(r-l)&&n*i<=m+(r-l)){
            int d = m-n*i,b,c;
            if(d>0) b = r, c = r-d;
            else b = l, c = l-d;
            cout << i << " " <<  b << " " << c << "\n";
            return;
        }
    }
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}