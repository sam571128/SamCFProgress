#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,q;
	cin >> n >> q;
	int num = n*n/2+n%2+1;
	while(q--){
		int x,y;
		cin >> x >> y;
		int ty = y-(x-1), tmp;
		if(ty%2==0){
			tmp = num + (ty-2)/2;
		}else{
			tmp = 1 + (ty-1)/2;
		}
		if(n%2){
			cout << tmp + (x-1)*((n+1)/2) << "\n";
		}else{
			if(ty%2) cout << tmp + ((x-1)/2+(x-1)%2) *n/2 + (x-1)/2 * (n/2+1) << "\n";
			else cout << tmp + ((x-1)/2+(x-1)%2) *(n/2+1) + (x-1)/2 * (n/2) << "\n";
		}
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}