#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string a,b;
	cin >> a >> b;
	if(a.size()>b.size()) swap(a,b);
	int n = a.size(), m = b.size();
	int t = lcm(n,m);
	string ta = a;
	while(ta.size() < t){
		ta += a;
	}
	int j = 0;
	for(int i = 0;i < t;i++,j=(j+1)%m){
		if(ta[i]!=b[j]){
			cout << "-1\n";
			return;
		}
	}
	cout << ta << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}