#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> s;
signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(),s.end());
	while(m--){
		int q;
		cin >> q;
		cout << (upper_bound(s.begin(),s.end(),q)-s.begin()) << " ";
	}
}