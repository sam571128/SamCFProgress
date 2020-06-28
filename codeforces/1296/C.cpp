#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<pair<int,int>,int> m;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0, r = n;
	pair<int,int> now = {0,0};
	m[now] = 0;
	for(int i = 1;i <= n;i++){
		//cout << now.first << " " << now.second << "\n";
		if(s[i-1]=='U') now.second++;
		if(s[i-1]=='D') now.second--;
		if(s[i-1]=='R') now.first++;
		if(s[i-1]=='L') now.first--;
		if(m.count(now)){
			if(r - l > i-(m[now]+1)){
				l = m[now]+1;
				r = i;
			}
		}
		m[now] = i;
	}
	if(r-l==n){
		cout << -1 << "\n";
	}else
		cout << l << " " << r << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}