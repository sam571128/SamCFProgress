#include <bits/stdc++.h>
 
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
unordered_map<char,char> m;
void solve(){
    string s;
    cin >> s;
    string ans = "";
    unordered_map<char,int> m2;
    for(int i = 0;i < s.size();i++){
        m2[s[i]]++;
    }
    int ma = 0;
    char tmp;
    for(auto itr = m2.begin();itr!=m2.end();itr++){
        if(itr->second>ma){
            ma = itr->second;
            tmp = itr->first;
        }
    }
    for(int i = 0;i < s.size();i++){
        ans += m[tmp];
    }
    cout << ans << "\n";
}
 
int main(){
    fastio
    int t;
    cin >> t;
    m['R'] = 'P';
    m['P'] = 'S';
    m['S'] = 'R';
    while(t--) solve();
}