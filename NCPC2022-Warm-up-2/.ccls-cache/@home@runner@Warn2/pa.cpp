#include<iostream>
#include<vector>
using namespace std;

int n, m, c;
long long cnt = 0, machine, Max = 0, inde = 0;
vector<int> device(30);
vector<int> state(30, false);

int main()
{
  while(cin >> n >> m >> c && (n || m || c))
  {
    ++inde;
    Max = 0;
    cnt = 0;
    bool y = true;

    for(int i = 1; i <= n; ++i) 
    {
      cin >> device[i];
      state[i] = false;
    }
    for(int i = 0; i < m; ++i)
    {
      cin >> machine;
      if(state[machine])
      {
        cnt -= device[machine];
        state[machine] = false;
      }
      else
      {
        cnt += device[machine];
        state[machine] = true;
        Max = max(Max, cnt);
      }
      if(cnt > c) { y = false;}
    }
    cout << "Sequence " << inde << "\n";
    if(!y) cout << "Fuse was blown.\n\n";
    else 
    {
      cout << "Fuse was not blown.\n";
      cout << "Maximal power consumption was "<< Max << " amperes.\n\n";
    }
  }
  return 0;
}