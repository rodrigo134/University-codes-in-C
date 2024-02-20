#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int matricula;
    int notas[3];
};

int main() {
    int i, n, j;
    printf("Insira o numero de cadastros a ser inserido: ");
    scanf("%d", &n);

    struct Aluno *aluno = (struct Aluno *)malloc(n * sizeof(struct Aluno));
    for (i = 0; i < n; i++) {
        printf("Insira a matricula do aluno [%d]: ", i + 1);
        scanf("%d", &aluno[i].matricula);
        for (j = 0; j < 3; j++) {
            printf("Insira a nota do aluno [%d]: ", i + 1);
            scanf("%d", &aluno[i].notas[j]);
        }
    }

    int count = 0, soma;

    int *p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        soma = 0;
        for (j = 0; j < 3; j++) {
            soma += aluno[i].notas[j];
        }

        if (soma >= 60) {
            count += 1;
            printf("ALUNO MATRICULA [%d] aprovado [%d] pontos\n", aluno[i].matricula,soma);
            p[count - 1] = aluno[i].matricula;
        }
    }

    p = (int *)realloc(p, count * sizeof(int));
    if (p == NULL && count > 0) {
        fprintf(stderr, "Falha na realocação de memória para lista de aprovados.\n");
        free(aluno);
        return 1;
    }

    printf("\nLISTA APROVADOS: ");
    for (i = 0; i < count; i++) {
        printf("[%d] ", p[i]);
    }
    printf("\n");

    free(aluno);
    free(p);

    return 0;
}

