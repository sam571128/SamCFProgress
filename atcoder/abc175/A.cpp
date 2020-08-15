#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int ans = 0, tt = -1, t = 0;
	for(int i = 0;i < (int)s.size();i++){
		if(tt){
			if(s[i]=='R') t++;
		}else if(s[i]=='R'){
				t = 1;
				tt = 1;
		}
		if(s[i]=='S'){
			t = 0;
			tt = 0;
		}
		ans = max(t,ans);
	}
	ans = max(t,ans);
	cout << ans << "\n";
}