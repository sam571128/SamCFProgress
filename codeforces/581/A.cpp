#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a,b;
	cin >> a >> b;
	cout << min(a,b) << " " <<(max(a,b)-min(a,b))/2;
}