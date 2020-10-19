#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int ma1 = 0;
	while(n--){
		int a;
		cin >> a;
		ma1 = max(a,ma1);
	}
	int m;
	cin >> m;
	int ma2 = 0;
	while(m--){
		int a;
		cin >> a;
		ma2 = max(a,ma2);
	}
	cout << ma1 << " " << ma2 << "\n";
}