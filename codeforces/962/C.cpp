#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ans = 1e9;
void dfs(string s,int i = 0, int cnt = 0){
	if(s=="") return;
	if(s[0]!='0'&&trunc(sqrt(stoll(s)*1.0))==sqrt(stoll(s)*1.0)){
		ans = min(ans,cnt);
	}
	if(i==s.size()) return;
	dfs(s,i+1,cnt);
	s.erase(i,1);
	dfs(s,i,cnt+1);
}

int main(){
	fastio
	string s;
	cin >> s;
	dfs(s);
	if(ans==1e9) cout << "-1" << "\n";
	else cout << ans << "\n";
}