#include <iostream>
using namespace std;
void nhapmang(int n, int a[]){
  for (int i = 0; i < n; i++)
    cin >> a[i];
}
void merge(int a[], int l, int m, int r){
  long long x = m - l + 1;
  long long y = r - m;
  int L[x] , R [y];
  for (int i = 0; i < x; i++) {
      L[i] = a[l + i];  
  }
  for (int j = 0; j < y; j++){
      R[j] = a[m + j + 1];
  }
  int i = 0, j = 0, k = l;
  while (i < x && j < y){
    if (L[i] <= R[j]){
      a[k] = L[i++];
    }
    else{
      a[k] = R[j++];
    }
    k++;
  }
  while (i < x){
    a[k++] = L[i++];
  }
  while (j < y){
    a[k++] = R[j++];
  }
}
void mergeSort(int a[], int l, int r){
  if (l < r){
    int m = (r+l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}
}

int a[100001];
int main(){
  int n;
  cin >> n;
  nhapmang(n,a);
  mergeSort(a,0,n-1);
  for (int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  return 0;
}