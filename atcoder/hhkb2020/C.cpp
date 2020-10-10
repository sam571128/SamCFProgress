#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	set<int> s;
	for(int i = 0;i <= 200000;i++) s.insert(i);
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		s.erase(tmp);
		cout << *s.begin() << "\n";
	}
}