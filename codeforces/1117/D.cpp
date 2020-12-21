#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;

struct matrix{
	vector<vector<int>> arr;
	int n, m;
	matrix(int nn, int mm){
		n = nn, m = mm;
		arr.resize(n,vector<int>(m,0));
	}
	matrix operator * (matrix b){
		matrix c(n,b.m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < b.m;j++){
				for(int k = 0;k < m;k++){
					c.arr[i][j] = (c.arr[i][j]+arr[i][k]*b.arr[k][j]%MOD)%MOD;
				}
			}
		}
		return c;
	}
};

int fastpow(matrix a, int p){
	matrix res(a.n,a.m);
	for(int i = 0;i < res.n;i++) res.arr[i][i] = 1;
	while(p){
		if(p&1) res = res * a;
		a = a*a;
		p >>= 1;
	}
	return res.arr[0][0];
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	matrix a(m,m);
	a.arr[0][0] =  1;
	a.arr[0][m-1] = 1;
	for(int i = 1;i < m;i++){
		a.arr[i][i-1] = 1;
	}
	cout << fastpow(a,n) << "\n";
}