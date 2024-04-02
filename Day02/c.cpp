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
const int mod = 1000000000 + 7;


ll v[maxn];
ll buck[maxn];
void solve(){
	int n, q;
	cin >> n >> q;
	int B = sqrt(n);

	for(int i=1;i<=n;i++){
		cin >> v[i];
		buck[i/B] += v[i];
	}

	for(int i=0;i<q;i++){
		int op;
		int a,b;
		cin >> op >> a >> b;

		if(op==1){
			buck[a/B] += (b - v[a]);
			v[a] = b;
		}
		else{
			ll ans = 0;
			if(b-a+1 < B){
				for(int j=a;j<=b;j++) ans += v[j];
				cout << ans << "\n";
				continue;
			}
			int bA = (a + B - 1)/B;
			int bB = (b/B)-1;
			for(int j=a;j<B*bA;j++) ans += v[j];
			for(int j=bA;j<=bB;j++) ans += buck[j];
			for(int j=(bB+1)*B;j<=b;j++) ans += v[j];
			cout << ans << "\n";
		}
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

