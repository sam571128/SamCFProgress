#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<int,int> m;
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		m[tmp]++;
		if(m[tmp]>=3){
			cout << "No\n";
			return;
		}
	}
	vector<int> v1, v2;
	for(auto &[a,b] : m){
		v1.push_back(a); b--;
	}
	for(auto &[a,b] : m){
		if(b) v2.push_back(a);
	}
	cout << "Yes\n";
	cout << v1.size() << "\n";
	if(!v1.empty())for(auto x : v1) cout << x << " ";
	cout << "\n" << v2.size() << "\n";
	if(!v2.empty())for(int i = v2.size()-1;~i;i--) cout << v2[i] << " ";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}