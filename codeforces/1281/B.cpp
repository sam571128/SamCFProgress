//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	string tmp = s;
	sort(tmp.begin(),tmp.end());
	for(int i = 0;i < n;i++){
		if(s[i]!=tmp[i]){
			for(int j = n-1;j > i;j--){
				if(s[j]==tmp[i]){
					swap(s[i],s[j]);
					goto out;
				}
			}
		}
	}
	out:;
	if(s >= t) cout << "---\n";
	else cout << s << "\n";

}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}