#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++) cin >> a[i];
	int tmp = a[n-1]-a[0];
	for(int i = 1;i < n-1;i++){
		if(a[i] <= tmp){
			cout << 1 << " " << i+1 << " " << n << "\n";
			return;	
		}
		else break;
	}
	cout << -1 << "\n";	
}


signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}