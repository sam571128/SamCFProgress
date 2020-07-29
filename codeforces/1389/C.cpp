#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    string s;
    cin >> s;
    int ans = 2;
    bool same = 0;
    for(int i = 0;i <= 9;i++){
        for(int j = 0;j <= 9;j++){
            int st = 0;
            int cnt = 0;
            for(int t = 0;t < s.size();t++){
                if(!st&&s[t]==('0'+i)) cnt++,st^=1;
                else if(st&&s[t]==('0'+j)) cnt++, st^=1;
            }
            if(i==j&&cnt>=ans) ans = max(ans,cnt),same = 1;
            else if(cnt>ans) ans=max(ans,cnt),same=0;
        }
    }
    cout << s.size()-(ans&1&&!same?ans-1:ans) << "\n";
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}