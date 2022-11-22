#include <bits/stdc++.h>
using namespace std;

#define input cin
#define output cout
#define ll long long 
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<int>

const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

int n;
int a[cs];
deque<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n;
    for (int i = 0;i<n;i++) {
        input >> a[i];
    }
    sort(a, a + n);
    for (int i = 0;i<n;i++) {
        if (i & 1) {
            q.push_back(a[i]);
        } else {
            q.push_front(a[i]);
        }
    }
    for (int i = 0;i<n;i++ ) {
        output << q.front() << ' ';
        q.pop_front();
    }
    return 0;
}
