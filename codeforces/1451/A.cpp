#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n==1){
		cout << 0 << "\n";
	}else if(n==2){
		cout << 1 << "\n";
	}else if(n&1^1||(n==3)){
		cout << 2 << "\n";
	}else{
		cout << 3 << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}