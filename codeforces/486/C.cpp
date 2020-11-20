#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, p;
	cin >> n >> p;
	p--;
	string s;
	cin >> s;
	string t = s;
	reverse(t.begin(),t.end());
	int mi = p, ma = p;
	int l, r;
	if(p >= n/2) l = n/2, r = n;
	else l = 0, r = n/2;
	int ans = 0;
	for(int i = l;i < r;i++){
		if(t[i]!=s[i]){
			ans += min(abs(t[i]-s[i]),26-abs(t[i]-s[i]));
			ma = max(i,ma), mi = min(i,mi);
		}  
	}
	cout << ans + min(abs(p-mi)+abs(ma-mi),abs(p-ma)+abs(ma-mi)) << "\n";
}
