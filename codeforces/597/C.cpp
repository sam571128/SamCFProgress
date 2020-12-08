#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;

struct BIT{
	int arr[N] = {};
	void update(int pos, int val){
		while(pos < N){
			arr[pos] += val;
			pos += pos&-pos;
		}
	}
	int query(int pos){
		if(pos==0) return 0;
		int res = 0;
		while(pos){
			res += arr[pos];
			pos -= pos&-pos;
		}
		return res;
	}
} bit[15];

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int ans = 0;
	if(k==0) ans = 1;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		for(int j = 1;j <= k;j++){
			if(j==k){
				ans += bit[j-1].query(tmp-1);
			}else{
				bit[j].update(tmp,bit[j-1].query(tmp-1));
			}
		}
		bit[0].update(tmp,1);
	}
	cout << ans << "\n";
}