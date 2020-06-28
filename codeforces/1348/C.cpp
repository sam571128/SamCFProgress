#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	if(s[0]!=s[k-1]){
		cout << s[k-1] << "\n";
		return;
	}
	cout << s[0];
	if(s[k]!=s[n-1]){
		for(int i = k;i < n;i++) cout << s[i];
		cout << "\n";
		return;
	}else{
		for(int i = 0;i < (n-k+k-1)/k;i++) cout << s[k];
		cout << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}