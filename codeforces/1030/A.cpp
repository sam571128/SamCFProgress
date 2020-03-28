#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	while(a--){
		int temp;
		cin >> temp;
		if(temp==1){
			cout<<"HARD";
			return 0;
		}
	}
	cout << "EASY";
}