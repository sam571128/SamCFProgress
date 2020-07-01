#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    ll n,r;
    cin >> n >> r;
    ll ans = 0;
    if(n > r){
        cout << r*(r+1)/2 << "\n";
    }else{
        cout << n*(n-1)/2+1 << "\n";
    }
}

int main(){
    fastio
    ll t;
    cin >> t;
    while(t--) solve();
}