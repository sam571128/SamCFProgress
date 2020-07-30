#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int u,v;
    cin >> u >> v;
    if((u&1)!=(v&1)||u>v) cout << -1 << "\n";
    else if(u==0&&v==0) cout << 0 << "\n";
    else if(u==v) cout << 1 << "\n" << u << "\n";
    else if((((v-u)/2)&u)==0) cout << 2 << "\n" << u+(v-u)/2 << " " << (v-u)/2 << '\n';
    else cout << 3 << '\n' << u << " " << (v-u)/2 << " " << (v-u)/2 << "\n";
}