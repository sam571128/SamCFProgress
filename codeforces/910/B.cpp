#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> arr = {a,a,a,a,b,b};
	sort(arr.begin(),arr.end());
	int ans = INT_MAX;
	do{
		int now = n, tmp = 1;
		for(auto x : arr){
			if(now >= x) now -= x;
			else{
				now = n-x, tmp++;
			}
		}
		ans = min(tmp,ans);
	}while(next_permutation(arr.begin(),arr.end()));
	cout << ans << '\n';
}