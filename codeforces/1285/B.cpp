//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n], sum = 0;
	vector<int> pref(n+1,0);
	for(int i = 0; i < n;i++){
		cin >> a[i];
		sum += a[i];
		pref[i+1] += pref[i] + a[i];
	}
	int tmp = 0;
	set<int> s;
	s.insert(0);
	bool hasz = 0;
	for(int i = 0;i < n;i++){
		tmp += a[i];
		if(tmp==0) hasz = 1;
		//cout << -tmp << " " << -tmp+sum << "\n";
		if(!hasz&&i==n-1) s.erase(0);
		auto itr = s.lower_bound(-tmp+sum);
		if(itr!=s.end()){
			cout << "NO\n";
			return;
		}
		s.insert(-tmp);
		
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}