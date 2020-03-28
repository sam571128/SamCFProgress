#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	string b = "";
	for(int i = 0;i < a;i++){
		if(i==a-1){
			if(i%2==0){
				b += "I hate it";
			}else{
				b += "I love it";
			}	
		}else{
			if(i%2==0){
				b += "I hate that ";
			}else{
				b += "I love that ";
			}
		}
	}
	cout << b;
}