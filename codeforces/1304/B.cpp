#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


signed main(){
    fastio
    int n,m;
    cin >> n >> m;
    set<string> s;
    vector<string> v1, mid, v2;
    for(int i = 0;i < n;i++){
        string tmp, tmp2;
        cin >> tmp;
        tmp2 = tmp;
        reverse(tmp.begin(),tmp.end());
        if(tmp==tmp2){
            if(mid.empty())mid.push_back(tmp);
            continue;
        }
        s.insert(tmp2);
        if(s.find(tmp)!=s.end()){ 
            v1.push_back(tmp);
            v2.push_back(tmp2);
        }
        
    }
    string ans = "";
    for(auto x : v1) ans += x;
    for(auto x : mid) ans += x;
    reverse(v2.begin(),v2.end());
    for(auto x : v2) ans += x;
    cout << ans.size() << "\n";
    cout << ans<< "\n";
}