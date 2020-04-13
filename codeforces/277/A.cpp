#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int uni[100000];
void initialize(int a[], int b){
	for(int i = 0;i < b;i++){
		a[i] = i;
	}
}

void unite(int a,int b,int n){
	int temp = uni[a];
	for(int i = 0;i < n;i++){
		if(uni[i]==temp){
			uni[i] = uni[b];
		}
	}
} 
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	initialize(uni,m);
	set<int> num;
	int count = 0;
	while(n--){
		int a;
		cin >> a;
		if(a==0) count++;
		int last;
		for(int i = 0;i < a;i++){
			cini(temp);
			temp--;
			num.insert(temp);
			if(i==0){
				last = temp;
			}else{
				unite(temp,last,m);
			}
		}
	}
	set<int> s;
	for(int i = 0;i < m;i++){
		s.insert(uni[i]);
	}
	if(s.size()!=(m-num.size())){
		cout << (s.size()-(m-num.size())-1)+count;
	}else{
		cout << count;
	}
	
}
