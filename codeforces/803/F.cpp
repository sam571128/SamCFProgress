#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, MOD = 1e9+7;

int fastpow(int n, int p){
    int res = 1;
    while(p){
        if(p&1) res = res * n % MOD;
        n = n * n%MOD;
        p>>=1;
    }
    return res;
}

int cnt[N], dp[N];
signed main(){
    fastio
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    for(int i = N-1;i;i--){
        int sum = 0;
        for(int j = i;j < N;j+=i){
            sum += cnt[j];
        }
        dp[i] = (fastpow(2,sum)-1+MOD)%MOD;
        for(int j = 2*i;j < N;j+=i){
            dp[i] = (dp[i] - dp[j]+MOD)%MOD;
        }
    }
    cout << dp[1] << "\n";
}