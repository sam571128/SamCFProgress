#include <bits/stdc++.h>
 
#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int main(){
	fastio
	int a,b;
	cin >> a >> b;
	int count = 0;
	while(a<=b){
		count++;
		a*=3;
		b*=2;
	}
	cout << count;
}