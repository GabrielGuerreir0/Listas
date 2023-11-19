#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

// Inserir no início da lista circular
void IncluirInicioCircular(No **lista, int num) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo) {
        novoNo->dado = num;
        if (*lista == NULL) {
            novoNo->proximo = novoNo;
            *lista = novoNo;
        } else {
            No *ultimo = *lista;
            while (ultimo->proximo != *lista) {
                ultimo = ultimo->proximo;
            }
            novoNo->proximo = *lista; 
            ultimo->proximo = novoNo; 
            *lista = novoNo; 
        }
    } else {
        printf("Erro na alocação de memória!");
    }
}

// Inserir no final da lista circular
void IncluirFinalCircular(No **lista, int num) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo) {
        novoNo->dado = num;
        if (*lista == NULL) {
            novoNo->proximo = novoNo; 
            *lista = novoNo;
        } else {
            No *ultimo = *lista;
            while (ultimo->proximo != *lista) {
                ultimo = ultimo->proximo; 
            }
            novoNo->proximo = *lista;
            ultimo->proximo = novoNo; 
        }
    } else {
        printf("Erro na alocação de memória!");
    }
}

// Inserir em uma posição específica na lista circular
void IncluirMeioCircular(No **lista, int num, int ref) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo) {
        novoNo->dado = num;
        if (*lista == NULL) {
            novoNo->proximo = novoNo; 
            *lista = novoNo;
        } else {
            No *aux = *lista;
            while (aux->dado != ref && aux->proximo != *lista) {
                aux = aux->proximo; 
            }
            novoNo->proximo = aux->proximo; 
            aux->proximo = novoNo; 
        }
    } else {
        printf("Erro na alocação de memória!");
    }
}

// Remover o primeiro nó da lista circular
No* removerPrimeiroCircular(No **lista) {
    if (*lista == NULL) {
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *remover = *lista;
    if (remover->proximo == *lista) {
        *lista = NULL;
    } else {
        No *ultimo = *lista;
        while (ultimo->proximo != *lista) {
            ultimo = ultimo->proximo; 
        }
        *lista = remover->proximo; 
        ultimo->proximo = *lista; 
    }

    free(remover);
    return *lista;
}

// Remover o último nó da lista circular
No* removerUltimoCircular(No **lista) {
    if (*lista == NULL) {
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *ultimo = *lista;
    No *anterior = NULL;
    while (ultimo->proximo != *lista) {
        anterior = ultimo;
        ultimo = ultimo->proximo; 
    }

    if (anterior == NULL) {
        *lista = NULL;
    } else {
        anterior->proximo = *lista; 
    }

    free(ultimo);
    return *lista;
}

// Remover um nó em uma posição específica da lista circular
No* removerPosicaoCircular(No **lista, int posicao) {
    if (*lista == NULL) {
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *atual = *lista;
    No *anterior = NULL;
    int contador = 0;

    while (contador < posicao) {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    if (anterior == NULL) {
        No *ultimo = *lista;
        while (ultimo->proximo != *lista) {
            ultimo = ultimo->proximo;
        }
        *lista = atual->proximo;
        ultimo->proximo = *lista; 
    } else {
        anterior->proximo = atual->proximo; 
    }

    free(atual);
    return *lista;
}

// Pesquisar um nó na lista circular
No* pesquisarNoCircular(No *lista, int valor) {
    if (lista == NULL) {
        return NULL;
    }

    No *atual = lista;
    do {
        if (atual->dado == valor) {
            return atual; 
        }
        atual = atual->proximo;
    } while (atual != lista); 

    return NULL;
}

// Exibir lista circular
void ExibirNoListaCircular(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No *atual = lista;
    printf("Elementos da lista circular:\n");
    do {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    } while (atual != lista);
}

// Função principal
int main() {
    int opcao, opcao1, valor, loc;
    No *listaCircular = NULL;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Excluir\n\t3 - Buscar\n\t4 - Apresentar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\t1 - Inicio\n\t2 - Meio\n\t3 - Fim\n");
                scanf("%d", &opcao1);
                switch (opcao1) {
                    case 1:
                        printf("Informe um valor para inserir no início da lista: ");
                        scanf("%d", &valor);
                        IncluirInicioCircular(&listaCircular, valor);
                        break;
                    case 2:
                        printf("Informe um valor para inserir: ");
                        scanf("%d", &valor);
                        printf("Informe o valor de referência: ");
                        scanf("%d", &loc);
                        IncluirMeioCircular(&listaCircular, valor, loc);
                        break;
                    case 3:
                        printf("Informe um valor para inserir no final da lista: ");
                        scanf("%d", &valor);
                        IncluirFinalCircular(&listaCircular, valor);
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
                }
                break;
            case 2:
                printf("\n\t1 - Remover Primeiro\n\t2 - Remover Ultimo\n\t3 - Remover Posicao\n");
                scanf("%d", &opcao1);
                switch (opcao1) {
                    case 1:
                        listaCircular = removerPrimeiroCircular(&listaCircular);
                        break;
                    case 2:
                        listaCircular = removerUltimoCircular(&listaCircular);
                        break;
                    case 3:
                        printf("Informe a posicao a ser removida: ");
                        scanf("%d", &loc);
                        listaCircular = removerPosicaoCircular(&listaCircular, loc);
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
                }
                break;
            case 3:
                printf("Informe o valor a ser buscado: ");
                scanf("%d", &valor);
                No *encontrado = pesquisarNoCircular(listaCircular, valor);
                if (encontrado != NULL) {
                    printf("Valor encontrado na lista.\n");
                } else {
                    printf("Valor não encontrado na lista.\n");
                }
                break;
            case 4:
                ExibirNoListaCircular(listaCircular);
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida!\n");
                }
                break;
        }
    } while (opcao != 0);

    return 0;
}
