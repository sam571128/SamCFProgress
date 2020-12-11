#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int sorted[n] = {};
	int arr[n];
	for(auto &x : arr) cin >> x;
	bool done = false;
	for(int i = n-1;~i;i--){
		if(arr[i]==i+1) sorted[i-1] = true;
		else break;
		if(i==0){
			done = true;
			//return;
		}
	}
	sorted[n-1] = true;
	double tmp = 1;
	while(m--){
		int a;
		double p;
		cin >> a >> p;
		if(sorted[a-1]){
			tmp *= 1-p;
		}
	}
	cout << setprecision(10) << fixed << (done ? 1 : 1-tmp) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}