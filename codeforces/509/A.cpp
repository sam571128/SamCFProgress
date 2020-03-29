#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int a;
	cin >> a;
	int dp[a][a];
	for(int i = 0;i < a;i++){
		for(int j = 0;j < a;j++){
			if(i==0||j==0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	cout << dp[a-1][a-1];
}