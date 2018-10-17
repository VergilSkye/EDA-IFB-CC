#include <string.h>
#include <stdio.h>
#include "dlist.h"
#include "alloc.h"

typedef struct pessoa{
  char nome[30];
  char cpf[30];
  int idade;
}pessoa;


void* constructor_pessoa(void* data){
    void* ptr = mallocx(sizeof(pessoa));
    memcpy(ptr,data,sizeof(pessoa));
    return ptr;
}

void destructor_pessoa(void* data){
  free(data);
}

 void* constructor_int(void* data){
     void* ptr = mallocx(sizeof(int));
     memcpy(ptr,data,sizeof(int));
     return ptr;
 }

void destructor_int(void* data){
    free(data);
}

void print_
_int(dlist_t* l){
    printf("\n");
    dlist_iterator_t it;
    for(it=l->head;it!=NULL;it=it->next){
        printf("%d -> ",*(int*)it->data);
    }
    printf("NULL\n");
    printf("\n");
}

void imprime_pessoa(pessoa* p){
  printf("Nome = ");
  printf("%s\n",p->nome);
  printf("CPF = ");
  printf("%s\n",p->cpf);
  printf("Idade = ");
  printf("%d\n",p->idade);
}

void print_dlist_pessoa(dlist_t* l){
    printf("\n");
    dlist_iterator_t it;
    for(it=l->head;it!=NULL;it=it->next){
        imprime_pessoa(it->data);
    }
    printf("NULL\n");
    printf("\n");
}
void le_pessoa(pessoa* p){
  printf("Nome = ");
  scanf("%s",p->nome);
  printf("CPF = ");
  scanf("%s",p->cpf);
  printf("Idade = ");
  scanf("%d",&(p->idade));
}


int main()
{
    dlist_t* dl1;
    dlist_t* dl2;
    dlist_t* dl3;
    
    dlist_initialize(&dl1,constructor_pessoa,destructor_pessoa);
    dlist_initialize(&dl2,constructor_pessoa,destructor_pessoa);
    dlist_initialize(&dl3,constructor_int,destructor_int);
    
    int i;
    for(i=0;i<3;i++){
        pessoa p;
        le_pessoa(&p);
        dlist_append(dl1,&p);
        dlist_prepend(dl2,&p);
        dlist_append(dl3,&i);
    }
    print_dlist_pessoa(dl1);
    print_dlist_pessoa(dl2);
    print_dlist_int(dl3);
    
    dlist_delete(&dl1);
    dlist_delete(&dl2);
    dlist_delete(&dl3);

    return 0;
}
