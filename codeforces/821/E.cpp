#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 16, MOD = 1e9+7;
struct matrix{
	vector<vector<int>> arr;
	matrix(){arr.resize(N,vector<int>(N,0));}
	matrix operator * (matrix b){
		matrix c;
		for(int i = 0;i < N;i++){
			for(int j = 0;j < N;j++){
				for(int k = 0;k < N;k++){
					c.arr[i][j] = (c.arr[i][j]+arr[i][k]*b.arr[k][j])%MOD;
				}
			}
		}
		return c;
	}
};

matrix fastpow(matrix a, int p){
	matrix res;
	for(int i = 0;i < N;i++) res.arr[i][i] = 1;
	while(p){ 
		if(p&1) res = res * a;
		a = a*a;
		p>>=1;
	}

	return res;
}

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	matrix ans;
	ans.arr[0][0] = 1;
	for(int i = 0;i < n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		for(int j = c+1;j < N;j++) ans.arr[j][0] = 0;
		matrix tmp;
		for(int j = 0;j <= c;j++){
			for(int k = max((int)0,j-1); k <= min(c,j+1);k++){
				tmp.arr[j][k] = 1;
			}
		}
		tmp = fastpow(tmp,min(k-a,b-a));
		ans = tmp * ans;
	}
	cout << ans.arr[0][0]%MOD << "\n";
}