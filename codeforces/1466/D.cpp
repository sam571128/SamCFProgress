#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    int val[n+1] = {}, deg[n+1] = {}, ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> val[i];
        ans += val[i];
    }
    for(int i = 2;i <= n;i++){
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1;i <= n;i++){
        if(deg[i] > 1) pq.push({val[i],deg[i]});
    }
    cout << ans << " ";
    while(!pq.empty()){
        auto [v,d] = pq.top(); pq.pop();
        d--;
        ans += v;
        if(d > 1) pq.push({v,d});
        cout << ans << " ";
    }
    cout << '\n';
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}