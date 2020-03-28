#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int k,l,m,n,d;
	cin >> k >> l >> m >> n >> d;  
	int count = d;
	for(int i = 1;i <= d;i++){
		if(i%k!=0&&i%l!=0&&i%m!=0&&i%n!=0){
			count--;
		}
	}
	cout << count;
}