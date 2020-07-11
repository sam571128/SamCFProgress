#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1,tmp;i <= n;i++){
		cin >> tmp;
		if(i&1&&tmp&1) ans++;
	}
	cout << ans << "\n";
}