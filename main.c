/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== ESTRUTURA DO PACIENTE =====
typedef struct No {
    char nome[50];
    struct No* prox;
} No;

// ===== FILA =====
typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enqueue(Fila* f, char nome[]) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

char* dequeue(Fila* f) {
    if (f->inicio == NULL) return NULL;

    No* temp = f->inicio;
    char* nome = (char*) malloc(50);
    strcpy(nome, temp->nome);

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) f->fim = NULL;

    free(temp);
    return nome;
}

int fila_vazia(Fila* f) {
    return f->inicio == NULL;
    char* peek_fila(Fila* f) {
    if (f->inicio == NULL) return NULL;
    return f->inicio->nome;
}
}

// ===== PILHA =====
typedef struct {
    No* topo;
} Pilha;

void push(Pilha* p, char nome[]) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);

    novo->prox = p->topo;
    p->topo = novo;
}

char* pop(Pilha* p) {
    if (p->topo == NULL) return NULL;

    No* temp = p->topo;
    char* nome = (char*) malloc(50);
    strcpy(nome, temp->nome);

    p->topo = temp->prox;
    free(temp);

    return nome;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
    char* peek_pilha(Pilha* p) {
    if (p->topo == NULL) return NULL;
    return p->topo->nome;
}
}

// ===== MAIN =====
int main() {
    Fila normal = {NULL, NULL};
    Fila emergencia = {NULL, NULL};
    Pilha historico = {NULL};
    Pilha acoes = {NULL};
    
    int op;
    char nome[50];

    do {
        printf("\n1 - Novo paciente\n");
        printf("2 - Emergencia\n");
        printf("3 - Atender\n");
        printf("4 - Ver historico\n");
        printf("5 - Desfazer ultimo atendimento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                enqueue(&normal, nome);
                break;

            case 2:
                printf("Nome (emergencia): ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                enqueue(&emergencia, nome);
                break;

            case 3: {
                char* atendido;

                if (!fila_vazia(&emergencia)) {
                    atendido = dequeue(&emergencia);
                } else {
                    atendido = dequeue(&normal);
                }

                if (atendido != NULL) {
                    printf("Atendendo: %s\n", atendido);
                    push(&historico, atendido);
                    push(&acoes, atendido);
                } else {
                    printf("Nenhum paciente na fila\n");
                }
                break;
            }

            case 4: {
                Pilha temp = historico;
                printf("Historico:\n");
                while (!pilha_vazia(&temp)) {
                    printf("%s\n", temp.topo->nome);
                    temp.topo = temp.topo->prox;
                }
                case 5: {
                char* ultimo = pop(&acoes);

                if (ultimo != NULL) {
                printf("Desfeito atendimento de: %s\n", ultimo);
                enqueue(&normal, ultimo); // volta pra fila
    }           else {
                    printf("Nada para desfazer\n");
                 }
                break;
}
                break;
            }
        }

    } while(op != 0);

    return 0;
}
