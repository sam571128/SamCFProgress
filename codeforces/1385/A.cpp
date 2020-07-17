#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int ma = max({a,b,c});
	int mi = min({a,b,c});
	int cnt = 0;
	if(a==ma) cnt++;
	if(b==ma) cnt++;
	if(c==ma) cnt++;
	if(cnt < 2){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << mi << " " << ma << " " << 1 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}