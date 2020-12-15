#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	deque<int> v;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	int s = 1;
	while(!v.empty()){
		if(s){
			cout << v.front() << " ";
			v.pop_front();
		}
		else{
			cout << v.back() << " ";
			v.pop_back();
		}
		s^=1;
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}