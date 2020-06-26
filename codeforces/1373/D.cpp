#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll mss(vector<ll> v){
	ll sum = 0, ans = 0;
	for(int i = 0;i < v.size();i++){
		sum = max((ll)0,sum+v[i]);
		ans = max(sum,ans);
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	vector<ll> a;
	vector<ll> b;
	ll sum = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(i&1^1) sum += arr[i];
	}
	for(int i = 0;i < n-1;i+=2){
		a.push_back(arr[i+1]-arr[i]);
	}
	for(int i = 1;i < n-1;i+=2){
		b.push_back(arr[i]-arr[i+1]);
	}
	cout << sum + max({(ll)0,mss(a),mss(b)}) << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}