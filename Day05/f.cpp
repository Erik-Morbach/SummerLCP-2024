#include <bits/stdc++.h>
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
const int maxn = 212345;
const int maxp = 20;
const int mod = 998244353;

namespace dsu{
	int p[maxn];
	int s[maxn];

	void setup(int n){
		for(int i=0;i<=n;i++){
			p[i] = i;
			s[i] = 1;
		}
	}

	int find(int v){
		return p[v] == v ? v : p[v] = dsu::find(p[v]);
	}

	void unio(int u, int v){
		u = dsu::find(u);
		v = dsu::find(v);
		if(s[u] < s[v]) swap(u,v);
		s[u] += s[v];
		p[v] = u;
	}
};


namespace graph{
	vi prox[maxn];
	void setup(int n){
		for(int i=0;i<=n;i++) prox[i].clear();
	}
	void add(int a, int b){
		prox[a].push_back(b);
		prox[b].push_back(a);
	}
	bool dfs(int v, int p, vi &path, int t){
		path.push_back(v);
		if(v == t) return true;

		for(int w: prox[v]){
			if(w == p) continue;
			if(dfs(w, v, path, t)){
				return true;
			}
		}
		path.pop_back();
		return false;
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	dsu::setup(n);
	graph::setup(n);
	vector<pair<int, ii>> ed;
	for(int i=0;i<m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		ed.push_back({c, {a,b}});
	}
	sort(all(ed));
	int last = 0;
	for(int i=m-1;i>=0;i--){
		if(dsu::find(ed[i].y.x) == dsu::find(ed[i].y.y)){
			last = i;
			continue;
		}
		dsu::unio(ed[i].y.x, ed[i].y.y);
		graph::add(ed[i].y.x, ed[i].y.y);
	}

	vi path;
	graph::dfs(ed[last].y.x, 0, path, ed[last].y.y);

	cout << ed[last].x << " " << path.size() << "\n";
	for(int w: path) cout << w << " ";
	cout <<"\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


