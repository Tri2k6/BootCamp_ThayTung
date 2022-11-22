#include <bits/stdc++.h>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

#define ll long long 
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<ll>

const ll cs = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

int n,k;
vi a,b;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n >> k;
    vi a(n),b(n,0);
    for (int i = 0;i<n;i++) {
        input >> a[i];
        if (!s.insert(a[i]).second) b[i] = 1;
    }
    for (auto x:s) {
        output << x << ' ';
        k--;
        if (k == 0) break;
    }
    if (k > 0) {
        for (int i = 0;i<n;i++) {
            if (b[i]) {
                output << a[i] << ' ';
                if (--k == 0) break;
            }
        }
    }
    return 0;
}
