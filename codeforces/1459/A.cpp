#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> v(n,0);
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(s1[i] < s2[i]) cnt--;
		else if(s1[i] > s2[i]) cnt++;
	}
	if(cnt > 0){
		cout << "RED\n";
	}else if(cnt < 0){
		cout << "BLUE\n";
	}else{
		cout << "EQUAL\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}