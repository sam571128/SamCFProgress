#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y,n;
	cin >> x >> y >> n;
	int tmp = (n/x)*x;
	tmp+=y;
	if(tmp>n) tmp-=x;
	cout << tmp << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}