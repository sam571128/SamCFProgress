#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5;
bool check(ll arr[], int n){
	static int used[N];
	for(int i = 1;i <= n;i++) used[i] = 0;
	for(int i = 0;i < n;i++) used[arr[i]] = 1;
	for(int i = 1;i <= n;i++)
		if(!used[i]) return false;
	return true;
}

void solve(){
	ll n;
	cin >> n;
	ll arr[n];
	ll ma = INT_MIN;
	for(auto &x : arr) cin >> x, ma = max(x,ma);
	vector<pair<int,int>> v;
	if(check(arr,ma)&&check(arr+ma,n-ma)){
		v.push_back({ma,n-ma});
	}
	if(ma!=n-ma){
		if(check(arr,n-ma)&&check(arr+(n-ma),ma)){
			v.push_back({n-ma,ma});
		}
	}
	cout << v.size() << "\n";
	for(auto x : v) cout << x.first << " " << x.second << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}