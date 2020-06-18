#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll a,b,n,ans = 0;
	cin >> a >> b >> n;
	while(a<=n&&b<=n)
		if(a<b) a+=b,ans++;
		else b+=a,ans++;
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}