#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n);
		n = (n * n);
		p>>=1;
	}
	return res;
}


void solve(){
	string str;
	int n,s;
	cin >> str >> s;
	n = stoll(str);
	int sum = 0;
	for(int i = 0;i < str.size();i++){
		if(sum+(str[i]-'0')>s) {
			cout << (n/(int)fastpow(10,str.size()-i)+1)*(int)fastpow(10,str.size()-i)-n << "\n";
			return;
		}
		else if(sum+(str[i]-'0')==s){
			if((n/(int)fastpow(10,str.size()-i-1))*(int)fastpow(10,str.size()-i-1)==n) cout << 0 << "\n";
			else cout << (n/(int)fastpow(10,str.size()-i)+1)*(int)fastpow(10,str.size()-i)-n << "\n";
			return;
		}
		sum+=str[i]-'0';
	}
	cout << 0 << "\n";
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}