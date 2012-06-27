#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EPS 1e-13
#define RAND (rand()/(RAND_MAX+1.0))

int main(){
  int T = 50;

  srand(time(NULL));
  printf("%d\n", T);

  while(T--){
    int i,j;
    
    int N, M, C[200], P[200][200];
    double x, y, z;
    double x_set[5] = {1, 2, 5, 10, 100};

    double alive_rate[200];

    N = 50 + (int)(RAND*151);
    M = 50 + (int)(RAND*151);
    for(i=0; i<N; i++) for(j=0; j<M; j++){
      P[i][j] = (int)(RAND*91);
      if(RAND < 0.75) P[i][j] = 0;
    }

    x = x_set[(int)(RAND*5)];
    for(i=0; i<M; i++){
      y = RAND;
      z = 0;
      for(j=0; j<N; j++) z += P[j][i];
      z *= (x+y);

      C[i] = (int)(z+0.5);
      if(C[i] < 1) C[i] = 1;
      if(C[i] > 1000000) C[i] = 1000000;
    }

    for(i=0; i<N; i++) alive_rate[i] = 1;
    for(i=0; i<N; i++) for(j=0; j<M; j++) alive_rate[i] *= (100 - P[i][j]) / 100.0;

    for(i=0; i<N; i++) if(alive_rate[i] > 0.1+EPS) break;
    if(i<N){
      T++;
      continue;
    }

    printf("%d %d\n", N, M);
    
    for(i=0; i<M; i++){
      if(i) putchar(' ');
      printf("%d",C[i]);
    }
    puts("");
    
    for(i=0; i<N; i++){
      for(j=0; j<M; j++){
        if(j) putchar(' ');
        printf("%d",P[i][j]);
      }
      puts("");
    }

    /* printf("cost is %d\n",res_cost); */
  }

  return 0;
}
