#include <iostream>
using namespace std;

void Nhap(int n, int a[]){
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
}
 
void Count(int n, int a[]){
  int count[10] = {0};
  for (int i = 0 ; i < n; i++){
    count[a[i]]++;
  }
  int i = 0;
  for (int j = 0; j < 10; j++){
    if (count[j] <= 0){
     continue;
    }
    else{
      while (count[j] > 0){
      a[i] = j;
      i++;
      count[j]--;
      }
    }
    if (i == n){
      break;
    }
  }
}

int a[100001];
int main(){
  int n;
  cin >> n;
  Nhap(n,a);
  Count(n,a);
  for (int i = 0 ; i < n; i++){
      cout << a[i] << " ";
  }
  return 0;
}