#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int pref[n+1] = {}, suff[n+1] = {};
	pref[1] = arr[0], suff[n-1] = arr[n-1];
	for(int i = 2;i <= n;i++){
		pref[i] = arr[i-1];
		if(pref[i-1]<0) pref[i] = -1;
		else pref[i] -= pref[i-1];
	}	
	for(int i = n-2;~i;i--){
		suff[i] = arr[i];
		if(suff[i+1]<0) suff[i] = -1;
		else suff[i] -= suff[i+1];
	}
	if(pref[n] == 0){
		cout << "YES\n";
		return;
	}
	for(int i = 0;i < n-1;i++){
		int a = pref[i], b = arr[i+1], c = arr[i], d = suff[i+2];
		if(a < 0 || d < 0) continue;
		b -= a, c -= d;
		if(b < 0 || c < 0) continue;
		if(b-c!=0) continue;
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}