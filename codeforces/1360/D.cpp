#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int ans = INT_MAX;
		for(int i = 1;i <= sqrt(a);i++){
			if(a%i==0){
				if(i<=b) ans = min(ans,a/i);
				if(a/i<=b) ans = min(ans,i);
			}
		}
		cout << ans << "\n";
	}
}