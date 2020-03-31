#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs; 

int main(){
	fastio
	cini(n);
	vi v;
	intz(sum);
	for(int i = 0;i < n;i++){
		cini(tmp);
		v.push(tmp);
		sum+=tmp;
	}
	int dp[n][n];
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < v.size();j++){
			if(i>=j){
				dp[i][j] = sum + (v[j]==0 ? 1 : -1);
			}else{
				dp[i][j] = dp[i][j-1] + (v[j]==0 ? 1 : -1);
			}
		}
	}
	int ma = INT_MIN;
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < v.size();j++){
			ma = max(ma,dp[i][j]);
		}
	}
	cout << ma;
}