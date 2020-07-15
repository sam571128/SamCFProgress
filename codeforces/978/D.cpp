#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	if(n<=2){
		cout << 0 << "\n";
		return 0;
	}
	
	int ans = INT_MAX;
	for(int d1 = -1;d1 <= 1;d1++){
		for(int d2 = -1;d2 <= 1;d2++){
			int d = arr[1]+d2-(arr[0]+d1), tmp = 0;
			bool ok = true;
			for(int i = 2;i < n;i++){
				if(abs((arr[0]+d1)+i*d-arr[i])>1){
					ok = false;
					break;
				}
				else if(abs((arr[0]+d1)+i*d-arr[i])==1) tmp++;
			}

			if(ok){
				ans = min(tmp+(d1?1:0)+(d2?1:0),ans);
			}
		}
	}
	cout << (ans==INT_MAX?-1:ans) << "\n";
}