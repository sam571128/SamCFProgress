#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int cnt[N];

signed main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,1});
		v.push_back({y+1,-1});
	}
	v.push_back({(int)1e18+5,0});
	sort(v.begin(),v.end());
	int now = 0, x = 0;
	for(auto [l,v] : v){
		cnt[now] += l-x;
		now += v;
		x = l;
	}
	for(int i = 1;i <= n;i++) cout << cnt[i] << " ";
}