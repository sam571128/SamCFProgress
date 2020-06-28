#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> ff,ss;
	ss.push_back(0);
	for(int i = 0;i < s.size();i++){
		if(s[i]=='1'){
			ss.push_back(i+k+1);
			ff.push_back(i-k-1);
		}
	}
	ff.push_back(n-1);
	int ans = 0;
	for(int i = 0;i < ss.size();i++){
		int m = (ff[i]+k+1-ss[i])/(k+1);
		ans += max(m,0);
	}
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}