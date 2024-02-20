#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cidade{
char nome[30];
int x;
int y;
};
int main(){

int i, j ,n;
printf("Insira quantas cidades serao cadastradas ");
scanf("%d",&n);
struct cidade *c = ( struct cidade*) malloc (n*sizeof(struct cidade));

if( c == NULL){
    printf("FALHA ALOCACAO \n");
    exit(1);
}


for(i = 0;i < n;i++){
    fgets(c[i].nome,30,stdin);
    while (getchar() != '\n');
    scanf("%d",&c[i].x);
    scanf("%d",&c[i].y);
}
float **mat;
 mat= (float**) malloc(n * sizeof( float*));
for(i = 0;i<n;i++){
    mat[i]= (float*)malloc(n * sizeof( float));

}
for(i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            int dx = c[i].x - c[j].x;
            int dy = c[i].y - c[j].y;
            mat[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

for(i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
}
 free(c);
    for ( i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);



}












