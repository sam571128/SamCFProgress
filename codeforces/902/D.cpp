#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 155;
int p[N][N];

signed main(){
	fastio
	int n;
	cin >> n;
	p[0][0] = 1, p[1][1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= i;j++)
			p[i][j] = (p[i][j] + p[i-1][j-1])%2;
		for(int j = 0;j <= i;j++)
			p[i][j] = (p[i][j] + p[i-2][j])%2;
	}
	cout << n << "\n";
	for(int j = 0;j<=n;j++){
		cout << p[n][j] << " ";
	}
	cout << "\n";
	cout << n-1 << "\n";
	for(int j = 0;j <= n-1;j++){
		cout << p[n-1][j] << " ";
	}
}