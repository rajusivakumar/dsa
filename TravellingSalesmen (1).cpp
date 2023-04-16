#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 9999

int n;

int distan[10][10];

int completed_visit;

int DP[16][4];

int TSP(int mark,int position){
  if(mark==completed_visit){
    return distan[position][0];
  }
  if(DP[mark][position]!=-1){
     return DP[mark][position];
  }
  int answer = MAX;
  for(int city=0;city<n;city++){
    if((mark&(1<<city))==0){
      int newAnswer = distan[position][city] + TSP( mark|(1<<city),city);
      answer = min(answer, newAnswer);
    }
  }
  return DP[mark][position] = answer;
}

int main(){
    cout << "Enter the number of places you want to visit: ";
    cin >> n;

    completed_visit = (1<<n) -1;

    cout << "Enter the distance matrix:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> distan[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));

    cout<<"Minimum Distance Travelled by you is "<<TSP(1,0);

    return 0;
}
// Enter the number of places you want to visit: 4
// Enter the distance matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
// Minimum Distance Travelled by you is 80