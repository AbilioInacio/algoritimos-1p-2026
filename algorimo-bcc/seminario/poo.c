#include <stdio.h>

const int QT_ALUNOS = 1000;

struct Aluno{
    int cod;
    float nota1, nota2, media;
    char nome[100], resultado[20];
};

void escrever_frase(char *original, char *frase){
    int i;
    for(i = 0; frase[i] != '\0'; i++){
        original[i] = frase[i];
    }
    original[i] = '\0';
}

void calcular_media(struct Aluno *a) {
    a->media = (a->nota1 + a->nota2) / 2;
    if(a->media >= 6){
        escrever_frase(a->resultado, "Aprovado");
    } else {
        escrever_frase(a->resultado, "Reprovado");
    }
}

void imprimir_dados(const struct Aluno *a) {
    printf("%5d | %-20s | %5.2f | %s\n", a->cod, a->nome, a->media, a->resultado);
}

int ordenar_crescente(struct Aluno *estudante){
    struct Aluno auxEstudante;
    int i, gap = 5, ok = 0, interacoes = 0;

    while(!ok || gap != 1){
        ok = 1;
        for(i = 0; i < QT_ALUNOS - gap; i++){
            if(estudante[i].media > estudante[i+gap].media){
                auxEstudante = estudante[i];
                estudante[i] = estudante[i+gap];
                estudante[i+gap] = auxEstudante;
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
    int i, eficiencia;
    struct Aluno alunos[QT_ALUNOS];

    for(i = 0; i < QT_ALUNOS; i++){
        scanf("%d,%[^,],%f,%f", &alunos[i].cod, alunos[i].nome, &alunos[i].nota1, &alunos[i].nota2);
        calcular_media(&alunos[i]);
    }
    
    eficiencia = ordenar_crescente(alunos);
    printf("Foi necessario %d interacoes\n", eficiencia);
    
    escrever_frase(alunos[999].nome, "Abilio Inacio");
    for(i = 0; i < QT_ALUNOS; i++){
        if(alunos[i].media >= 6){
            imprimir_dados(&alunos[i]);
        }
    }
    return 0;
}