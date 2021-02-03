#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,d;
	cin >> n >> d;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(d==1){
			cout << "YES\n";
			continue;
		}
		if(tmp >= 10*d){
			cout << "YES\n";
			continue;
		}
		if(tmp % d == 0){
			cout << "YES\n";
			continue;
		}
		while(tmp%d!=0&&tmp >= 10){
			tmp -= 10;
		}
		if(tmp%d==0&&tmp) cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}