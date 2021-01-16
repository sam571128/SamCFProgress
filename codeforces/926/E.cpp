#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	stack<int> s;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		while(!s.empty()&&s.top()==tmp)
			s.pop(), tmp++;
		
		s.push(tmp);
	}
	cout << s.size() << "\n";
	vector<int> v;
	while(!s.empty()) v.push_back(s.top()), s.pop();
	reverse(v.begin(),v.end());
	for(auto x : v) cout << x << " ";
}