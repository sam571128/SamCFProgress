#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0;i < n;i++){
		if(abs(s[i]-s[n-i-1]) > 2||abs(s[i]-s[n-i-1])==1){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}