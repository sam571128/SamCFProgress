#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<int,int> m;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	int mx = 0, ele = -1;
	for(auto [a,b] : m){
		if(b > mx){
			mx = b;
			ele = a;
		}
	}
	int ind = -1, cnt = 0;
	for(int i = 0;i < n;i++){
		if(a[i] == ele) ind = i;
		else cnt++;
	}
	cout << cnt << "\n";
	for(int i = ind-1;~i;i--){
		if(a[i]==ele) continue;
		else if(a[i] > ele) cout << 2 << " " << i+1 << " " << i+2 << "\n";
		else cout << 1 << " " << i+1 << " " << i+2 << "\n";
	}
	for(int i = ind+1;i<n;i++){
		if(a[i]==ele) continue;
		else if(a[i] > ele) cout << 2 << " " << i+1 << " " << i << "\n";
		else cout << 1 << " " << i+1 << " " << i << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}