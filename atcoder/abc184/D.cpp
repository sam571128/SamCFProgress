#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

double dp[100][100][100];
int vis[100][100][100];

double solve(int a, int b, int c){
	if(a==100||b==100||c==100) return 0;
	if(vis[a][b][c]) return dp[a][b][c];
	vis[a][b][c] = 1;
	int s = a+b+c;
	dp[a][b][c] = 1 + 1.0*a*solve(a+1,b,c)/s +1.0*b*solve(a,b+1,c)/s + 1.0*c*solve(a,b,c+1)/s;
 	return dp[a][b][c];
}

signed main(){
	//fastio
	int a,b,c;
	cin >> a >> b >> c;
	cout << setprecision(10) << fixed << solve(a,b,c);
}