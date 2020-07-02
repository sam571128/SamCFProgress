#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int main(){
	fastio
	int n;
	cin >> n;
	int r[n], b[n];
	for(auto &x : r) cin >> x;
	for(auto &x : b) cin >> x;
	int s1 = 0,s2 = 0;
	for(int i = 0;i < n;i++){
		if(r[i] > b[i]) s1++;
		else if(r[i] < b[i]) s2++;
	}
	if(s1==0) cout << -1 << "\n";
	else cout << s2/s1+1 << "\n";
}