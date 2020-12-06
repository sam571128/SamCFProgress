#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    for(int i = 0;i < n;i++) s += '0';
    s[n-1] = '1';
    map<int,int> m,m2;
    int arr[n];
    for(auto &x : arr) cin >> x, m2[x]++;
    for(int i = 0;i < n-1;i++){
        m[min(arr[i],arr[i+1])]++;
    }
    for(int i = 1;i <= n;i++) if(!m2[i]) s[n-1] = '0';
    for(int i = n-1;i;i--){
        if(m[i]){
            s[i-1] = '1';
            int tmp = i;
            while(--m[i]){
                s[tmp]='0';
                tmp++;
            }
        }
    }
    for(int i = 0;i < n-2;i++){
        if(s[i]=='0') s[i+1] = '0';
    }
    reverse(s.begin(),s.end());
    cout << s << '\n';
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}