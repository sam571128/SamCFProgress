#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int i = 0;i <= 1000/3+1;i++){
		if(i*3>n) break;
		for(int j = 0;j <= 1000/5;j++){
			if(i*3+j*5>n) break;
			for(int k = 0;k <= 1000/7+1;k++){
				if(i*3+j*5+k*7>n) break;
				if(i*3+j*5+k*7==n){
					cout << i << " " << j << " " << k << "\n";
					return;
				}
			}
		}
	}
	cout << -1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}