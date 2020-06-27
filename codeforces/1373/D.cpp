#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	ll dp[n+1][3];
	memset(dp,0,sizeof dp);
	for(auto &x : v) cin >> x;
	for(int i = 0;i < n;i++){
		dp[i+1][0] = max(dp[i+1][0],dp[i][0]+(i&1 ? 0 :v[i]));
		if(i+2<=n) dp[i+2][1] = max(dp[i+2][1],max(dp[i][0],dp[i][1])+(i&1 ? v[i] : v[i+1]));
		dp[i+1][2] = max(dp[i+1][2], max({dp[i][0],dp[i][1],dp[i][2]}) + (i&1 ? 0 : v[i]));
	}
	cout << max({dp[n][0],dp[n][1],dp[n][2]}) << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}
