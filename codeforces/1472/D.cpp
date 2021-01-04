#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	vector<int> odd, even;
	int x = 0, y = 0;
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp&1) odd.push_back(tmp), x += tmp;
		else even.push_back(tmp), y += tmp;
	}
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());
	int a = 0, b = 0;
	for(int i = 0;i < n;i++){
		if(i%2==0){
			if((!odd.empty()&&!even.empty()&&even.back() <= odd.back())||even.empty()) x-=odd.back(), odd.pop_back();
			else a += even.back(), y -= even.back(), even.pop_back();
		}else{
			if((!even.empty()&&!odd.empty()&&odd.back() <= even.back())||odd.empty()) y-=even.back(), even.pop_back();
			else b += odd.back(), x -= odd.back(), odd.pop_back();
		}
	}
	if(a > b) cout << "Alice\n";
	else if(a < b) cout << "Bob\n";
	else cout << "Tie\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}
