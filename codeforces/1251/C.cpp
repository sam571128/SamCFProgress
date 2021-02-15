#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	string e = "", o = "";
	for(auto c : s){
		if((c-'0')&1) o.push_back(c);
		else e.push_back(c);
	}
	string ans = "";
	int i = 0, j = 0;
	while(i < e.size()||j < o.size()){
		if(i >= e.size()){
			ans += o[j];
			j++;
		}else if(j >= o.size()){
			ans += e[i];
			i++;
		}else if(o[j] > e[i]){
			ans += e[i];
			i++;
		}else{
			ans += o[j];
			j++;
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}