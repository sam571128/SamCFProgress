#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,h;
	cin >> n >> h;
	int sum = 0;
	while (n--){
		int temp;
		cin >> temp;
		sum += (temp>h ? 2 : 1);
	}
	cout << sum;
}