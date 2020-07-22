#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		string a,b;
		cin >> n >> a >> b;
		a+='0',b+='0';
		vector<int> ans1, ans2;
		for(int i = 1;i <= n;i++){
			if(a[i]!=a[i-1]) ans1.push_back(i);
			if(b[i]!=b[i-1]) ans2.push_back(i);
		}
		ans1.insert(ans1.end(),ans2.rbegin(),ans2.rend());
		cout << ans1.size() << " ";
		for(auto x : ans1) cout << x << " ";
		cout << "\n";
	}
}