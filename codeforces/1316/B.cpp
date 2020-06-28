#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string maxs = s;
	ll ans = 1;
	for(int k = 1;k <= n;k++){
		string tmp = s.substr(k);
		string rev = s.substr(0,k);
		if((n-k)&1) reverse(rev.begin(),rev.end());
		tmp += rev;
		if(tmp < maxs){
			maxs = tmp;
			ans = k+1;
		}
	}
	cout << maxs << '\n' << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}	