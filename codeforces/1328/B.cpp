#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push emplace_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b; --b;
		int p1,p2;
		for(int i = a-2;~i;i--){
			if(b<a-1-i){
				p1 = i;
				p2 = a-1-b;
				break;
			}
			b-=a-1-i;
		}
		
		for(int i = 0;i < a;i++){
			if(i==p1||i==p2){
				cout<<"b";
			}else{
				cout << "a";
			}
		}
		cout << "\n";
	}
}