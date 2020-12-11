#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define int long long
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
void solve(){
    int n,q;
    cin >> n >> q;
    int arr[n];
    for(auto &x : arr) cin >> x;
    sort(arr,arr+n);
    ll pref[n+1] = {};
    int lb[N], rb[N] = {};
    memset(lb,0x3f3f3f,sizeof lb);
    for(int i = 0;i < n;i++){
        pref[i+1] = pref[i]+arr[i];
        lb[arr[i]] = min(lb[arr[i]],i);
        rb[arr[i]] = max(rb[arr[i]],i);
    }
    set<int> s;
    queue<pair<int,int>> bfs;
    bfs.push({arr[0],arr[n-1]});
    while(!bfs.empty()){
        auto [l,r] = bfs.front(); bfs.pop();
        int mid = l+r>>1;
        int idx = upper_bound(arr,arr+n,mid)-arr;
        ll suml = pref[idx]-pref[lb[l]], sumr = pref[rb[r]+1]-pref[idx];
        s.insert(suml); s.insert(sumr);
        if(suml!=0&&arr[idx-1]!=r) bfs.push({l,arr[idx-1]});
        if(l!=r&&sumr!=0&&arr[idx]!=l) bfs.push({arr[idx],r});
    }
    while(q--){
        ll sum;
        cin >> sum;
        if(pref[n]-pref[0]==sum) cout << "YES\n";
        else if(s.find(sum)!=s.end()) cout << "YES\n";
        else cout << "NO\n";
        contin:;
    }
}

signed main(){
    fastio
    //freopen("ans.out","r",stdin);
    int t = 1;
    cin >> t;
    while(t--) solve();
}