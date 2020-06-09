#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll int n,m;
	cin >> n >> m;
	ll int ma = n-(m-1);
	ll int mi = n/m;
	cout << (m-n%m)*mi*(mi-1)/2+(mi+1)*mi*(n%m)/2 << " " << ma*(ma-1)/2;
}