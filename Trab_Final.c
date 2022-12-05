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

void Cadastro1(int matricula,char*nome,char*endereco,char*telefone,char*email){
            NO* resp = Ler(matricula, raiz1);
                if(resp == NULL || resp->matricula != matricula){// vazia ou eu posso adicionar
                    NO* NEW = malloc(sizeof(NO));
                    NEW->matricula = matricula;
                    NEW->aluno.nome[0] = nome;
                    NEW->aluno.endereco[0] = endereco;
                    NEW->aluno.telefone[0] = telefone;
                    NEW->aluno.email[0] = email;
                    NEW->fi_esq = NULL;
                    NEW->fi_dir = NULL;
    

                        if (resp == NULL){ //add na raiz
                            raiz1 = NEW;
                        }
                        else{
                            if(matricula < resp->matricula){
                                raiz1->fi_esq = NEW;
                            }
                             else{
                                raiz1->fi_dir = NEW;
                            }
                        }
                }                        
                else{//nao posso deixar add novamente pq neste caso
                //havera chaves duplicadas
                    printf("Add inválida. matricula duplicada");
                    }
            


}



void Cadastro2(int matricula,char*nome,char*endereco,char*telefone,char*email){
            NO* resp = Ler(matricula, raiz2);
                if(resp == NULL || resp->matricula != matricula){// vazia ou eu posso adicionar
                    NO* NEW = malloc(sizeof(NO));
                    NEW->matricula = matricula;
                    NEW->aluno.nome[0] = nome;
                    NEW->aluno.endereco[0] = endereco;
                    NEW->aluno.telefone[0] = telefone;
                    NEW->aluno.email[0] = email;
                    NEW->fi_esq = NULL;
                    NEW->fi_dir = NULL;
    

                        if (resp == NULL){ //add na raiz
                            raiz2 = NEW;
                        }
                        else{
                            if(matricula < resp->matricula){
                                raiz2->fi_esq = NEW;
                            }
                             else{
                                raiz2->fi_dir = NEW;
                            }
                        }
                }                        
                else{//nao posso deixar add novamente pq neste caso
                //havera chaves duplicadas
                    printf("Add inválida. matricula duplicada");
                    }
            


}

NO *Excluir(NO *raiz, int matricula){

	if (raiz != NULL)
	{
		if (matricula > raiz->matricula)
		{
			//busca na direita
			raiz->fi_dir = Excluir(raiz->fi_dir, matricula);
		

		}else if (matricula < raiz->matricula)
		{
			//busca na esquerda
			raiz->fi_esq = Excluir(raiz->fi_esq, matricula);
	
		}
		else //encontrou o elemento a ser removido
		{
			//removendo nó folha
			if (raiz->fi_esq == NULL && raiz->fi_dir == NULL)
			{
				free(raiz);
				raiz = NULL;
			
				return NULL;
			}
			else if (raiz->fi_esq == NULL && raiz->fi_dir != NULL)
			{
				//faz a ponte de ligação com a sub Arvore direita
				NO *aux = raiz->fi_dir; //salva  a sub Arvore direita
				free(raiz); //apaga o nó onde a fun está no momento
				raiz = NULL;
		
				return aux; //retorna pro ant do nó excluido a subArv dir
			}
			else if (raiz->fi_esq != NULL && raiz->fi_dir == NULL)
			{
				//faz a ponte de ligação com a sub Arvore esquerda
				NO *aux = raiz->fi_esq;
				free(raiz);
				raiz = NULL;

				return aux;
			}
		}
		return raiz;

	}
	else{
		return NULL;

	}
}






void in_ordem(NO* aux){

    if(aux->fi_esq != NULL){
        in_ordem(aux->fi_esq);
    }

    printf("%i\t" , aux->matricula);

    if(aux->fi_dir != NULL){
        in_ordem(aux->fi_dir);
    }
}
void alterar(int matricula,NO*raiz){

    NO * aux = Ler(matricula, raiz);

    if(aux == NULL){
        printf("\nNao ha alunos matriculados\n\n");

    }else{

        printf("Qual dado deseja modificar? \n[1] Nome \n[2] e-mail \n[3] Cancelar\n \n[4] telefone \n [5] endereco");
        scanf("%d", &matricula);

        if (matricula == 1){

            printf("Digite o nome:\n");
            scanf("%s", aux->aluno.nome);
        }
        if (matricula == 2){
            printf("Digite o e-mail:\n");
            scanf("%s", aux->aluno.email);
            
        }
        if (matricula == 3){

            printf("Mudanca cancelada, nenhum dado alterado\n\n");        
        }if(matricula == 4){
		 printf("digite o telefone:\n");
	         scanf("%s",aux->aluno.telefone);
	}if(matricula== 5){
	    printf("digite o endereco:\n");
	    scanf("%s",aux->aluno.endereco);
    }
    }
}


int main(){
char *nome = "joao";
char *endereco = "j";
char *telefone = "jo";
char *email = "jao";
Cadastro1(511226,nome,endereco,telefone,email);
Cadastro1(511227,nome,endereco,telefone,email);
Cadastro2(511225,nome,endereco,telefone,email);

Excluir(raiz1,511226);
alterar(511227,raiz1);
in_ordem(raiz1);
printf("\n");
in_ordem(raiz2);



















return 0;
}
