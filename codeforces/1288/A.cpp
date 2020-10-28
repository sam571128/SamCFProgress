#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const double EPS = 1e-7;

void solve(){
	int a,b;
	cin >> a >> b;
	int n = ceil(sqrt(b)), m = floor(sqrt(b));
	if((a-(n-1))*n >= b||(a-(m-1))*m >= b){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}