#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int now = 0;
	bool is = (n%400==0||(n%4==0&&n%100!=0));
	while(true){
		n++;
		if(n%400==0||(n%4==0&&n%100!=0)) now += 2;
		else now++;
		now%=7;
		if(now==0&&is==(n%400==0||(n%4==0&&n%100!=0))){
			cout << n << "\n";
			return 0;
		}
	}
}