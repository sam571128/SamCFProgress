#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	if(n*(a-b)>c+d||n*(a+b)<c-d){
		cout << "No\n";
	}else{
		cout << "Yes\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}