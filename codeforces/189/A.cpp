#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	vector<int> v;
	v.push(a);
	v.push(b);
	v.push(c);
	int dp[n+1];
	for(int i = 0;i <= n;i++){
		if(i==0)dp[i] = 0;
		else{
			dp[i] = -10000;
			for(int j = 0;j < 3;j++){
				if(i-v[j]<0)continue;
				dp[i] = max(dp[i],dp[i-v[j]]+1);
			}
		}
	}
	cout << dp[n];
}