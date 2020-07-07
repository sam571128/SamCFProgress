#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	cout << max(1,min(n,x+y-n+1)) << " " << min(n,x+y-1) << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}