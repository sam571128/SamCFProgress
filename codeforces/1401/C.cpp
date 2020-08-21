#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	int tmp[n];
	for(int i = 0;i < n;i++) tmp[i] = a[i];
	sort(tmp,tmp+n);
	for(int i = 0;i < n;i++){
		if(tmp[i]!=a[i]){
			if(a[i]%tmp[0]!=0){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}