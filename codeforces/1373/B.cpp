#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
 
void solve(){
    string s;
    cin >> s;
    int cntz = 0;
    int cnto = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i]=='0') cntz++;
        else cnto++;
    }
    int result = min(cntz,cnto);
    if(result&1) cout << "DA\n";
    else cout << "NET\n";
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}