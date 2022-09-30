#include<iostream>
#include<vector>
using namespace std;

long long n, cnt, l , r;

void merge(int l, int r, vector<int> &arr, vector<int> &tmp)
{
  if(r<=l) return;
  int mid = (l+r)>>1;
  merge(l,mid,arr,tmp);
  merge(mid+1,r,arr,tmp);
  int ptl = l, ptr = mid+1;
  for(int i = l; i <= r; ++i)
  {
    if(ptr>r||(ptl<=mid&&arr[ptl]<arr[ptr]))
      tmp[i]=arr[ptl++];
    else if(ptl > mid)
    {
      tmp[i]=arr[ptr++];
    }
    else{
      tmp[i]=arr[ptr++];
      cnt += (mid - ptl + 1);
    }
  }
  for(int i = l; i <=r; ++i) arr[i] = tmp[i];
  return;
}

int main()
{
  while(cin >> n && n)
  {
      cnt = 0;
      vector<int> seq(n+5);
      vector<int> temp(n+5);
      for(int i = 0; i < n; ++i) cin >> seq[i];
      merge(0, n-1, seq, temp);
      if(cnt % 2 == 1) cout << "Marcelo\n";
      else cout << "Carlos\n";
  }
  return 0;
}