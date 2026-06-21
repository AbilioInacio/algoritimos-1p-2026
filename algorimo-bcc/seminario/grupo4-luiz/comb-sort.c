#include <stdio.h>

const int QT_ALUNOS = 1000, TAM_NOME = 100, TAM_RES = 20;

void copiar_palavras(char *frase1, char *frase2){
    int i;
    for(i = 0; frase2[i] != '\0'; i++){
        frase1[i] = frase2[i];
    }
    frase1[i] = '\0';
}

void trocar_palavras(char *frase1, char *frase2, int tamanho){
    char auxChar;
    for(int i = 0; i < tamanho; i++){
        auxChar = frase1[i];
        frase1[i] = frase2[i];
        frase2[i] = auxChar;
    }
}

int ordenar_decrescente(int *cod, char nomes[][TAM_NOME], float *media, char resultado[][TAM_RES]){
    int i, auxCod, gap = 5, ok = 0, interacoes = 0;
    float auxMedia;

    while(!ok || gap != 1){
        ok = 1;
        for(i = 0; i < QT_ALUNOS - gap; i++){
            if(media[i] < media[i+gap]){
                auxCod = cod[i];
                cod[i] = cod[i+gap];
                cod[i+gap] = auxCod;
    
                trocar_palavras(nomes[i], nomes[i+gap], TAM_NOME);
                trocar_palavras(resultado[i], resultado[i+gap], TAM_RES);
                
                auxMedia = media[i];
                media[i] = media[i+gap];
                media[i+gap] = auxMedia;
                ok = 0;
            }
        }
        if(gap > 1){
            gap--;
        }
        interacoes++;
    }
    return interacoes;
}

int main(){
    int cod[QT_ALUNOS], i, gap = 5, eficiencia = 0;
    float nota1, nota2, media[QT_ALUNOS];
    char nomes[QT_ALUNOS][TAM_NOME], resultado[QT_ALUNOS][TAM_RES];

    for(i = 0; i < QT_ALUNOS; i++){
        scanf("%d,%[^,],%f,%f",&cod[i], nomes[i], &nota1, &nota2);
        media[i] = (nota1 + nota2)/2;
        if(media[i] >= 6){
            copiar_palavras(resultado[i], "Aprovado");
        } else {
            copiar_palavras(resultado[i], "Reprovado");
        }
    }

    eficiencia = ordenar_decrescente(cod, nomes, media, resultado);
    printf("Foi necessario %d interacoes\n", eficiencia);

    for(i = 0; i < QT_ALUNOS; i++){
        if(media[i] >= 6){
            printf("%5d | %-20s | %5.2f | %s\n", cod[i], nomes[i], media[i], resultado[i]);
        }
    }
    return 0;
}