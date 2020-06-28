#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,m,p;
	cin >> n >> m >> p;
	int t1 = -1, t2 = -1;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(t1 == -1 && tmp % p) t1 = i;
	}
	for(int i = 0, tmp;i < m;i++){
		cin >> tmp;
		if(t2 == -1 && tmp % p) t2 = i;
	}
	cout << t1+t2 << "\n";
}