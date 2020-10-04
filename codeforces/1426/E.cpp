#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << min(max(0,a-d-f),e)+min(max(0,b-e-d),f)+min(max(0,c-f-e),d) <<" " << min(a,e)+min(b,f)+min(c,d);
}