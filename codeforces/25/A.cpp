#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	int ce = 0,co = 0,le,lo;
	for(int i = 0;i < a;i++){
		int temp;
		cin >> temp;
		if(temp%2==0){
			ce++;
			le=i+1;
		}else{
			co++;
			lo=i+1;
		}
	}
	if(ce==1){
		cout << le;
	}else{
		cout << lo;
	}
}