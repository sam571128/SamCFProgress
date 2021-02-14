#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e4+5;

void solve(){
	int n;
	cin >> n;
	int cnt[N] = {};
	vector<int> v;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		cnt[tmp]++;
		if(cnt[tmp]==2) v.push_back(tmp), cnt[tmp] = 0;
	}
	vector<pair<int,int>> v2;
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size()-1;i++){
		v2.push_back({v[i],v[i+1]});
	}
	sort(v2.begin(),v2.end(), [&](pair<int,int> a, pair<int,int> b){
		return (a.first*a.first+a.second*a.second)*(b.first*b.second) < (b.first*b.first+b.second*b.second)*(a.first*a.second);
	});
	auto [a,b] = v2[0];
	cout << a << " " << a << " " << b << " " << b << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}