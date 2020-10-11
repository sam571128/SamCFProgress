#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	cout << 2 << "\n";
	if(n==2){
		cout << 1 << " " << 2 << "\n";
		return;
	}
	vector<int> v;
	for(int i = 1;i < n;i++){
		if(i!=n-2) v.push_back(i);
	}
	cout << n-2 << " " << n << "\n";
	int num = n-1;
	while(!v.empty()){
		cout << num << " " << v.back() << "\n"; 
		num = (num+v.back()+1)/2;
		v.pop_back(); 
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}