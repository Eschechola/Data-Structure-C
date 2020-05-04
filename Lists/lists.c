#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct celulaLista{
   int codigo;
   char nome[40];
   char endereco[40];
   struct celulaLista *proximo;
}celula;

void initLista(celula **pRecebido){
   (*pRecebido)->proximo = NULL;
}

void insertLista(celula **pRecebido){
   // Declara��es
      celula *temporario;
      int cod;
      char nome[40];
      char endereco[40];
   // Instru��es
        system("cls");
     /* printf("Nome: ");
     scanf("%[^\n]", &nome);
      printf("Endere�o: ");
      fflush(stdin);
      scanf("%[^\n]", &endereco);
      fflush(stdin);*/
      printf("C�digo: ");
      scanf("%d", &cod);
      temporario = (celula *)malloc(sizeof(celula));
      temporario->codigo = cod;
      /*strcpy(temporario->nome, nome);
      strcpy(temporario->endereco, endereco);*/
      temporario->proximo = (*pRecebido)->proximo;
      (*pRecebido)->proximo = temporario;
}

void buscaListaSimples(celula **pRecebido){
   // Declara��es
      celula *temporario;
   // Instru��es
      if((*pRecebido)->proximo == NULL){
         printf("Nenhum Restaurante Encontrado!\n");
      }
      else{
         temporario = (celula *)malloc(sizeof(celula));
         temporario = (*pRecebido)->proximo;
         while(temporario != NULL){
            printf("Nome: %d\n", temporario->nome);
            printf("Endere�o: %d\n", temporario->endereco);
            printf("Codigo: %d\n", temporario->codigo);
            temporario = temporario->proximo;
         }
      }
}

void removeElementoListaSimples(celula **pRecebido){
   // Declara��es
      celula *temporario;
   // Instru��es
      if((*pRecebido)->proximo == NULL){
         printf("\nLista Vazia!");
      }
      else{
         temporario = (*pRecebido)->proximo;
         (*pRecebido)->proximo = temporario->proximo;
         free(temporario);
      }
}

int main(){

    char op;
    celula *pLista;

    void initLista(celula **pRecebido);
    void insertLista(celula **pRecebido);
    void buscaListaSimples(celula **pRecebido);
    void removeElementoListaSimples(celula **pRecebido);

    while(1){
        system("cls");
        printf("  +################################################################+\n");
        printf("  #                                                                #\n");
        printf("  #                            Registro                            #\n");
        printf("  #                               De                               #\n");
        printf("  #                          Restaurantes                          #\n");
        printf("  #                                                                #\n");
        printf("  +################################################################+\n");
        printf("  #                                                                #\n");
        printf("  #   <1> - Inserir                                                #\n");
        printf("  #   <2> - Consultar                                              #\n");
        printf("  #   <3> - Remover                                                #\n");
        printf("  #   <4> - Sair                                                   #\n");
        printf("  #   > ");
        op=getch();
        switch(op){

            case '1':
                insertLista(&pLista);
                break;

            case '2':
                buscaListaSimples(&pLista);
                break;

            case '3':
                removeElementoListaSimples(&pLista);
                break;

            case '4':
                exit(0);
                break;

            default:
                break;
        }
    }
}
