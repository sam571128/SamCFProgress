#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int arr[n][m];
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> arr[i][j];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if((arr[i][j]+i+j)&1) arr[i][j]++;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << arr[i][j] << " ";
		}	
		cout << "\n";
	} 
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}
