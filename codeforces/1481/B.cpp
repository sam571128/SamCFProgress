#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	while(true){
		for(int i = 1;i < n;i++){
			if(arr[i] > arr[i-1]){
				arr[i-1]++, k--;
				if(k==0){
					cout << i << "\n";
					return;
				}
				goto nxt;
			}
		}
		cout << -1 << "\n";
		return;
		nxt:;
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}