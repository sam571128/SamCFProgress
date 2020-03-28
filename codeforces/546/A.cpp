#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	int sum = a;
	for(int i = 2;i <= c;i++){
		sum+= i*a;
	}
	cout << ((b-sum)<0 ? (-b+sum):0);
}