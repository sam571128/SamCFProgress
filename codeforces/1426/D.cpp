#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	map<int,int> m;
	int now = 0, ans = 0;
	m[0] = 1;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		now+=tmp;
		if(m[now]){
			m.clear();
			ans++;
			now = tmp;	
			m[0]++;		
		}
		m[now]++;
	}
	cout << ans << "\n";
}