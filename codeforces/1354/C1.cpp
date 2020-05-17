#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const double PI = 3.14159265;
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		double n;
		cin >> n;
		n*=2;
		cout << fixed << setprecision(8) << tan(2*(n-2)/n/4*PI) << "\n";
	}
}