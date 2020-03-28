#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int count = 0;
	while(n--){
		int a,b;
		cin >> a >> b;
		if(b-a>=2){
			count++;
		}
	}
	cout << count;
}