#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int dp[n];
	dp[0] = 1;
	for(int i = 1;i < n;i++){
		if(a[i]>a[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
	}
	cout << *max_element(dp,dp+n);
}
