#include <bits/stdc++.h>
#include <algorithm>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	vector<int> v;
	int dp[a];
	while(a--){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	dp[0] = 1;
	for(int i = 1;i < v.size();i++){
		if(v[i]>=v[i-1]){
			dp[i] = dp[i-1]+1;
		}else{
			dp[i] = 1;
		}
	}
	
	int result = INT_MIN;
	for(int i = 0;i < v.size();i++){
		result = max(result,dp[i]);
	}
	cout << result;
}