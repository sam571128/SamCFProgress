#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	ll last = -1;
	bool ok = true;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(last == -1) last = tmp;
		else if((last-tmp)&1){
			ok = false;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}