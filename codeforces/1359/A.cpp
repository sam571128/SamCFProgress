#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	if(n/k>=m){
		cout << m << "\n";
		return;
	}
	else{
		int ma = n/k; 
		m -= ma; 
		int mi = ceil(1.0*m/(k-1));
		if(ma!=mi) cout << ma - mi << "\n";
		else cout << 0 << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}