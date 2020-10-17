#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 18;
int dp[1<<N][N], dis[N][N];
signed main(){
	fastio
	int n;
	cin >> n;
	vector<array<int,3>> v;
	for(int i = 0;i < n;i++){
		int x,y,z;
		cin >> x >> y >> z;
		v.push_back({x,y,z});
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			dis[i][j] = abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1])+max((int) 0,v[j][2]-v[i][2]);
			dis[j][i] = abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1])+max((int) 0,v[i][2]-v[j][2]);
		}
	}
	for(int i = 0; i < (1 << n); i++)
    fill(dp[i], dp[i] + n, 1e18);
	dp[1][0] = 0;
	for(int S = 1; S < (1 << n); S++){
	    for(int i = 0; i < n; i++){
	        if((S & (1 << i)) == 0){
	            for(int j = 0; j < n; j++){
	                if(S & (1 << j))
	                    dp[S | (1 << i)][i] = min(dp[S | (1 << i)][i], dp[S][j] + dis[j][i]);
	            }
	        }
	    }
	}
	int ans = 1e18;
	for(int i = 1;i < n;i++) 
		ans = min(ans,dp[(1<<n)-1][i] + dis[i][0]);
	cout << ans << "\n";
}