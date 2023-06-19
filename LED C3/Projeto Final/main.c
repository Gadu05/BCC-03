#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QTDE_PILHA 4
#define TAM_PILHA 3

typedef struct _conteiner{
    int codigo;
    struct _conteiner * proximo;
} Conteiner;

typedef struct _pilha{
    Conteiner * pilha;
    int TAM;
    int numPilha;
    struct _pilha * proximo;
} Pilha;

typedef struct _posicao{
    Pilha *pilha;
    int pos;
}Posicao;

void liberarMemoria(Pilha *p);
void operacaoInserir(Pilha *p);
void operacaoRemover(Pilha *p);
void operacaoConsultaConteiner(Pilha *p);
void operacaoConsulta(Pilha *p);

void inserirPilha(Pilha *p, int codigo);
void removerConteiner(Pilha *p, int codigo);

Pilha* iniciarPilha();
Pilha* liberarPilha(Pilha *p);
Pilha* acharMenorPilha(Pilha *p);

Conteiner* liberarConteiner(Conteiner *cont);

Posicao acharCodigo(Pilha *p, int codigo);

bool pilhasVazias(Pilha *p);

void menu(){

    printf("** ESCOLHA A OPERACAO QUE DESEJA REALIZAR:  **\n\n");
    printf("01. ADICIONAR UM CONTEINER\n");
    printf("02. REMOVER UM CONTEINER\n");
    printf("03. CONSULTAR UM CONTEINER\n");
    printf("04. EXEBIR TODOS OS CONTEINERS\n");

    printf("00. SAIR DO PROGRAMA\n\n");

    printf(">> ");

}

int main(){

    Pilha *p = iniciarPilha();
    int op;

    while(true){

        menu();
        scanf("%d", &op);
        fflush(stdin);
        system("cls");

        switch(op){
        case 0:
            liberarMemoria(p); /** SAIR*/
            return 0;
            break;
        case 1:
            operacaoInserir(p); /** INSERIR*/
            break;
        case 2:
            operacaoRemover(p); /** REMOVER*/
            break;
        case 3:
            operacaoConsultaConteiner(p); /** CONSULTA CONTEINER*/
            break;
        case 4:
            operacaoConsulta(p); /** CONSULTA*/
            break;
        default:
            printf("Opcao Invalida!\nPor favor, digite novamente.\n");
            break;
        }


    }


    //liberarMemoria(p);

    return 0;

}

void operacaoInserir(Pilha *p){

    int codigo;
    printf("Digite o codigo do conteiner:\n");
    scanf("%d", &codigo);
    fflush(stdin);
    system("cls");

    inserirPilha(p, codigo);


    getchar();
    system("cls");
    return;

}

void operacaoRemover(Pilha *p){

    if (pilhasVazias(p)){
        printf("Impossivel desempilhar!\n");
        getchar();
        system("cls");
        return;
    }

    int codigo;
    printf("Digite o codigo do conteiner:\n");
    scanf("%d", &codigo);
    fflush(stdin);
    system("cls");

    removerConteiner(p, codigo);


    getchar();
    system("cls");
    return;

}

void operacaoConsultaConteiner(Pilha *p){

    int codigo;
    printf("Digite o codigo do conteiner:\n");
    scanf("%d", &codigo);
    fflush(stdin);
    system("cls");

    Posicao busca = acharCodigo(p, codigo);

    if (busca.pilha == NULL){
        printf("Nao ha nenhum conteiner com esse codigo!\n");
        getchar();
        system("cls");
        return;
        return;
    }

    printf("O conteiner com o codigo: %d\n", codigo);
    printf("Esta na pilha %d, e na posicao %d\n", busca.pilha->numPilha, busca.pos);

    getchar();
    system("cls");
    return;

}

void operacaoConsulta(Pilha *p){

    Pilha *pilhaAtual = p;
    while(pilhaAtual != NULL){

        if (pilhaAtual->TAM > 0)
            printf("PILHA %d:\n", pilhaAtual->numPilha);

        int i = pilhaAtual->TAM;
        Conteiner *contAtual = pilhaAtual->pilha;
        while(contAtual != NULL){
            printf("-Codigo %05d:\n", contAtual->codigo);
            printf("   Posicao: %02d;\n", i--);
            contAtual = contAtual->proximo;
        }

        pilhaAtual = pilhaAtual->proximo;
        printf("\n");

    }


    getchar();
    system("cls");
    return;

}

