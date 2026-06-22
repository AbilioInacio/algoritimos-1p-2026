#include <stdio.h>      //adiciona a bibioteca de input e output

const int QT_ALUNOS = 1000, TAM_NOME = 100, TAM_RES = 20; // define as constantes globais que todas as dunções podem ler

void copiar_palavras(char *frase1, char *frase2){   //recebe os ponteiros frase1 e frase2, para servir para qualquer frase
    int i;
    for(i = 0; frase2[i] != '\0'; i++){     //começa na primiera posição ate encontrar o caractere especial \0 que define fim da frase
        frase1[i] = frase2[i];      //em todas as posicoes copia o caracter da frase2 para frase1.
    }
    frase1[i] = '\0';       //colocar o caracter indicando o fim da frase, pois o for nao entra no caracter especial
}

void trocar_palavras(char *frase1, char *frase2, int tamanho){      //recebe como parametro as duas frases a serem invetidas e o tamnho
    char auxFrase[tamanho];             //cria um vetor auxiliar do tamanho definido
    copiar_palavras(auxFrase, frase1);  //copia da frase1 para o auxiliar
    copiar_palavras(frase1, frase2);    //copia os caracteres da frase2 para a frase1
    copiar_palavras(frase2, auxFrase);  //copia os caracteres do auxiliar para a frase2
}

void ordenar_decrescente(int *cod, char nomes[][TAM_NOME], float *media, char resultado[][TAM_RES]){
    int auxCod, pos, interacoes = 0, ok = 0;
    float auxMedia;
    for(int i = 0; i < QT_ALUNOS-1; i++){       //define o primeiro ponteiro na primeira posição ate a penultima posição
        pos = i;    //assume que a priera posição é o maior antes de começar a comparar
        for(int j = i+1; j < QT_ALUNOS; j++){       //define o ponteiro de comparaçao na segunda posição e vai ate a ultima
            if(media[pos] < media[j]){      //compara se a posição selecionada com o maior é maior que a posição testada
                pos = j;    //armazena a posição do maior comparado
            }
        }
        if(pos != i){   //verifica se a posição do maior é diferente da posiçao analizada
            auxCod = cod[i];        //aramazena o valor do codigo da posição na varival auxiliar para liberar o espaço
            cod[i] = cod[pos];      //copia o proximo elemento para a posição ordenada
            cod[pos] = auxCod;      //armazena o valor da posição que foi substituido e estava na variavel auxiliar 

            trocar_palavras(nomes[i], nomes[pos], TAM_NOME);            //chama a função e passa a matriz nome com as posições a serem trocadas
            trocar_palavras(resultado[i], resultado[pos], TAM_RES);     //chama a funcao e passa a matriz resultado com as posiçõ a serem trocadas
            
            auxMedia = media[i];    //aramazena o valor da media da posição na varival auxiliar para liberar o espaço
            media[i] = media[pos];  //copia o proximo elemento para a posição ordenada
            media[pos] = auxMedia;  //armazena o valor da posição que foi substituido e estava na variavel auxiliar
        }
    }
}

int main(){
    int cod[QT_ALUNOS], i;
    float nota1, nota2, media[QT_ALUNOS];
    char nomes[QT_ALUNOS][TAM_NOME], resultado[QT_ALUNOS][TAM_RES];

    for(i = 0; i < QT_ALUNOS; i++){     //ciclio de repeticao para ler todos os alunos
        scanf("%d,%[^,],%f,%f",&cod[i],nomes[i],&nota1,&nota2);     //leitura de cada linha lendo primeiro o codigo, depois o nome ate a virgula e as duas notas
        media[i] = (nota1 + nota2)/2;       //calcula media na posicao em que esta sendo lido
        if(media[i] >= 6){      //verifica a media para definir o resultado
            copiar_palavras(resultado[i], "Aprovado");  //chama a funcao e para escrever na posicao do vetor a palavra
        } else {
            copiar_palavras(resultado[i], "Reprovado"); //chama a funcao e para escrever na posicao do vetor a palavra
        }
    }

    ordenar_decrescente(cod, nomes, media, resultado); //Chama a função e passa os ponteiros das matrizes e vetores que serão ordenados

    for(i = QT_ALUNOS-121; i < QT_ALUNOS; i++){     //ciclo de repetição para imprimir os alunos com as 121 piores medias
            printf("%5d | %-20s | %5.2f | %s\n", cod[i], nomes[i], media[i], resultado[i]); //imprime na nar ordem e identea para ficarem alinhados
    }
    return 0;
}