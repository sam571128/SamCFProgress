#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n==1) { cout << s << "\n";return;}
	for(int i = 1;i < n;i++){
		if(s[i]<s[i-1]) break;
		if(i==n-1){
			cout << s << "\n";
			return;
		}
	}
	int cntz = 0, check = 0;
	int cnto = 0;
	for(int i = 0;i < n;i++){
		if(s[i]=='1') cnto++, check = 1;
		else{
			if(!check)cntz++;
			cnto = 0;
		}
	}
	for(int i = 0;i <= cntz;i++) cout << 0;
	for(int i = 0;i < cnto;i++) cout << 1;
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}