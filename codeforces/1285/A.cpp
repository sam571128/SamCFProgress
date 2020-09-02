//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0;i < n;i++){
		if(s[i]=='L') cnt1++;
		else cnt2++;
	}
	cout << cnt1+cnt2+1 << "\n";
}