#include <stdio.h>
#include <stdlib.h>

int op;

struct Pilha{
    int topo; //posiçao elemento topo
    int capa;
    float *pElem;
}dados;

void criarpila(struct Pilha *p, int c){
//o operador '->' é equivalente a seguinte expressao: '(*ponteiro).membro'
    p->topo = -1;
    p ->capa = c;
//A funçao malloc() aloca size bytes e retorna um ponteiro para a memoria alocada.
//a memoria nao é inicializada.
p->pElem = (float*) malloc (c * sizeof(float));
}

int estavazia(struct Pilha *p){
    if(p-> topo ==-1){return 1;}//true
    else{return 0;}//false
}

int estacheia(struct Pilha *p){
    if(p-> topo ==p->capa-1){return 1;}//true
    else{return 0;}//false
}

void empilhar(struct Pilha *p, float v){
    p->topo++;
    p->pElem[p->topo] = v;
}

float desimpilhar(struct Pilha *p){
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}

float returnatopo(struct Pilha *p){
    return p->pElem[p->topo];
}


int main()
{
    dados p;
    dados *minhapilha = criarpila(p, 6);
    while(1){
        float valor;
        printf("\n\n1 - Empilhar\n2 - Desimpilhar\n3 - Mostrar Topo\n4 - Sair\n > ");
        scanf("%d", &op);

        switch(op){
            case 1://empilha
               if(estacheia(&minhapilha) == 1){printf("\n\nCheia !");}
                else{

                    printf("Valor: ");
                    scanf("%f", valor);
                    empilhar(&minhapilha, valor);
                }
            break;

            case 2://desimpilha
                if(estavazia(&minhapilha) == 1){printf("\n\nVazia");}
                else{valor = desimpilhar(&minhapilha); printf("\n%.1f Desimpilhado\n", valor);}
             break;

            case 3:
                if(estavazia(&minhapilha)==1){printf("\n\nVazia");}
                else{
                    valor = returnatopo(&minhapilha);
                    printf("\nTopo: %.1f\n", valor);
                }
            break;

            case 4:
                exit(0);
                break;
            default:
                printf("Insira algo válido !");
                break;
        }
    }


}
