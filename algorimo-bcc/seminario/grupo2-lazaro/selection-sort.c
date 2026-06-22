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
    char auxFrase[tamanho];
    copiar_palavras(auxFrase, frase1);
    copiar_palavras(frase1, frase2);
    copiar_palavras(frase2, auxFrase);
}

void ordenar_decrescente(int *cod, char nomes[][TAM_NOME], float *media, char resultado[][TAM_RES]){
    int auxCod, pos, interacoes = 0, ok = 0;
    float auxMedia;
    for(int i = 0; i < QT_ALUNOS-1; i++){
        pos = i;
        for(int j = i+1; j < QT_ALUNOS; j++){
            if(media[pos] < media[j]){
                pos = j;
            }
        }
        if(pos != i){
            auxCod = cod[i];
            cod[i] = cod[pos];
            cod[pos] = auxCod;

            trocar_palavras(nomes[i], nomes[pos], TAM_NOME);
            trocar_palavras(resultado[i], resultado[pos], TAM_RES);
            
            auxMedia = media[i];
            media[i] = media[pos];
            media[pos] = auxMedia;
        }
    }
}

int main(){
    int cod[QT_ALUNOS], i;
    float nota1, nota2, media[QT_ALUNOS];
    char nomes[QT_ALUNOS][TAM_NOME], resultado[QT_ALUNOS][TAM_RES];

    for(i = 0; i < QT_ALUNOS; i++){ //ciclio de repeticao para ler todos os alunos
        scanf("%d,%[^,],%f,%f",&cod[i],nomes[i],&nota1,&nota2);  //leitura de cada linha lendo primeiro o codigo, depois o nome ate a virgula e as duas notas
        media[i] = (nota1 + nota2)/2; //calcula media na posicao em que esta sendo lido
        if(media[i] >= 6){
            copiar_palavras(resultado[i], "Aprovado");
        } else {
            copiar_palavras(resultado[i], "Reprovado");
        }
    }

    ordenar_decrescente(cod, nomes, media, resultado);

    for(i = QT_ALUNOS-121; i < QT_ALUNOS; i++){
            printf("%5d | %-20s | %5.2f | %s\n", cod[i], nomes[i], media[i], resultado[i]);
    }
    return 0;
}