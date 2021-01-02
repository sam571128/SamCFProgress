#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int arr[32];
signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int ans = 0;
	memset(arr,0x3f3f3f,sizeof arr);
	for(int i = 0;i < n;i++) cin >> arr[i];
	for(int i = 0;i < 31;i++){
		if(2LL*arr[i] < arr[i+1]) arr[i+1] = 2LL*arr[i];
	}
	//for(int i = 0;i < 32;i++) cout << arr[i] << " ";
	bitset<32> bs;
	bs = m;
	set<int> s;
	for(int i = 31;~i;i--){
		if(bs[i]) ans += arr[i];
		else s.insert(ans+arr[i]);
	}
	s.insert(ans);
	cout << *s.begin() << "\n";
}