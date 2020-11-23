#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	int z = -1 , o = -1, z2 = n, o2 = n;
	for(int i = 0;i < n;i++){
		if(s[i]=='0') z2 = i;
		else if(s[i]=='1') o2 = i;
 		if(!~z&&s[i]=='0') z = i;
		else if(!~o&&s[i]=='1') o = i; 
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		l--,r--;
		bool check1 = (z==l&&s[l]=='0')||(o==l&&s[l]=='1');
		bool check2 = (z2==r&&s[r]=='0')||(o2==r&&s[r]=='1');
		if(check1&&check2) cout << "NO\n";
		else cout << "YES\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}