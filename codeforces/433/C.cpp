#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,m;
	cin >> n >> m;
	ll arr[m];
	vector<ll> v[n+1];
	for(auto &x : arr) cin >> x;
	ll sum = 0;
	for(int i = 1;i < m;i++){
		if(arr[i]!=arr[i-1]){
			v[arr[i]].push_back(arr[i-1]);
			v[arr[i-1]].push_back(arr[i]);
			sum += abs(arr[i]-arr[i-1]);
		}	
	}
	ll ans = sum;
	for(int i = 1;i <= n;i++){
		if(v[i].empty()) continue;
		ll curr = 0;
		for(auto x : v[i]) curr -= abs(x-i);
		sort(v[i].begin(),v[i].end());
		ll y = v[i][v[i].size()/2];
		for(auto x : v[i]) curr += abs(x-y);
		ans = min(ans,sum+curr);
	}
	cout << ans << "\n";
}