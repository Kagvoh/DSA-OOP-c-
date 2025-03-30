#include <iostream>
#include <vector>
#define Max 1000000

using namespace std;
struct Point{
  int x;
  int y;
};

void Merge(vector<Point> &P, int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<Point> L(n1);
  vector<Point> R(n2);
  
  for (int i = 0; i < n1; i++) L[i] = P[l + i];
  for (int j = 0; j < n2; j++) R[j] = P[m + 1 + j];

  int i = 0 , j = 0, k = l;
  while(i < n1 && j < n2){
    if (L[i].x < R[j].x || L[i].x == R[j].x && L[i].y > R[j].y){
      P[k++] = L[i++];
    }
    else{
      P[k++] = R[j++];
    }
  }
  while (i < n1){
    P[k++] = L[i++];
  }
  while (j < n2){
    P[k++] = R[j++];
  }
}

void MergeSort(vector<Point> &P, int l, int r){
  if ( l < r ){
  int m = l + (r-l)/2;
  MergeSort(P,l,m);
  MergeSort(P,m+1,r);
  Merge(P,l,m,r);
  }
}

int main(){
  int n; cin >> n;
  vector<Point> P(n);
  for (int i = 0 ; i < n; i++){
      cin >> P[i].x >> P[i].y;
  }
  MergeSort(P,0,n-1);
  for (auto &i : P){
    cout << i.x << " " << i.y << "\n";
  }
}