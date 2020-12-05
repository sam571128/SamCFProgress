#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string tmp = "", o = "110";
	if(n==1){
		if(s=="0") cout << (int)1e10 << "\n";
		else cout << (int)2e10 << "\n";
		return;
	}
	if(n==2&&s=="11"){
		cout << (int)1e10 << "\n";
		return;
	}
	while(tmp.size() <= n*2){
		tmp += o;
	}
	if(tmp.substr(0,n)==s){
		cout << (int)1e10-((n-3+2)/3) << "\n";
		return;
	}
	if(tmp.substr(1,n)==s){
		cout << (int)1e10-(n-2+2)/3 << "\n";
		return;
	}
	if(tmp.substr(2,n)==s){
		cout << (int)1e10-(n-1+2)/3 << "\n";
		return;
	}
	cout << 0 << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}