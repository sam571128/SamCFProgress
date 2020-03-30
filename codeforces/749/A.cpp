#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	cini(a);
	int count;
	if(a%2==0){
		count = a/2;
		cout << count << "\n";
		for(int i = 0;i < count;i++){
			cout << "2 ";
		}
	}else{
		count=(a-3)/2;
		cout << count+1 << "\n";
		for(int i = 0;i < count;i++){
			cout << "2 ";
		}
		cout << "3";
	}
	
}