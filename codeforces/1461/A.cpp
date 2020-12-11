#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < k;i++){
		cout << 'a';
	}
	for(int i = 0;i < n-k;i++){
		cout << char('a'+(i+1)%3);
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}