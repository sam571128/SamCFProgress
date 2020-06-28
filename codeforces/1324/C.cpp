#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int last = -1, ma = INT_MIN;
	for(int i = 0;i < n;i++){
		if(s[i]=='R') ma = max(ma,i-last), last = i;
	}
	ma = max(ma, n-last);
	cout << ma << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}