#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Produto{
int codigo;
char name[50];
int qtd_disponivel;
double preco_venda;
};

int main(){
int i,n;
printf("Insira a quantida de cadastros \n");
scanf("%d",&n);

struct Produto *p = (struct Produto*)malloc(n*sizeof(struct Produto));
printf("Preencha dados dos produtos \n");
 for(i=0;i<n;i++){
    printf("========================\n");
    printf("codigo :");
    scanf("%d",&p[i].codigo);
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    printf("\nNome :");
    fgets(p[i].name,50,stdin);
    printf("\nquantidade disponivel :");
    scanf("%d",&p[i].qtd_disponivel);
    printf("\preco venda :");
    scanf("%lf",&p[i].preco_venda);
    printf("========================");
 }
 int maior=0;
 char nome[50];
for(i=0;i<n;i++){
    if(p[i].preco_venda>maior){
        maior=p[i].preco_venda;
        strcpy(nome,p[i].name);

    }
}
char nome_qtd[50];
int maior_qtd_disponivel =-1;
for(i=0;i<n;i++){
    if(p[i].qtd_disponivel>maior_qtd_disponivel){
        maior_qtd_disponivel=p[i].qtd_disponivel;
        strcpy(nome_qtd,p[i].name);

    }
}
printf("\n");
printf(" MAIOR PRECO DE VENDA EH %d do produto %s ",maior,nome);
printf(" MAIOR QUANTIDADE EH %d do produto %s ",maior_qtd_disponivel,nome_qtd);

}




