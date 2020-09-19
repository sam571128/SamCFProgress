#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	int oo = 0, ee = 0 , oe = 0, eo = 0;
	for(int i = 0;i < n;i++){
		if(i&1^1){
			if((s[i]-'0')%2==1) oo++;
			else oe++;
		}else {
			if((s[i]-'0')%2==1) eo++;
			else ee++;
		}
	}
	if(n&1){
		cout << (oo ? "1\n" : "2\n");
	}else{
		cout << (ee ? "2\n" : "1\n");
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}