#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int mxN = 5005;
ll int a[mxN];
ll int b[mxN][mxN];
ll int dp[mxN][mxN];

int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i],b[0][i]=a[i],dp[0][i]=a[i];
	for(int i = 1;i < n;i++)
		for(int j = 0;j <= n-i;j++) b[i][j]=b[i-1][j]^b[i-1][j+1],dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i-1][j+1],b[i][j]});
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;

		cout << dp[r-l][--l] << "\n";
	}
}