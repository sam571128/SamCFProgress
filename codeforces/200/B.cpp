#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	long double sum = 0;
	for(int i = 0;i < a;i++){
		int temp;
		cin >> temp;
		sum+=temp;
	}
	cout << setprecision(13)<<sum/a;
}