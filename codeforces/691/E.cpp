#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105, MOD = 1e9+7;
int n,k;
struct mat{
	int arr[N][N];
	mat operator * (mat b){
		mat c = mat();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					c.arr[i][j] = (c.arr[i][j] + arr[i][k]*b.arr[k][j]%MOD)%MOD;
				}
			}
		}
		return c;
	}
	mat(){
		memset(arr,0,sizeof arr);
	}
};

mat fastpow(mat m, int p){
	mat ans = mat();
	for(int i = 0;i < n;i++) ans.arr[i][i] = 1;
	while(p){
		if(p&1) ans = ans * m;
		m = m*m;
		p>>=1;
	} 
	return ans;
}

int cnt(int num){
	int ans = 0;
	while(num){
		ans++;
		num &= num-1;
	}
	return ans;
}

signed main(){
	fastio
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	mat m = mat();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(cnt(arr[i]^arr[j])%3==0) m.arr[i][j] = 1;
		}
		m.arr[i][n] = 1;
	}
	mat tmp = fastpow(m,k-1);
	int ans = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			ans = (ans+tmp.arr[i][j])%MOD;
		}
	}
	cout << ans << "\n";
}