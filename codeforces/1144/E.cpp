#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int k;
	cin >> k;
	string s,t;
	cin >> s >> t;
	int as[k+1], at[k+1];
	as[0] = 0, at[0] = 0;
	for(int i = 0;i < k;i++){
		as[i+1] = s[i]-'a';
	}
	for(int i = 0;i < k;i++){
		at[i+1] = t[i]-'a';
	}
	for(int i = k; ~i;--i){
		as[i] += at[i];
		if(i!=0){
			as[i-1] += as[i]/26;
			as[i]%=26;
		}
	}

	for(int i = 0;i <= k;i++){
		int tt = as[i]%2;
		as[i] /= 2;
		if(i<k) as[i+1] += tt*26;
	}
	for(int i = 1;i <= k;i++) cout << char(as[i]+'a');
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}