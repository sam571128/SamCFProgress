#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105, MOD = 1e9+7;
int m;
struct mat{
	int arr[N][N];
	mat(){
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				arr[i][j] = (i==j);
			}
		}
	}
	mat operator * (mat b){
		mat c;
		memset(c.arr,0,sizeof c.arr);
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				for(int k = 0;k < m;k++){
					c.arr[i][j] = (c.arr[i][j]+(long long)arr[i][k]*b.arr[k][j]%MOD)%MOD;
				}
			}
		}
		return c;
	}
};

mat fastpow(mat a, int p){
	mat tmp = mat();
	while(p){
		if(p&1) tmp = tmp*a;
		a = a*a;
		p>>=1;
	}
	return tmp;
}
int arr[(int)1e6+5];
signed main(){
	fastio
	int n,l;
	cin >> n >> l >> m;
	mat a,b,c;
	memset(a.arr,0,sizeof a.arr); memset(b.arr,0,sizeof b.arr); memset(c.arr,0,sizeof c.arr);
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		for(int j = 0;j < m;j++) a.arr[j][(j+tmp)%m]++;
	}
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		arr[i] = tmp;
		for(int j = 0;j < m;j++) b.arr[j][(j+tmp)%m]++;
	}
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		tmp += arr[i];
		for(int j = 0;j < m;j++) c.arr[j][(j+tmp)%m]++;
	}
	mat ans = a*fastpow(b,l-2)*c;
	cout << ans.arr[0][0] << "\n";
}