#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v1, v2; //v1 for a, v2 for b
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i]=='a'){
			v1.push_back(i);
			ans = max(ans,(v2.size() <= k ? i+1 : i-v2[v2.size()-1-k]));
		}else{
			v2.push_back(i);
			ans = max(ans,(v1.size() <= k ? i+1 : i-v1[v1.size()-1-k]));
		}
	}
	cout << ((v1.size() <= k || v2.size() <= k) ? n : ans) << "\n";
}