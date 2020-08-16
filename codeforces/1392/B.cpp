#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(auto &x : a) cin >> x;
	int arr1[n], arr2[n];
	int mx = *max_element(a,a+n);
	for(int i = 0;i < n;i++) arr1[i] = mx - a[i];
	mx = *max_element(arr1,arr1+n);
	for(int i = 0;i < n;i++) arr2[i] = mx - arr1[i];
	if(k&1){
		for(auto &x : arr1) cout << x << " ";
	}else{
		for(auto &x : arr2) cout << x << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}