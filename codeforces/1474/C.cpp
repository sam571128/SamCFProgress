#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	n *= 2;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	multiset<int> s;
	vector<pair<int,int>> ans;
	for(int i = 0;i < n-1;i++){
		s.clear();
		ans.clear();
		for(auto x : arr) s.insert(x);
		//Choose the first integer with the biggest integer
		int x = arr[n-1];
		ans.push_back({arr[n-1],arr[i]});
		s.erase(s.find(arr[n-1])); s.erase(s.find(arr[i]));
		for(int j = n-1;~j;j--){
			if(s.find(arr[j])==s.end()) continue;
			s.erase(s.find(arr[j]));
			if(s.find(x-arr[j])==s.end()) goto next;
			s.erase(s.find(x-arr[j]));
			ans.push_back({arr[j],x-arr[j]});	
			x = arr[j];
		}
		cout << "YES\n";
		cout << arr[n-1]+arr[i] << "\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
		return;
		next:;
	} 
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}