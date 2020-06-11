#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x,m;
	cin >> n >> x >> m;
	int l = x, r = x;
	for(int i = 0;i < m;i++){
		int nl, nr;
		cin >> nl >> nr;
		if(r<=nr&&nl<=r) r = nr;
		if(l>=nl&&nr>=l) l = nl;
	}
	cout << r-l+1 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}