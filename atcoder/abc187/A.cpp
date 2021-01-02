#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dSum(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}

signed main(){
	fastio
	int a,b;
	cin >> a >> b;
	a = dSum(a), b = dSum(b);
	cout << max(a,b) << "\n";
}