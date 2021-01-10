#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



const int N = 2e5+5;
set<pair<int,int>> bids[N];
int has[N];

set<pair<int,int>> winners;

signed main(){
	//fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a,b;
		cin >> a >> b;
		bids[a].insert({i,b});
		has[a] = i;
	}
	for(int i = 1;i <= n;i++){
		if(has[i]) winners.insert({has[i],i});
	}
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		vector<int> v;
		for(int i = 0;i < k;i++){
			int tmp;
			cin >> tmp;
			if(has[tmp]) winners.erase({has[tmp],tmp}),v.push_back(tmp);
		}
		if(winners.size()==0) cout << 0 << " " << 0 << '\n';
		else{
			cout << (*winners.rbegin()).second << " ";
			if(winners.size()==1){
				cout << (*bids[(*winners.rbegin()).second].begin()).second << "\n";
			}else{
				cout << (*bids[(*winners.rbegin()).second].upper_bound({has[(*next(winners.rbegin())).second],0})).second << "\n";
			}
		}
		for(auto x : v) winners.insert({has[x],x});
	}
}