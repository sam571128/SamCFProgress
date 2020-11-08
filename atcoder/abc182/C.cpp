#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


signed main(){
	fastio
	int n;
	cin >> n;
	int cnt[3] = {};
	int tmp = 0;
	while(n){
		cnt[(n%10)%3]++;
		n/=10;
		tmp++;
	}
	int ans1 = max(cnt[1]-min(cnt[1],cnt[2]),cnt[2]-min(cnt[1],cnt[2]))%3;
	cnt[1]%=3, cnt[2]%=3;
	int ans2 = max(cnt[1]-min(cnt[1],cnt[2]),cnt[2]-min(cnt[1],cnt[2]))%3;
	cout << (min(ans1,ans2)==tmp ? -1 : min(ans1,ans2)) << "\n";
}