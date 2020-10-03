#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a,t,c,g;
signed main(){
	fastio
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0;i < n;i++){
		a = t = c = g = 0;
		for(int j = i;j < n;j++){
			if(s[j]=='A') a++;
			if(s[j]=='T') t++;
			if(s[j]=='C') c++;
			if(s[j]=='G') g++;
			if(a==t&&c==g) ans++;
		}
	}
	cout << ans << "\n";
}