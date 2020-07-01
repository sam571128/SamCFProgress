#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll a,b,n,m;
	cin >> a >> b >> n >> m;
	if(min(a,b) >= m&&n+m <= a+b) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}