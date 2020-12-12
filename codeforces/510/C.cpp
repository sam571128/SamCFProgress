#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> adj[26];
    int deg[26] = {};
    bool ok = true;
    for(int i = 1;i < n;i++){
        string s2;
        cin >> s2;
        for(int j = 0;j < s.size();j++){
            if(j>=s2.size()){
                ok = false;
                break;
            }
            if(s[j]==s2[j]) continue;
            adj[s[j]-'a'].push_back(s2[j]-'a');
            deg[s2[j]-'a']++;
            break;
        }
        s = s2;
    }
    queue<int> q;
    for(int i = 0;i < 26;i++){
        if(deg[i]==0) q.push(i);
    }
    vector<char> ans;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(char(u+'a'));
        for(auto v : adj[u]){
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }
    for(int i = 0;i < 26;i++){
        if(deg[i]!=0||!ok){
            cout << "Impossible\n";
            return;
        } 
    }
    for(auto c : ans) cout << c;
}

signed main(){
    fastio
    int t = 1;
    //cin >> t;
    while(t--) solve();
}