#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans[n], tmp = n;
    for(int i = 0, last = 0;i < n;i++){
        if(i==n-1||s[i]=='>'){
            for(int j = i;j >= last;j--)
                ans[j] = tmp--;
            last = i + 1;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    tmp = 1;
    for(int i = 0, last = 0;i < n;i++){
        if(i==n-1||s[i]=='<'){
            for(int j = i;j >= last;j--)
                ans[j] = tmp++;
            last = i + 1;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}