#include <iostream>
#include <vector>

using namespace std;

void FindMex(vector<int> &v, int n){
  vector<int> count(n+1,0);
  int mex = 0;
  for (int i = 0; i < n; i++){
    count[v[i]]++;
    while(count[mex] > 0){
      mex++;
    }
    cout << mex << " ";
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  FindMex(v,n);
  return 0;
}