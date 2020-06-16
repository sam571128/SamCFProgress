#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i+=2){
		cout << s[i];
	}
	cout << s.back();
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}