void liberarMemoria(Pilha *p){

    Pilha *pilhaAtual = p;
    while (pilhaAtual != NULL){

        Conteiner *conteinerAtual = pilhaAtual->pilha;
        while (conteinerAtual != NULL){

            conteinerAtual = liberarConteiner(conteinerAtual);

        }

        pilhaAtual = liberarPilha(pilhaAtual);

    }

}

Pilha* liberarPilha(Pilha *p){

    if (p == NULL)
        return p;

    Pilha *rm = p;
    p = rm->proximo;
    free(rm);
    return p;

}

Conteiner* liberarConteiner(Conteiner *cont){

    if (cont == NULL)
        return cont;

    Conteiner *rm = cont;
    cont = rm->proximo;
    free(rm);
    return cont;

}


Pilha* iniciarPilha(){

    Pilha *p = NULL;

    for (int i = 0; i < QTDE_PILHA; i++){

        Pilha *novo = malloc(sizeof(Pilha));
        novo->pilha = NULL;
        novo->TAM = 0;
        novo->numPilha = i+1;
        novo->proximo = NULL;

        if (p == NULL){

            p = novo;
            continue;

        }

        Pilha * atual = p;
        while(atual->proximo != NULL)
            atual = atual->proximo;

        atual->proximo = novo;

    }

    return p;

}


void inserirPilha(Pilha *p, int codigo){

    if (acharCodigo(p, codigo).pilha != NULL){
        printf("Codigo invalido!\n");
        return;
    }

    Pilha *menorpilha = acharMenorPilha(p);

    if (menorpilha->TAM >= TAM_PILHA){
        printf("Impossivel empilhar!\n");
        return;
    }



    Conteiner * novo = malloc(sizeof(Conteiner));
    novo->codigo = codigo;
    novo->proximo = NULL;

    printf("Conteiner adicionado com sucesso!\n");
    if (menorpilha->pilha == NULL){
        menorpilha->pilha = novo;
        menorpilha->TAM++;
        return;
    }

    novo->proximo = menorpilha->pilha;
    menorpilha->pilha = novo;
    menorpilha->TAM++;

    return;

}

void removerConteiner(Pilha *p, int codigo){

    Posicao busca = acharCodigo(p, codigo);

    if (busca.pilha == NULL){
        printf("Codigo invalido!\n");
        return;
    }

    Conteiner *rm = busca.pilha->pilha;

    if (rm == NULL){
        printf("Impossivel desempilhar!\n");
        return;
    }

    if (rm->codigo != codigo){

        printf("Impossivel desempilhar!\n");
        return;

    }

    busca.pilha->pilha = rm->proximo;
    busca.pilha->TAM--;
    printf("Conteiner removido com sucesso!\n");
    free(rm);

    return;

}

Pilha* acharMenorPilha(Pilha *p){

    int menorPilha = p->TAM;
    Pilha *menor = p;
    Pilha *atual = p->proximo;

    while (atual != NULL){

        if (atual->TAM < menorPilha){
            menorPilha = atual->TAM;
            menor = atual;
        }

        atual = atual->proximo;

    }

    return menor;

}

Posicao acharCodigo(Pilha *p, int codigo){

    Pilha *aux = p;
    Posicao achou;
    achou.pilha = NULL;
    int pos;

    while (aux != NULL){

        pos = aux->TAM;

        Conteiner * atual = aux->pilha;
        while(atual != NULL){

            if (atual->codigo == codigo){
                achou.pilha = aux;
                achou.pos = pos;
                return achou;
            }

            atual = atual->proximo;
            pos--;

        }

        aux = aux->proximo;

    }

    return achou;

}

bool pilhasVazias(Pilha *p){

    Pilha *atual = p;
    if (atual != NULL){

        if (atual->TAM > 0)
            return false;

        atual = atual->proximo;

    }

    return true;

}
