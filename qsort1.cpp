#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno {
    char nome[81];
    float nota;
};

int compararAlunos(const void *a, const void *b) {
    const Aluno *alunoA = (const Aluno *)a;
    const Aluno *alunoB = (const Aluno *)b;
    
    if (alunoA->nota > alunoB->nota)
        return -1;
    else if (alunoA->nota < alunoB->nota)
        return 1;
    else
    return strcmp(alunoA->nome, alunoB->nome);
}

int main() {
    Aluno alunos[] = {
        {"Joao", 7.5},
        {"Victor", 6.8},
        {"Angelim", 8.2},
        {"Payet", 7.5}
    };
    int numAlunos = sizeof(alunos) / sizeof(alunos[0]);

    qsort(alunos, numAlunos, sizeof(Aluno), compararAlunos);

    for (int i=0; i<numAlunos; i++) {
        printf("Nome: %s, Nota: %.1f\n", alunos[i].nome, alunos[i].nota);
    }

    return 0;
}
