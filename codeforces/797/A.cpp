#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	vector<int> v;
	for(int i = 2;i <= n;i++){
		if(v.size()==k-1&&n!=1){
			for(auto x : v) cout << x << " ";
			cout << n << "\n";
			return 0;
		}
		while(n%i==0){
			v.push_back(i), n/=i;
			if(v.size()==k-1&&n!=1){
				for(auto x : v) cout << x << " ";
				cout << n << "\n";
				return 0;
			}
		}
	}
	if(v.size()==k){
		for(auto x : v) cout << x << " ";
		return 0;
	}
	cout << -1 << "\n";
}