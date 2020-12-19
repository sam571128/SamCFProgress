#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool decim(int n){
	bool res = true;
	while(n){
		if(n%10==7) res = false;
		n/=10;
	}
	return res;
}

bool octal(int n){
	bool res = true;
	while(n){
		if(n%8==7) res = false;
		n/=8;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(octal(i)&&decim(i)) ans++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}