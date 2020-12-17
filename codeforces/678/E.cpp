#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 20;
double p[N][N], dp[1<<N][20];


void solve(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++) cin >> p[i][j];
	}
	dp[1][0] = 1; //The state when there is only the number 0 alive
	for(int i = 2;i < (1<<n);i++){
		for(int j = 0;j < n;j++){
			if(i&(1<<j))
				for(int k = 0;k < n;k++){
					if(i&(1<<k)&&k!=j)
						dp[i][j] = max({dp[i][j],dp[i^(1<<j)][k]*p[k][j]+dp[i^(1<<k)][j]*p[j][k]});
				}
		}
	}
	cout << setprecision(10) << fixed << *max_element(dp[(1<<n)-1],dp[(1<<n)-1]+n) << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}