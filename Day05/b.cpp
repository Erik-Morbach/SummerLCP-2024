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

namespace graph{
	vi prox[maxn];
	int vizi[maxn];
	int cntt = 0;
	int low[maxn];
	int d[maxn];
	int f[maxn];
	bool cutVertex[maxn];
	int cnt = 1;
	void add(int a, int b){
		prox[a].push_back(b);
		prox[b].push_back(a);
	}

	void clearVizi(){
		cntt++;
	}

	void dfs(int v, int p){
		low[v] = d[v] = cnt++;
		vizi[v] = cntt;

		cutVertex[v] = false;

		int child = 0;
		for(int w: prox[v]){
			if(w == p) continue;
			if(vizi[w] < cntt){
				dfs(w, v);
				low[v] = min(low[v], low[w]);
				if(low[w] >= d[v] && p != -1)
					cutVertex[v] = true;
				child++;
			}
			else
				low[v] = min(low[v], d[w]);
		}
		if(p == -1 and child>1)
			cutVertex[v] = true;

		f[v] = cnt++;
	}
};
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph::add(a, b);
	}

	graph::clearVizi();
	for(int i=1;i<=n;i++)
		if(graph::vizi[i] < graph::cntt)
			graph::dfs(i, -1);

	vi cuts;
	for(int i=1;i<=n;i++){
		if(graph::cutVertex[i])
			cuts.push_back(i);
	}
	cout << cuts.size()<<"\n";
	for(int w: cuts){
		cout << w << " ";
	}
	cout << "\n";
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


