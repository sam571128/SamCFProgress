#include <bits/stdc++.h>
#include <vector>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int sum = 0;
	int cap = 0;
	while(n--){
		int a,b;
		cin >> a >> b;
		sum-=a;
		sum+=b;
		cap = max(cap,sum);
	}
	cout << cap;
}