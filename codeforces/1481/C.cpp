#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int arr[n], arr2[n];
	vector<int> c[n+1];
	int cc[n+1];
	fill(cc,cc+n+1,-1);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i < n;i++){
		cin >> arr2[i];
		if(arr[i]!=arr2[i]) c[arr2[i]].push_back(i);
		if(arr[i]==arr2[i]) cc[arr[i]] = i;
	}
	vector<int> q;
	while(m--){
		int tt;
		cin >> tt;
		q.push_back(tt);
	}
	vector<int> ans;
	reverse(q.begin(), q.end());
	for(int i = 0;i < q.size();i++){
		if(c[q[i]].empty()){
			if(ans.empty()&&cc[q[i]]==-1){
				cout << "NO\n";
				return;
			}else{
				if(~cc[q[i]]) ans.push_back(cc[q[i]]);
				else ans.push_back(ans.back());
			}
		}else{
			ans.push_back(c[q[i]].back()); c[q[i]].pop_back();
		}
	}
	bool ok = true;
	for(auto v : c){
		if(!v.empty()) ok = false;
	}
	if(ok){
		cout << "YES\n";
		for(int i = ans.size()-1;~i;i--) cout << ans[i]+1 << " ";
		cout << "\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}