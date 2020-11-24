#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int arr[n+m+1] = {};
	for(int i = 1;i <= n;i++){
		for(int j = 1, tmp;j <= m;j++){
			cin >> tmp;
			arr[i+j]^=tmp;
		}
	}
	int ans = 1;
	for(int i = 1;i <= n+m;i++){
		ans &= (arr[i]==0);
	}
	if(ans){
		cout << "Jeel\n";
	}else{
		cout << "Ashish\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}