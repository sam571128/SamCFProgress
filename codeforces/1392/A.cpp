#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int cnt = 0, num = -1;
	set<int> s;
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		s.insert(a);
		cnt++;
	}
	if(s.size()>1){
		cout << 1 << "\n";
	}else{
		cout << cnt << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}