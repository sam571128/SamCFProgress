#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll sum = 0;
    ll tmp = n/m;
    for(int i=1;i<=9;i++){
           sum+=(n-m*i+m*10)/(m*10)*(m*i%10);
    } 
    cout << sum << "\n";
}

int main(){
    fastio
    ll q;
    cin >> q;
    while(q--) solve();
}