#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>
#include <cstring>
#include <assert.h>
#include <numeric>
#include <math.h>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


const int MOD = 1e9 + 7;
const double EPS = 1e-9;
int dx[]{0,0,1,-1,-1,-1,1,1};
int dy[]{1,-1,0,0,-1,1,-1,1};
int knight_dx[]{-2,-2,-1,-1,2,2,1,1};
int knight_dy[]{-1,1,-2,2,-1,1,-2,2};

void solve(){
    string s, t;
    while(cin >> s >> t){
      if(s == t){
           cout << "To get from "<<s<<" to "<<t<<" takes "<<0<<" knight moves.\n";
           continue;
      }
      queue<string> q{};
      q.push(s);
      unordered_set<string> seen{};
      seen.insert(s);
      int sz = 1, dep = 0;
      bool ok = 1;
      for(; ok && !q.empty(); ++dep, sz = q.size()){
          while(ok && sz--){
              string cur = q.front(); q.pop();
              for(int i = 0; i < 8; ++i){
                  string next = cur;
                  next[0] += knight_dx[i], next[1] += knight_dy[i];
                  if(next[0] < 'a' || next[1] < '1' || next[0] > 'h' || next[1] > '8' || seen.count(next)) continue;
                  if(next == t){
                      cout << "To get from "<<s<<" to "<<t<<" takes "<<1+dep<<" knight moves.\n";
                      ok = 0;
                  }
                  seen.insert(next);
                  q.push(next);
              }
          }
      }
    }
}   
int main() {
    solve();
}
