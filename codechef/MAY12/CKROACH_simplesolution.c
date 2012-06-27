#include<stdio.h>

#define EPS 1e-13

int main(){
  int T;

  scanf("%d",&T);
  while(T--){
    int i,j,k;
    
    int N, M, C[200], P[200][200];
    int res[200], res_size = 0, res_cost = 0;

    double alive_rate[200];

    scanf("%d%d",&N,&M);
    for(i=0; i<M; i++) scanf("%d", C+i);
    for(i=0; i<N; i++) for(j=0; j<M; j++) scanf("%d", P[i]+j);

    for(i=0; i<N; i++) alive_rate[i] = 1;

    for(k=0; k<M; k++){
      for(i=0; i<N; i++) if(alive_rate[i] > 0.1+EPS) break;
      if(i==N) break;

      for(i=0; i<N; i++) if(alive_rate[i] > 0.1+EPS && P[i][k]) break;
      if(i==N) continue;

      res[res_size++] = k;
      res_cost += C[i];

      for(i=0; i<N; i++) alive_rate[i] *= (100 - P[i][k]) / 100.0;
    }

    printf("%d\n",res_size);
    for(i=0;i<res_size;i++){
      if(i) putchar(' ');
      printf("%d",res[i]+1);
    }
    puts("");

    /* printf("cost is %d\n",res_cost); */
  }

  return 0;
}
