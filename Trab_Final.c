#include <stdio.h>
#include <stdlib.h>


typedef struct No{
	
	int matricula;
	
	struct Aluno_set{
	char *nome[1]; 
	char *email[2];
	char *telefone[2];
	char *endereco[2];
}aluno;
	struct Disciplinas{
	char *disciplinas[10];
	char *code[10];
	int *nota_final[10];
}disciplina;
	
	aluno aln;
	struct No* fi_esq;
	struct No* fi_dir;



}NO;

NO * raiz1 = NULL;
NO * raiz2 = NULL;

//A variavel matricula corresponde a matricula da struct NO
//o aux contera a raiz de busca 
//A funcao "Ler" faz o papel de busca
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

void Cadastro(int matricula,char*nome,char*endereco,char*telefone,char*email, NO* raiz){
    NO* resp = Ler(matricula, raiz);
    if(resp == NULL || resp->matricula != matricula){// vazia ou eu posso adicionar
        NO* NEW = malloc (sizeof(NO));
        NEW->matricula = matricula;
        NEW->aluno.nome[0] = nome;
        NEW->aluno.endereco[0] = endereco;
        NEW->aluno.telefone[0] = telefone;
        NEW->aluno.email[0] = email;
        NEW->fi_esq = NULL;
        NEW->fi_dir = NULL;

        if(resp == NULL){ //add na raiz
            raiz = NEW;
        }
        else{
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

 
NO* Excluir( NO*pt ,int matricula){
    
	
	//caso da lista está vazia
    if(pt==NULL){
        return NULL;
    //caso de ser uma folha ou raiz   
    }else if(pt->fi_esq==NULL && pt->fi_dir==NULL){
        if(pt->matricula > matricula){
            pt->fi_esq = Excluir(pt->fi_esq, matricula);
        }
        else{
             pt->pai->fi_esq = NULL;
        }
    //caso de estar no lado direito
    }else if(pt->fi_dir !=NULL && pt->fi_esq == NULL){
        if(pt->matricula > pt->pai->matricula){
            pt->pai->fi_dir = pt->fi_dir;
        }
        else{
             pt->pai->fi_esq = pt->fi_dir;
        }

    }else if(pt->fi_dir ==NULL && pt->fi_esq != NULL){
          if(pt->matricula > pt->pai->matricula){
            pt->pai->fi_dir = pt->fi_esq;
        }else{
             pt->pai->fi_esq = pt->fi_esq;
        }
    }else{
        NO* aux = pt;
       while (aux->fi_dir != NULL) {
          aux = aux->fi_dir;
       }
        pt->matricula = aux->matricula;
        if(pt->fi_dir->matricula == pt->matricula){
            pt->fi_dir = NULL;
        }
        aux->pai->fi_dir= NULL;
        if(aux ->fi_esq != NULL){
            NO* aux2 = busca(aux->fi_esq->matricula, raiz1);
            aux2->fi_dir = aux->fi_esq;
        }
    }

    return pt;
}

void in_ordem(NO* aux){

    if(aux->fi_esq = NULL){
        in_ordem(aux->fi_esq);
    }

    printf("%d\t" , aux->matricula);

    if(aux->fi_dir != NULL){
        in_ordem(aux->fi_dir);
    }
}


NO *buscar(NO *raiz, int matricula){
    if(raiz){
        if(matricula == raiz->aln.matricula)
            return raiz;
        else if(matricula < raiz->aln.matricula)
            return buscar(raiz->esq, matricula);
        else
             return buscar(raiz->dir, matricula);
    }
    return NULL;
}



int main(){




















return 0;
}
