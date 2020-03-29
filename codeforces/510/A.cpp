#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int count = 1; // Right => 1, rDown => 2, Left => 3, lDown => 0
	int a,b;
	cin >> a >> b;
	for(int i = 0;i < a;i++){
		if(count ==1){
			for(int j = 0;j < b;j++){
				cout << "#";
			}
			cout << "\n";
		}else if(count==2){
			for(int j = 0;j < b-1;j++){
				cout << ".";
			}
			cout << "#";
			cout << "\n";
		}else if(count==3){
			for(int j = 0;j < b;j++){
				cout << "#";
			}
			cout << "\n";
		}else if(count==0){
			cout << "#";
			for(int j = 1;j < b;j++){
				cout << ".";
			}
			cout << "\n";
		}
		count=(count+1)%4;
	}  
}