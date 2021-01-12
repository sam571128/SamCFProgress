#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(10) << (a*d+c*b)/(b+d) << "\n";
}