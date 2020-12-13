#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 212;
int C[N][N];


void init(){
	for(int i = 0;i < N;i++){
		C[i][0] = 1;
	}
	C[1][1] = 1;
	for(int i = 2;i < N;i++){
		for(int j = 1;j <= N;j++){
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}
}

signed main(){
	fastio
	init();
	int n;
	cin >> n;
	cout << C[n-12+11][n-12] << "\n";
}