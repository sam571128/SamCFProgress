#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int idx[N];

void solve(){
    fill(idx,idx+N,1e9);
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    int ans = 0;
    while(i < s1.size()&&j < s2.size()){
        if(s1[i]==s2[j]) i++, j++, idx[j] = min(idx[j],i-1);
        else i++;
        ans = (int)s1.size()-i;
    }
    i = s1.size()-1, j = s2.size()-1;
    while(~i&&~j){
        if(s1[i]==s2[j]){
            i--, j--;
            ans = max(ans,i-idx[j+1]);
        }else i--;
        if(j==-1) ans = max(i+1,ans);
    }
    cout << ans << "\n";
}

signed main(){
    fastio
    int t = 1;
    //cin >> t;
    while(t--) solve();
}