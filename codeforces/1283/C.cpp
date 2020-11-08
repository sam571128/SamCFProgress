#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1;i <= n;i++) s.insert(i);
	vector<int> a,b;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i]==0) a.push_back(i+1);
		else s.erase(arr[i]);
	}
	for(auto x : s){
		b.push_back(x);
	}
	for(int i = 0;i < a.size();i++){
		if(a[i]==b[i]){
			swap(b[i],b[(i+1)%a.size()]);
		}
	}
	reverse(b.begin(),b.end());
	for(auto x : arr){
		if(x==0){
			cout << b.back() << " ";
			b.pop_back();
		}else{
			cout << x << " ";
		}
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}