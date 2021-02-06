#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int ans = n*(n-1)/2;
	string s;
	cin >> s;
	int now = 1;
	for(int i = 1;i < n;i++){
		if(s[i]==s[i-1]) now++;
		else ans -= now, now = 1;
	}
	reverse(s.begin(),s.end());
	now = 1;
	for(int i = 1;i < n;i++){
		if(s[i]==s[i-1]) now++;
		else ans -= now-1, now = 1;
	}
	cout << ans << "\n";
}