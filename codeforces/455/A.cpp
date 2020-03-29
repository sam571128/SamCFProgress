#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

long long int a[100005],dp[100005];

int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		ll int temp;
		cin >> temp;
		a[temp]++;
	} 
	dp[0] = 0;
	dp[1] = a[1];
	
	for(ll int i = 2;i <= 100004;i++){
		dp[i] = max(dp[i-1],dp[i-2] + a[i]*i);
	}
	cout << dp[100001];
}