#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			for(int k = j+1;k < n;k++){
				if((v[i].first-v[j].first)*(v[j].second-v[k].second)==(v[j].first-v[k].first)*(v[i].second-v[j].second)){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	cout << "No\n";
}