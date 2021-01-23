#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	map<string,int> a,b;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		string tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for(int i = 0;i < n;i++){
		string tmp;
		cin >> tmp;
		b[tmp]++;
	}
	int ans = n;
	for(auto [x,y] : a){
		ans -= min(y,b[x]);
	}
	cout << ans << "\n";
}