#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = 0, ma = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		sum+=tmp;
		ma = max(tmp,ma);
	}
	if(n==1){
		cout << "T\n";
		return;
	}else if(ma*2>sum){
		cout << "T\n";
		return;
	}else{
		if(sum%2) cout << "T\n";
		else cout << "HL\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}