#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	map<int,int> m1, m2;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int tmp = 0;
		for(int j = i+1;j < n;j++){
			//cout << m1[a[j]] << " " << m2[a[j]] << " " << tmp << "\n";
			if(a[i]==a[j]) ans += tmp;
			tmp -= m1[a[j]]*m2[a[j]];
			m2[a[j]]++;
			tmp += m1[a[j]]*m2[a[j]];
		}
		m1[a[i]]++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}