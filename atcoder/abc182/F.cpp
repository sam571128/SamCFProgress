#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 55;
ll n,x;
ll arr[N];

map<pair<int,ll>,ll> m;

ll solve(int i, ll sum){
	if(i==n-1) return 1;
	if(m[{i,sum}]) return m[{i,sum}];
	ll w = arr[i+1]/arr[i];
	if(sum%w) return m[{i,sum}] = solve(i+1,sum/w)+solve(i+1,sum/w+1);
	else return m[{i,sum}] = solve(i+1,sum/w);
}

signed main(){
	fastio
	cin >> n >> x;
	for(int i = 0;i < n;i++) cin >> arr[i];
	//The number of ways to use 1, (a_{i+1})/(a_i), (a_{i+2})/(a_{i+1}) 
	cout << solve(0,x) << "\n";
}