#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    omp_set_num_threads(8);
    #pragma omp parallel for
    int *FF = malloc(sizeof(int) * NF);
    int *R = malloc(sizeof(int) * (NA-NF+1));

    for(int i=0;i<NF;++i)
        FF[i]=F[NF-i-1];

    for(int i=0;i<NA-NF+1;++i){
        int s=0;
        for(int j=0;j<NF;++j)
            s+=A[i+j]*FF[j];
        R[i]=s;
    }
    for(int i=0;i<NA-NF+1;i++)
        printf("%d\n",R[i]);
    free(FF);
    free(R);
    // ---- free memory ----
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}

