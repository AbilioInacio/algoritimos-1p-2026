#include <stdio.h>

#define MAX_ALUNOS 1000
#define TAM_NOME 50
#define NUM_NOTAS 2
#define MELHORES 131

int main(void) {
    int matricula[MAX_ALUNOS];
    char nomes[MAX_ALUNOS][TAM_NOME];
    float notas[MAX_ALUNOS][NUM_NOTAS];
    float medias[MAX_ALUNOS];

    int total = 0;
    int i, j, k;

    while (total < MAX_ALUNOS && scanf("%d,%[^,],%f,%f", &matricula[total], nomes[total], &notas[total][0], &notas[total][1]) == 4) {
        
        medias[total] = (notas[total][0] + notas[total][1]) / NUM_NOTAS;
        total++;
    }
    printf("Total de alunos lidos: %d\n", total);

    float chaveMedia, chaveNotas[NUM_NOTAS];
    char chaveNome[TAM_NOME];
    int chaveMatricula;

    for (i = 1; i < total; i++) {
        chaveMedia = medias[i];
        chaveMatricula = matricula[i];
        
        for (j = 0; j < NUM_NOTAS; j++) {
            chaveNotas[j] = notas[i][j];
        }

        for (j = 0; nomes[i][j] != '\0'; j++) {
            chaveNome[j] = nomes[i][j];
        }
        chaveNome[j] = '\0';

        j = i - 1;

        while (j >= 0 && medias[j] > chaveMedia) {
            medias[j + 1] = medias[j];
            matricula[j + 1] = matricula[j];
            notas[j + 1][0] = notas[j][0];
            notas[j + 1][1] = notas[j][1];

            for (k = 0; nomes[j][k] != '\0'; k++) {
                nomes[j + 1][k] = nomes[j][k];
            }
            nomes[j + 1][k] = '\0';
            
            j--;
        }

        medias[j + 1] = chaveMedia;
        matricula[j + 1] = chaveMatricula;
        notas[j + 1][0] = chaveNotas[0];
        notas[j + 1][1] = chaveNotas[1];

        for (k = 0; chaveNome[k] != '\0'; k++) {
            nomes[j + 1][k] = chaveNome[k];
        }
        nomes[j + 1][k] = '\0';
    }

    int inicio = total - MELHORES;

    for (i = inicio; i < total; i++) {
        printf("%d,%s,%.2f, ",
                matricula[i],
                nomes[i],
                medias[i]);
        if(medias[i]<6){
            printf(" Reprovado\n");
        }else{
            printf(" Aprovado\n");
        }
    }

    return 0;
}