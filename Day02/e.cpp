#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<61)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
const int maxn = 812345;
const int maxp = 20;
const int mod = 998244353;

namespace comp{
	set<int> v;
	unordered_map<int, int> mapper;
	void setup(){
		v.clear();
		mapper.clear();
	}
	void add(int x){
		v.insert(x);
	}

	void build(){
		int id = 1;
		mapper.clear();
		for(auto w: v){
			mapper[w] = id++;
		}
	}

	int query(int x){
		return mapper[x];
	}
};

namespace fen{
	int v[maxn];
	void add(int x, int val){
		while(x<maxn){
			v[x]+=val;
			x += lsb(x);
		}
	}
	int query(int x){
		int ans = 0;
		while(x){
			ans += v[x];
			x -= lsb(x);
		}
		return ans;
	}
};

void solve(){
	int n,q;
	cin >> n >> q;
	vi v(n);
	comp::setup();
	for(int i=0;i<n;i++){
		cin >> v[i];
		comp::add(v[i]);
	}

	vector<pair<char, ii>> quer;
	for(int i=0;i<q;i++){
		char op;
		int a,b;
		cin >> op >> a >> b;
		quer.push_back({op, {a,b}});
		comp::add(b);
		if(op=='?') comp::add(a);
	}

	comp::build();

	for(int i=0;i<n;i++){
		v[i] = comp::query(v[i]);
	}
	for(auto &w: quer){
		w.y.y = comp::query(w.y.y);
		if(w.x == '?')
			w.y.x = comp::query(w.y.x);
	}

	for(int i=0;i<n;i++)
		fen::add(v[i], 1);

	for(auto qu: quer){
		if(qu.x == '!'){
			fen::add(v[qu.y.x-1], -1);
			v[qu.y.x-1] = qu.y.y;
			fen::add(v[qu.y.x-1], 1);
			continue;
		}
		cout << fen::query(qu.y.y) - fen::query(qu.y.x-1) << "\n";
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


