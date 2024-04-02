#include <bits/stdc++.h>
#include <functional>
#include <queue>
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


void twoGreater(ii &p, int a){
	if(a > p.y) p.y = a;
	if(p.x < p.y) swap(p.x, p.y);
}
namespace graph{
	vi prox[maxn];
	int low[maxn];
	int d[maxn];
	int cnt = 1;
	int pontes = 0;
	int bestRemoveds = 0;

	void setup(int n){
		cnt = 1;
		pontes = 0;
		bestRemoveds = 0;
		for(int i=0;i<=n;i++){
			prox[i].clear();
			low[i] = 0;
			d[i] = 0;
		}
	}
	void add(int a, int b){
		prox[a].push_back(b);
		prox[b].push_back(a);
	}

	int dfs(int v, int p){
		low[v] = d[v] = cnt++;

		ii best = {0,0};
		for(int w: prox[v]){
			if(w==p) continue;
			if(d[w] == 0){
				int curr = dfs(w,v);
				low[v] = min(low[v], low[w]);
				if(low[w] > d[v]){
					twoGreater(best, curr+1);
					pontes++;
				}
				else 
					twoGreater(best, curr);
			}
			else{
				low[v] = min(low[v], d[w]);
			}
		}
		bestRemoveds = max(bestRemoveds, best.x + best.y);
		return best.x;
	}

};
void solve(){
	int n, m;
	cin >> n >> m;
	graph::setup(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph::add(a, b);
	}

	for(int i=1;i<=n;i++){
		if(!graph::d[i]) graph::dfs(i, -1);
	}

	cout << graph::pontes - graph::bestRemoveds << "\n";

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


