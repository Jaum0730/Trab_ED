#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int matricula;
	//Data set
	char * nome;
	char * email;
	char * endereco;
	char * telefone;	
	
	struct No* fi_dir;
	struct No* fi_esq;



}NO;
NO * raiz1 = NULL;
NO * raiz2 = NULL;

//A variavel matricula corresponde a matricula da struct NO
//o aux contera a raiz de busca 
NO* Ler(int matricula, NO* aux){
    if(aux == NULL){
        return NULL; //vazia
    }
    //significa que eh a raiz
    else if(matricula == aux->matricula){
        return aux; //encontrei :D
    }
    else if(matricula<aux->matricula){ //buscar no lado esq
        if(aux->fi_esq != NULL){
            return Ler(matricula, aux->fi_esq);
        }
        else{//esq esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
    else{//buscar no lado dir
        if(aux->fi_dir != NULL){
            return Ler(matricula, aux->fi_dir);
        }
        else{//dir esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
}

void Cadastro(int matricula,char*nome,char*endereço,char*telefone,char*email, NO* raiz){
    NO* resp = Ler(matricula, raiz);
    if(resp == NULL || resp->matricula != matricula){// vazia ou eu posso adicionar
        NO* NEW = malloc (sizeof(NO));
        NEW->matricula = matricula;
        NEW->nome = nome;
        NEW->nome = endereço;
        NEW->nome = telefone;
        NEW->nome = email;
        NEW->fi_esq = NULL;
        NEW->fi_dir = NULL;

        if(resp == NULL){ //add na raiz
            raiz = NEW;
        }else{
            if(matricula < resp->matricula){
                resp->fi_esq = NEW;
            }else{
                resp->fi_dir = NEW;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso
        //havera chaves duplicadas
        printf("Add inválida. matricula duplicada");
    }

}


int main(){




















return 0;
}
