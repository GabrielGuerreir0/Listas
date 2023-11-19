#include <stdio.h>
#include <stdlib.h>


// estrutura
typedef struct no{
    int dado;
    struct no *proximo;
    struct no *anterior;
}No;

//inserir inicio
void IncluirInicioDupla(No** lista, int num){

 No* novoNo = (No*) malloc(sizeof(No));

 if(novoNo){
novoNo->dado = num;
novoNo->proximo =*lista;
novoNo->anterior =NULL;
if(*lista){
    (*lista) ->anterior=novoNo;
}
*lista = novoNo;
 }else{
    printf("Erro na alocação de memoria!");
 } 
}


//inserir meio
void IncluirMeioDupla(No** lista, int num, int ref){

No *aux,*novoNo = (No*) malloc(sizeof(No));

 if(novoNo){
novoNo->dado = num;
    if(*lista == NULL){
        novoNo->proximo=NULL;
        novoNo->anterior=NULL;
        *lista=novoNo;
    }else{
        aux=*lista;
        while(aux->dado != ref && aux->proximo){
            aux =aux->proximo;
        }
        novoNo->proximo = aux->proximo;
        aux->proximo->anterior =novoNo;
        novoNo->anterior =aux;
        aux->proximo = novoNo;
    }

 }else{
    printf("Erro na alocação de memoria!");
 } 

}


//inserir final
void IncluirFinalDupla(No** lista, int num){

No *aux,*novoNo = (No*) malloc(sizeof(No));

 if(novoNo){
novoNo->dado = num;
novoNo->proximo =NULL;
if(*lista == NULL){
    *lista = novoNo;
    novoNo->anterior = NULL;
}
else{
    aux =*lista;
    while (aux->proximo)
    {
        aux =aux->proximo;
    }
    aux->proximo = novoNo;
    novoNo->anterior =aux;
    
}
 }else{
    printf("Erro na alocação de memoria!");
 }

} 


//remover o primeiro
No* removerPrimeiro(No **lista){
    if (*lista == NULL){
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *remover = *lista;
    *lista = (*lista)->proximo;
    if (*lista != NULL){
        (*lista)->anterior = NULL;
    }

    free(remover);
    return *lista;
}

//remover o ultimoi
No* removerUltimo(No **lista){
    if (*lista == NULL){
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *aux = *lista;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }

    if (aux->anterior != NULL){
        aux->anterior->proximo = NULL;
    } else {
        *lista = NULL;
    }

    free(aux);
    return *lista;
}

// remover  posição especifica
No* removerPosicao(No **lista, int posicao){
    if (*lista == NULL){
        printf("Lista vazia, não há nada para excluir.\n");
        return NULL;
    }

    No *aux = *lista;
    int contador = 0;

    while (aux != NULL && contador < posicao){
        aux = aux->proximo;
        contador++;
    }

    if (aux == NULL){
        printf("Posição inválida.\n");
        return *lista;
    }

    if (aux->anterior != NULL){
        aux->anterior->proximo = aux->proximo;
    } else {
        *lista = aux->proximo;
    }

    if (aux->proximo != NULL){
        aux->proximo->anterior = aux->anterior;
    }

    free(aux);
    return *lista;
}

//pesquisar no
No* pesquisarNo(No *lista, int valor){
    No *aux = lista;

    while (aux != NULL){
        if (aux->dado == valor){
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}

//exibir lista
void ExibirNoLista(No *no){
    printf("\n\tLista:\n");
    while (no)
    {
        printf("%d\n", no->dado);
        no =no->proximo;
    }
    printf("\n\n");

}


//função principal
int main(){

    int opcao, opcao1, elemento, valor, loc;
    No *lista =NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Excluir\n\t3 - Buscar\n\t4 - apresentar\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            
            printf("\n\t1 - Inicio\n\t2 - Meio\n\t3 - Fim\n");
            scanf("%d",&opcao1);
                switch (opcao1)
                {
                case 1:
                    printf("Informe um valor: ");
                    scanf("%d",&valor);
                    IncluirInicioDupla(&lista,valor);
                    break;
                case 2:
                    printf("Informe um valor: ");
                    scanf("%d",&valor);
                    printf("informe o valor que este numero deve ser acrecentado apos ele: ");
                    scanf("%d",&loc);
                    IncluirMeioDupla(&lista,valor,loc);
                    break;
                case 3:
                    printf("Informe um valor: ");
                    scanf("%d",&valor);
                    IncluirFinalDupla(&lista,valor);
                    break;
                default:
                    printf("opcao invalida!\n");
                    break;
                }
            break;
        case 2:
            printf("\n\t1 - Remover Primeiro\n\t2 - Remover Ultimo\n\t3 - Remover Posicao\n");
            scanf("%d", &opcao1);
                switch (opcao1){
            case 1:
                lista = removerPrimeiro(&lista);
                break;
            case 2:
                lista = removerUltimo(&lista);
                break;
            case 3:
                printf("Informe a posição anterior da que deve ser removida: ");
                scanf("%d", &loc);
                lista = removerPosicao(&lista, loc);
                break;
            default:
                printf("opcao invalida!\n");
                break;
            }
            break;
        case 3:
            printf("Informe o valor a ser buscado: ");
            scanf("%d", &valor);
            No *encontrado = pesquisarNo(lista, valor);
            if (encontrado != NULL){
                printf("Valor encontrado na lista.\n");
            } else {
                printf("Valor não encontrado na lista.\n");
            }
            break;
        case 4:
            ExibirNoLista(lista);
            break;
        default:
            if (opcao != 0)
            {
                printf("opcao invalida!\n");
            }
            break;
        }
    }while (opcao != 0);
    
    return 0;
}