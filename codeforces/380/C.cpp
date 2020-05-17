#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;

string a;
int n;
struct S
{
	int a,b,c; //a -> sequence length, b -> open brackets, c -> close brackets
	void print(){
		cout << a << " " << b << " " << c;
	}
}t[2*N];

S combine(S s1, S s2){
	int a = s1.a + s2.a;
	int b = s1.b + s2.b;
	int c = s1.c + s2.c;
	int tmp = min(s1.b,s2.c); //combine the open brackets from the left and close from the left
	a += 2*tmp;
	b -= tmp;
	c -= tmp;
	return {a,b,c};
}

void build(){
	for(int i = n-1; i > 0; --i) t[i] = combine(t[i<<1],t[i<<1|1]);
}

S query(int l,int r){
	S resl = {0,0,0}, resr = {0,0,0};
	for(l += n, r += n; l < r; l>>=1,r>>=1){
		if(l&1) resl = combine(resl,t[l++]);
		if(r&1) resr = combine(t[--r],resr);
	}
	return combine(resl,resr);
}

int main(){
	fastio
	cin >> a;
	n = a.size();
	for(int i = 0;i < a.size();i++)
		t[i+a.size()] = (a[i] == '(' ? S{0,1,0} : S{0,0,1});
	build();
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << query(l-1,r).a << "\n";
	}
}