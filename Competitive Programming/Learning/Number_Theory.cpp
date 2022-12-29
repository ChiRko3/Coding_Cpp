/* Author : Chirag */
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pii pair<int, int>
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define round_int(a) (int)((double)a + 0.5)
#define round_decimal(a, f) cout << fixed << setprecision(f) << a << endl;
#define log(a)            \
    for (auto a : a)      \
    {                     \
        cout << a << " "; \
    }
#define read(n) \
    int n;      \
    cin >> n;
#define endl "\n";
using namespace std;
double Euclid_Dis(pair<int, int> &A, pair<int, int> &B)
{
    ll T = ((B.first - A.first) * (B.first - A.first)) + ((B.second - A.second) * (B.second - A.second));
    return sqrt(T);
}
int ManHattan(int x, int y, int x0, int y0)
{
    return abs(x0 - x) + abs(y0 - y);
}
int ManHattan(pair<int, int> &A, pair<int, int> &B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}
int Factors_RootN(int n){
    int ans = 0;
    for(int i = 1;i * i <= n;i++){
        int t = n % i;
        if(t == 0){
            ans++;
            if(i != (n / i)){
                ans++;
            }
        }
    }
    return ans;
}
void Iterating_Multiples(int n){
    vector<int> div(n + 1,1);
    for(int i = 2;i <= n;i++){
        for(int j = i;j <= n;j = j + i){
            div[j]++;
        }
    }
    log(div);
}
int primeFactors(int n){         // Fast Way Of Prime Factorization
    int c = 2;
    int sm = 0;
    while (n > 1)
    {
        if (n % c == 0)
        {
            sm = sm + c;
            n /= c;
        }
        else
            c++;
    }
    return sm;
}
void Prime_Seive(int n){
    vector<int> prime(n + 1,1);
    prime[1] = 0;
    for(int i = 2;i <= n;i++){
        if(!prime[i]) continue;
        for(int j = i * i;j <= n;j = j + i){
            prime[j] = 0;
        }
    }
    for(int i = 1;i <= n;i++){
        if(prime[i]){
            cout<<i<<" ,";
        }
    }
}
int GCD(int a,int b){
    if(b == 0) return a;
    return GCD(b,a%b);

}
void solve()
{
    // int n;
    // cin>>n;
    int a,b;
    cin>>a>>b;
    // Factors in Linear Time Skipped
    // cout<<Factors_RootN(n)<<endl;  //O(sqrt(N))
    // Iterating_Multiples(n);   // O(NlogN)
    // Prime_Seive(n);   // O(Nlog(logN))
    cout<<GCD(a,b);              // O(log(max(a,b)))
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    clock_t begin = clock();
    file_i_o();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}