#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int l,r,d;
	cin >> l >> r >> d;
	cout << r/d-l/d+(l%d==0 ? 1 : 0);
}