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

int ordenar_decrescente(int *cod, char nomes[][TAM_NOME], float * media, char resultado[][TAM_RES]){
    int auxCod, interacoes = 0, ok = 0;
    float auxMedia;
    char auxNome[TAM_NOME];
    while(!ok){
        ok = 1;
        for(int i = 1; i < QT_ALUNOS; i++){
            for(int j = i-1; j >= 0; j--){
                if(media[i] > media[j]){
                    auxCod = cod[i];
                    cod[i] = cod[j];
                    cod[j] = auxCod;
        
                    trocar_palavras(nomes[i], nomes[j], TAM_NOME);
                    trocar_palavras(resultado[i], resultado[j], TAM_RES);
                    
                    auxMedia = media[i];
                    media[i] = media[j];
                    media[j] = auxMedia;            
                    ok = 0;
                }
            }
        }
        interacoes++;
    }
    return interacoes;
}

int main(){
    int cod[QT_ALUNOS], i,  eficiencia = 0;
    float nota1, nota2, media[QT_ALUNOS];
    char nomes[QT_ALUNOS][TAM_NOME], resultado[QT_ALUNOS][TAM_RES];

    for(i = 0; i < QT_ALUNOS; i++){
        scanf("%d,%[^,],%f,%f",&cod[i],nomes[i],&nota1,&nota2);
        media[i] = (nota1 + nota2)/2;
        if(media[i] >= 6){
            copiar_palavras(resultado[i], "Aprovado");
        } else {
            copiar_palavras(resultado[i], "Reprovado");
        }
    }

    eficiencia = ordenar_decrescente(cod, nomes, media, resultado);

    printf("Foi necessario %d interacoes\n", eficiencia);
    for(i = 0; i < 111; i++){
            printf("%5d | %-20s | %5.2f | %s\n", cod[i], nomes[i], media[i], resultado[i]);
    }
    return 0;
}