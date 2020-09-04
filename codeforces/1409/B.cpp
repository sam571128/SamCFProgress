#include <bits/stdc++.h>

#define int long long
#define x first
#define y second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	pair<int,int> a,b;
	int n;
	cin >> a.x >> b.x >> a.y >> b.y >> n;
	if(a < b) swap(a,b);
	cout << min(max(b.y,b.x-n)*max(a.y,(a.x-(n-(b.x-max(b.y,b.x-n))))),max(a.y,a.x-n)*max(b.y,(b.x-(n-(a.x-max(a.y,a.x-n)))))) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}