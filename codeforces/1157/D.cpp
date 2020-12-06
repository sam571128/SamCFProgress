#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	if(n < k*(k+1)/2){
		cout << "NO\n";
		return;
	}
	n = n-k*(k+1)/2;
	int ans[k];
	for(int i = 0;i < k;i++){
		ans[i] = (i+1) + n/k + (i>=k-n%k);
	}
	if(n!=k-1){
		cout << "YES\n";
		for(auto x : ans) cout << x << " ";
		cout << "\n";
	}else{
		if(k==2||k==3){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			if(k!=1){
				ans[1]--;
				ans[k-1]++;
			}
			for(auto x : ans) cout << x << " ";
			cout << "\n";
		}
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}