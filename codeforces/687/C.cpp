#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 505;
int dp[2][N][N];

signed main(){
	fastio
	int n, m;
	cin >> n >> m;
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;i++){
		int tmp;
		cin >> tmp;
		for(int j = 0;j <= m;j++){
			for(int k = 0;k <= j;k++){
				dp[i%2][j][k] |= dp[(i+1)%2][j][k];
				if(j>=tmp) dp[i%2][j][k] |= dp[(i+1)%2][j-tmp][k];
				if(j>=tmp&&k>=tmp) dp[i%2][j][k] |= dp[(i+1)%2][j-tmp][k-tmp];
			}
		}
	}
	vector<int> v;
	for(int i = 0;i <= m;i++){
		if(dp[n%2][m][i]) v.push_back(i);
	}
	cout << v.size() << "\n";
	for(auto x : v) cout << x << ' ';
}