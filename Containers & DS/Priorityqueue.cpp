#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void sapxepmang(vector<int> &a, int n){
  priority_queue< int, vector<int> , greater<int> > A;
  for(int i : a){
    A.push(i);
  }
  for (int i = 0; i < n; i++){
    a[i] = A.top();
    A.pop();
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> a;
  int num;
  for (int i = 0; i < n; i++){
    cin >> num;
    a.push_back(num); 
  }
  sapxepmang(a,n);
  for(int x : a){
    cout << x << " ";
  }
  return 0;
}