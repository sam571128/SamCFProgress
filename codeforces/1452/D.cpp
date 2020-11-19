#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

int fastpow(int n, int p){
    int res = 1;
    while(p){
        if(p&1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        p>>=1;
    }
    return res;
}

signed main(){
    fastio
    int n;
    cin >> n;
    int fib[n+1];
    for(int i = 0;i <= n;i++){
        if(i <= 1) fib[i] = 1;
        else fib[i] = (fib[i-1]+fib[i-2])%MOD;
    }
    cout << fib[n-1]*fastpow(fastpow(2,n),MOD-2)%MOD << "\n";
}