/*Construa, em C, um programa que contenha as seguintes
fun��es de Lista Encadeada- B�sica
� Inser��o de um Elemento da Lista (inserir no in�cio)
� Remo��o de um Elemento da Lista (retirar do in�cio)
� Impress�o da Lista
� Busca de um elemento na Lista, retorna 1 se ele existe e 0
caso contr�rio
� Uma fun��o que verifica se a lista est� vazia, retorna 1 se ela
estiver vazia e 0 caso contr�rio
� Uma fun��o que retorne a quantidade de elementos de uma
lista. A lista � passada por par�metro .
� Uma fun��o que some os elementos de uma lista que �
passada por par�metro*/



/*pr�ximo passo:

    � Inser��o de um Elemento da Lista (inserir no fim da lista)
� Remo��o de um Elemento da Lista (retirar do fim da lista)
� Uma fun��o que retorna a quantidade de n�meros �mpares da
lista
� Uma fun��o que receba duas listas e retorne uma terceira lista
que � a uni�o dessas duas listas (N�o � permitido elementos
repetidos na Lista Uni�o)*/


#include <stdio.h>
#include <stdlib.h>

typedef struct no{

int info;
struct no *prox;


}No;

typedef No Lista;


Lista* Inicializa(){

return NULL;

}

Lista* Remover(Lista *inicioLista){


if(inicioLista == NULL){

    printf("\nNao eh possivel remover, a Lista esta vazia!");
    return inicioLista;
}


Lista *aux = inicioLista;
inicioLista = inicioLista -> prox;

free(aux);

return inicioLista;
}


Lista* RemoveFim (Lista *inicioLista){


if (inicioLista == NULL){

    printf("\nLista Vazia");
    return inicioLista;

}

if (inicioLista->prox == NULL){ //caso para quando existir um n� s� na lista

    free(inicioLista);
    return NULL;


}

No *aux1 = inicioLista;             //o ponteiro aux1 vai caminhar antes do aux2, porque eu vou precisar fazer o n� que ele est� apontar para NULL e liberar o aux2 � frente
No *aux2 = inicioLista->prox;


while(aux2->prox != NULL){           //s� vou caminhar enquanto aux2-> prox nao for NULL. quando for NULL, vou liberar aux2 e fazer aux1 atras dele apontar para null

aux2 = aux2 -> prox;
aux1 = aux1 -> prox;


}

//quando o aux2-> prox = null

aux1 -> prox = NULL;
free (aux2);

return inicioLista; //retorna o inicio porque eu nao mudei nada nele apenas o fim da lista

}




void Imprime(Lista *InicioLista){

Lista *aux = InicioLista;

if (InicioLista == NULL){

    return;
}

printf("\nLista = \n");

while(aux!=NULL){


  printf("%d ", aux->info);
  aux = aux->prox;

}


}


Lista* Insere(Lista* inicioVelho, int info){

No *novo = (No*)malloc(sizeof(No));
if (novo == NULL){

    printf("\nImpossivel alocar memoria");
    return inicioVelho;
}

novo -> info = info;
novo -> prox = inicioVelho;

return novo;

}



Lista* InsereFim (Lista *inicioLista, int info){

No *novo = (No*)malloc(sizeof(No));

if (novo == NULL){

    printf("\nNao foi possivel alocar memoria para o novo n�");
    return inicioLista; //envia o proprio inicio


}

novo -> info = info; //o n� deve estar pronto antes de entrar na lista
novo -> prox = NULL;


Lista *aux = inicioLista;

    if (inicioLista == NULL){

        return novo; //inicio aponta para o novo n� caso ele estivesse apontando para NULL (ou seja, Lista vazia)


    }

    while(aux->prox != NULL){


        aux = aux -> prox;

    }
       aux -> prox = novo;


        return inicioLista; //nao mudei o inicio, apenas acrescentei um n� no final

}

int Busca (Lista *inicioLista, int num){

Lista *aux = inicioLista;

while (aux != NULL){

    if(num == aux->info){

        return 1;

    }
        aux = aux-> prox;

}

return 0;

}


int Vazia(Lista *inicioLista){

if (inicioLista == NULL){
    return 1;

}

return 0;
}



int qtdElementos(Lista *inicioLista){

Lista *aux = inicioLista;
int cont = 0;

while(aux != NULL){

    cont++;

    aux = aux -> prox;
}

return cont;

}


int SomaElementos (Lista *inicioLista) {


int SomaLista = 0;
Lista *aux = inicioLista;

while(aux != NULL){

    SomaLista += aux -> info;

    aux = aux -> prox;
}


return SomaLista;
}




Lista* ListUniao (Lista *Inicio1, Lista *Inicio2){


Lista *Inicio3 = Inicializa(); //inicio aponta para null
No *aux = Inicio1;


No *novo;

while (aux != NULL){

novo = (No*)malloc (sizeof(No));
novo-> info = aux -> info;
novo-> prox= Inicio3; //inicio velho
Inicio3 = novo;
aux = aux ->prox;
}


}

















int main(){

Lista *inicio;
int valor = 4;
int existe;
int numero = 5;
int vaziaouNao;
int quantidadeElementos;
int Sum;

inicio = Inicializa();
inicio = Insere (inicio, valor);
inicio = Remover (inicio);
inicio = Insere (inicio, valor);
Imprime(inicio);
existe = Busca(inicio, numero);
vaziaouNao = Vazia(inicio);
quantidadeElementos = qtdElementos(inicio);
Sum = SomaElementos(inicio);

return 0;
}
