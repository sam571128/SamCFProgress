#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool done = false;
int x;
string ans[51];
void dfs(int now, string s, int used){
	if(done) return;
	if(now==x){
		sort(s.begin(),s.end());
		ans[x] = s;
		cout << s << "\n";
		done = true;
		return;
	}
	for(int i = 9;i;i--){
		if(used&(1<<i)) continue;
		dfs(now+i,s+to_string(i),used|(1<<i));
	}
}

void solve(){
	done = false;
	cin >> x;
	if(ans[x]!=""){
		cout << ans[x] << "\n";
		return;
	}
	dfs(0,"",0);
	if(!done){
		cout << -1 << "\n";
		ans[x] = "-1";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}