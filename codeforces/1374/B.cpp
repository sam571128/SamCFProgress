#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int cnt = 0, ans = 0;
    while(n%3==0){
        cnt++;
        n/=3;
    }
    for(int i = 0;i < cnt;i++){
        if(n&1) ans++, n*=2;
        n/=2;
        ans++;
    }
    if(n==1){
        cout << ans << "\n";
    }else{
        cout << -1 << '\n';
    }
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}