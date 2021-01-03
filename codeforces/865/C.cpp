#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e3+5;
int a[55], b[55], p[55];
int n,r;
double dp[55][N];

bool check(double num){
	for(int i = n-1;~i;i--){
		for(int j = r+1;j < N;j++) dp[i+1][j] = num;
		for(int j = r;~j;j--){
			dp[i][j] = min(num,(dp[i+1][j+a[i]]+a[i])*p[i]/100+(dp[i+1][j+b[i]]+b[i])*(100-p[i])/100);
		}
	}
	return dp[0][0] < num;
}

signed main(){
	//fastio
	cin >> n >> r;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i] >> p[i];
	}
	double l = 0, r = 1e18;
	for(int i = 0;i < 200;i++){
		double mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(10) << l << "\n";
}