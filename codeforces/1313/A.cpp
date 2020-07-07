#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int ans = 0;
	if(a < b) swap(a,b);
	if(a < c) swap(a,c);
	if(b < c) swap(b,c);
	if(a) a--, ans++;
	if(b) b--, ans++;
	if(c) c--, ans++;
	if(a&&b) a--,b--,ans++;
	if(a&&c) a--,c--,ans++;
	if(b&&c) b--,c--,ans++;
	if(a&&b&&c) a--,b--,c--,ans++;
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}