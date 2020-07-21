#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	set<int> s;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		s.insert(tmp);
	}
	bool ok = false;
	int ans = 0;
	for(int i = 0, tmp;i < m;i++){
		cin >> tmp;
		if(s.find(tmp)!=s.end()){
			ans = tmp;
			ok = true;
		}
	}
	if(ok){
		cout << "YES\n";
		cout << 1 << " " << ans << "\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}