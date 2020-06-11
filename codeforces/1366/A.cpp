#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(a>b) swap(a,b);
	if(a*2<=b){
		cout << a << "\n";
		return;
	}
	int x = b-a;
	int ans = 0;
	ans += x;
	b-=2*x ;
	a-=x;
	ans += a/3*2 + (a%3==2);
	cout << ans << "\n";
}

int main(){
	//fastio
	int t;
	cin >> t;
	while(t-- ) solve();
}