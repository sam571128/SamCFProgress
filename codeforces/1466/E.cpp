#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}
	

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int sum = 0;

	int bit[61] = {};
	for(auto &x : arr){
		for(int i = 60;~i;i--){
			if(x&(1LL<<i)) bit[i]++;
		}
	}
	int tmp1[n] = {}, tmp2[n] = {};
	for(int i = 0;i < n;i++){
		for(int j = 60;~j;j--){
			if(arr[i]&(1LL<<j)){
				//cout << (1LL<<j)*bit[j]%MOD << " " << bit[j]*fastpow(2,j)%MOD << "\n";
				tmp1[i]=(tmp1[i]+(1LL<<j)%MOD*bit[j]%MOD)%MOD;
			}
		}
		/*for(int j = 0;j < n;j++){
			tmp1[i] = (tmp1[i]+(arr[i]&arr[j]))%MOD;
		}*/
	}
	for(int i = 0;i < n;i++){
		for(int j = 60;~j;j--){
			if(arr[i]&(1LL<<j)){
				//cout << (1LL<<j)*bit[j]%MOD << " " << bit[j]*fastpow(2,j)%MOD << "\n";
				tmp2[i]=(tmp2[i]+(1LL<<j)%MOD*n%MOD)%MOD;
			}else{
				tmp2[i]=(tmp2[i]+(1LL<<j)%MOD*bit[j]%MOD)%MOD;
			}
		}
		/*for(int j = 0;j < n;j++){
			tmp2[i] = (tmp2[i]+(arr[i]|arr[j]))%MOD;
		}*/
	}

	for(int i = 0;i < n;i++){
		//for(int j = 0;j < n;j++){
			sum = (sum+tmp1[i]*tmp2[i]%MOD)%MOD;
		//}
	}
	cout << sum%MOD << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}