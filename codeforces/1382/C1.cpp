#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	char tmp;
	vector<int> v;
	for(int i = 0;i < n;i++) cin >> tmp, a[i] = tmp-'0';
	for(int i = 0;i < n;i++) cin >> tmp, b[i] = tmp-'0';
	for(int i = n-1;i > 0;i--){
		if(a[i]!=b[i]){
			if(a[i]!=a[0]) v.push_back(1), a[0] = a[i];
			v.push_back(i+1);
			int l = 0, r = i;
			while(l < r) swap(a[l],a[r]),l++, r--;
			for(int j = 0;j < i;j++) a[j]^=1; 
		}
	}
	if(a[0]!=b[0]) v.push_back(1);
	cout << v.size() << " ";
	for(auto x : v) cout << x << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}