#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, sum = 0;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum%n){
		cout << -1 << "\n";
		return;
	}
	sum/=n;
	vector<array<int,3>> v;
	for(int i = 1;i < n;i++){
		if(arr[i]%(i+1)){
			v.push_back({1,i+1,i+1-arr[i]%(i+1)});
			arr[0] -= i+1-arr[i]%(i+1);
			arr[i] += i+1-arr[i]%(i+1);
		}
		v.push_back({i+1,1,arr[i]/(i+1)});
		arr[0] += (arr[i]/(i+1))*(i+1);
		arr[i] = 0;
	}
	
	for(int i = 1;i < n;i++){
		v.push_back({1,i+1,sum});
	}
	cout << v.size() << "\n";
	for(auto x : v){
		for(auto y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}