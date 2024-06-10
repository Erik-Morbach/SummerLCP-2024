#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<60)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
#define MOD 1000000007
const int maxn = 1123456;

string mapa[200];
ll fen[30][200][200];
void add(int id, int x, int y, int v){
	assert(id > 0);
	assert(x>0);
	assert(y>0);
	while(x<200){
		int y1 = y;
		while(y1 < 200){
			fen[id][x][y1] += v;
			y1 += lsb(y1);
		}
		x += lsb(x);
	}
}
int query(int id, int x, int y){
	int ans = 0;
	while(x){
		int y1 = y;
		while(y1){
			ans += fen[id][x][y1];
			y1 -= lsb(y1);
		}
		x -= lsb(x);
	}
	return ans;
}
int query(int id, int x1, int x2, int y1, int y2){
	return query(id, x2, y2) + query(id, x1-1, y1-1)
		- query(id, x2, y1-1) - query(id, x1-1, y2);
}

void solve(){
	memset(fen, 0, sizeof(fen));
	int N, M, q;
	cin >> N >> M >> q;
	cout << N << " " << M << " " << q << "\n";
	for(int i=1;i<=N;i++){
		cin >> mapa[i];
		for(int j=1;j<=M;j++){
			add(mapa[i][j-1]-'a'+1, i, j, 1);
		}
	}

	for(int caso=0;caso<q;caso++){
		int i,j;
		cin >> i >> j;
		i++;j++;
		int l = 0;
		int r = max(N,M);
		int best = 0;
		while(l<=r){
			int m = (l+r)/2;
			//cout << "Will be "<<m <<endl;
			// Is valid?
			if(not(i-m > 0 and j-m > 0)){
				r = m-1;
				//cout << "Failed 1"<<endl;
				continue;
			}
			if(not(i+m <= N and j+m <= M)){
				r = m-1;
				//cout << "Failed 2"<<endl;
				continue;
			}
			int suma = query(mapa[i][j-1]-'a'+1, i-m, i+m, j-m, j+m);
			ll des = (2*m+1)*(2*m+1);
			//cout << "Testing "<<m << " -> "<<des <<"|"<<suma<<endl;
			if(suma == des){
				best = max(best, 2*m+1);
				l = m+1;
			}
			else r = m-1;
		}
		cout << best << "\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0)->tie(0);
	int t = 1;
	cin >> t;

	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}
