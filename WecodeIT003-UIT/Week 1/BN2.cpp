#include <iostream>
#include <vector>
#include <string>
using namespace std;

void BinarySearch(vector<string> &v, int n, string k){
  int l = 0;
  int r = n - 1;
  int dem = 0;
  bool check = false;
  while ( l <= r ){
    int m = l + (r-l)/2;
    if (v[m] < k){
      dem++;
      l = m + 1; 
    }
    else if(v[m] > k){
      dem++;
      r = m - 1;
    }
    else{
      dem++;
      check = true;
      cout << m << "\n";
      cout << dem;
      break;
    }
  }
  if (!check) cout << "-1";
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    string x;
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    cin >> x;
    BinarySearch(v,n,x);
    return 0;
}