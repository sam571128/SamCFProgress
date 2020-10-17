#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 1;i*i <= n;i++){
		if(n%i==0){
			v.push_back(i);
			if(i*i!=n) v.push_back(n/i);// << "\n";
		}
	}
	sort(v.begin(),v.end());
	for(auto x : v) cout << x << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}