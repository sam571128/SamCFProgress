#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int sum = 0;
	int Max = 0;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		Max = max(tmp,Max);
		sum+=tmp;
	}
	cout << max(sum/(n-1)+(sum%(n-1)?1:0),Max);
}