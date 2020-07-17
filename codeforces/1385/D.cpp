#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ans = INT_MAX;
string str = "";
string s;
void dfs(int tmp,int s2 = 0, int c = 0, int cnt = 0){ 
    if(tmp==1){
        cnt += (s[s2]!=('a'+c));
        str[s2] = 'a' + c;
        ans = min(cnt,ans);
        return;
    }  
    int newcnt = cnt;
    for(int i = s2;i < s2+tmp/2;i++){
        newcnt += (s[i]!=('a'+c));
        str[i] = 'a'+c;
    }
    dfs(tmp/2,s2+tmp/2,c+1,newcnt);
    newcnt = cnt;
    for(int i = s2+tmp/2;i < s2+tmp;i++){
        newcnt += (s[i]!=('a'+c));
        str[i] = 'a'+c;
    }
    dfs(tmp/2,s2,c+1,newcnt);
}

void solve(){
    int n;
    cin >> n >> s;
    str = "";
    ans = INT_MAX;
    for(int i = 0;i < n;i++) str += 'a';
    dfs(n);
    cout << ans << "\n";
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}