//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void inv(char &a){
	if(a=='B') a = 'W';
	else a = 'B'; 
}

signed main(){
	fastio
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans;
	string tmp = s;
	for(int i = 0;i < n-1;i++){
		if(tmp[i]=='B'){
			inv(tmp[i]); inv(tmp[i+1]);
			ans.push_back(i+1);
		} 
	}
	if(tmp[n-1]=='W'){
		cout << ans.size() << "\n";
		for(auto x : ans) cout << x << " ";
		return 0;
	}
	ans.clear();
	tmp = s;
	for(int i = 0;i < n-1;i++){
		if(tmp[i]=='W'){
			inv(tmp[i]); inv(tmp[i+1]);
			ans.push_back(i+1);
		} 
	}
	if(tmp[n-1]=='B'){
		cout << ans.size() << "\n";
		for(auto x : ans) cout << x << " ";
		return 0;
	}
	cout << -1 << "\n";
}