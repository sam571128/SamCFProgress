#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	int m;
	cin >> m;
	vector<pair<int,int>> v; //cost, type
	for(int i = 0;i < m;i++){
		int a;
		string b;
		cin >> a >> b;
		v.push_back({a,b[0]=='P'});
	}
	sort(v.begin(),v.end());
	int ans = 0, num = 0;
	for(auto x : v){
		if(x.second==0){
			if(a) a--, num++, ans += x.first;
			else if(c) c--, num++, ans += x.first;
		}else{
			if(b) b--, num++, ans += x.first;
			else if(c) c--, num++, ans += x.first;
		}
	}
	cout << num << " " << ans << "\n";
}