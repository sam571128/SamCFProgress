#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[(1<<n)];
	for(auto &x : arr) cin >> x;
	int ma1 = 0, idx1 = 0, ma2 = 0, idx2 = 0;
	for(int i = 0;i < (1<<n);i++){
		if(i < (1<<n-1)){
			if(ma1 < arr[i]){
				ma1 = arr[i];
				idx1 = i;
			}
		}else{
			if(ma2 < arr[i]){
				ma2 = arr[i];
				idx2 = i;
			}
		}
	}
	cout << (ma1 > ma2 ? idx2 : idx1)+1 << "\n";
}