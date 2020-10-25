#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	n*=2;
	set<int> s;
	vector<int> ans;
	vector<pair<char,int>> v;
	while(n--){
		char c;
		int val = 0;
		cin >> c;
		if(c=='-'){
			cin >> val;
		}
		v.push_back({c,val});
	}
	while(!v.empty()){
		auto [c,val] = v.back();
		v.pop_back();
		if(c=='+'){
			if(s.empty()){
				cout << "NO\n";
				return 0;
			}
			ans.push_back(*s.begin());
			s.erase(*s.begin());
		}else{
			if(!s.empty()&&val > *s.begin()){
				cout << "NO\n";
				return 0;
			}else{
				s.insert(val);
			}
		}
	}
	cout << "YES\n";
	reverse(ans.begin(),ans.end());
	for(auto x : ans) cout << x << " ";
}