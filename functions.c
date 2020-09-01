#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nude{
    char *materia;
    char *nota;
    struct nude* next;
}Node_sec;

typedef struct listinha{
    int tamanho;
    Node_sec* cabeca;
}Lista_sec;

typedef struct node{
    int matricula;
    int diciplina;
    char *nome;
    char *email;
    Lista_sec* materias;
    struct node* next;
}Node;

typedef struct lista{
    int tamanho;
    Node* cabeca;
}Lista;



char * cap_texto(char *palavra){
	char h;
	int j=0;

	while((h = getchar()) != '\n' && h != EOF && h != '\0'){
        palavra = (char *)realloc(palavra,(j+1)* sizeof(char));
        palavra[j++] = h;
    }
    palavra[j] = '\0';
    return palavra;
    }

Lista* criarlista(){
    Lista* lista = (Lista *) malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->cabeca = NULL;
    return lista;
    }

Lista_sec* criarlista_sec(){
    Lista_sec* lista_sec = (Lista_sec *) malloc(sizeof(Lista_sec));
    lista_sec->tamanho = 0;
    lista_sec->cabeca = NULL;
    return lista_sec;   
}

bool is_empty(Lista * lista){
    if(lista->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool is_empty_sec(Lista_sec * lista_sec){
    if(lista_sec->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

Node * at_pos(Lista * lista, int indice){
    if(is_empty(lista) || indice >= lista->tamanho){
    	return NULL;
    }else{
        int i=0;
        Node * ponteiro = lista->cabeca;
        while(ponteiro != NULL){
            if(i == indice){
                return ponteiro;
            }
            i++;
            ponteiro = ponteiro->next;
        }
    }
    return NULL;
}

Node_sec * at_pos_sec(Lista_sec * lista_sec, int indice){
    if(is_empty_sec(lista_sec) || indice >= lista_sec->tamanho){
    	return NULL;
    }else{
        int i=0;
        Node_sec * ponteiro_sec = lista_sec->cabeca;
        while(ponteiro_sec != NULL){
            if(i == indice){
                return ponteiro_sec;
            }
            i++;
            ponteiro_sec = ponteiro_sec->next;
        }
    }
    return NULL;
}

void Cadastrar(Lista* lista, Node* node){
    int i,quant,cont;

    printf("Quantas pessoas deseja cadastrar:");
    scanf(" %d",&quant);getchar();
    cont = lista->tamanho;
    quant= cont+quant;
    for(cont;cont < quant;cont++){
        node = (Node*) malloc(sizeof(Node));
        node->materias = criarlista_sec();
        printf("matrícula:");
        scanf(" %d",&node->matricula);getchar();
        
        printf("nome:");
        node->nome = cap_texto(node->nome);
        
        printf("email:");
        node->email = cap_texto(node->email); 
        printf("\n");

        node->diciplina = 0;
        node->next = lista->cabeca;
        lista->cabeca = node;
        lista->tamanho++;
        }
    }
    char* verificar(char* validar){
        if (strcmp(validar,"MM")== 0){
            return validar; }
        if (strcmp(validar,"MS")== 0){
            return validar; }
        if (strcmp(validar,"SS")== 0){
            return validar; }
        if (strcmp(validar,"MI")== 0){
            return validar; }
        if (strcmp(validar,"II")== 0){
            return validar; }
        if (strcmp(validar,"SR")== 0){
            return validar; }
        if (strcmp(validar,"TR")== 0){
            return validar; }
        else{
            printf("------------------- Digite uma menção válida -------------------\n");
            printf("Menção:");
            validar = cap_texto(validar);
            validar = verificar(validar);
        }
    }

    void Cadastrar_disciplina(Node* node, Lista_sec* lista_sec){
    int i,quant,cont;
    char *validar;

    printf("Quantas matérias deseja cadastrar:");
    scanf(" %d",&quant);getchar();
    cont = lista_sec->tamanho;
    quant= cont+quant;
    Node_sec* node_sec;
    for(cont;cont < quant;cont++){
        node_sec = (Node_sec *) malloc(sizeof(Node_sec));

        printf("-----------------------------------\n");
        printf("matéria:");
        node_sec->materia = cap_texto(node_sec->materia);
        
        printf("Menção:");
        validar= cap_texto(node_sec->nota);
        validar = verificar(validar);
        node_sec->nota = validar;
        printf("-----------------------------------\n");

        node_sec->next = lista_sec->cabeca;
        lista_sec->cabeca = node_sec;
        lista_sec->tamanho++;
        node->diciplina++;

        }
    }
void imprimirlista(Lista * lista){
    Node* ponteiro = lista->cabeca;

    if(ponteiro == NULL){
        printf("\n\n------------------- Não existem alunos cadastrados -------------------\n\n");  
    }

    for(int cont=0;cont < lista->tamanho;cont++){
        printf("-----------------------------------\n");
        printf("Aluno:%d\n", cont);
        printf("Nome:%s\n", ponteiro->nome);
        printf("Email:%s\n", ponteiro->email);
        printf("Matricula:%d\n", ponteiro->matricula);
        if(ponteiro->diciplina == 0){
            printf("Histórico:Aluno sem disciplina\n");   
        }
        else{
            printf("Histórico:%d\n", ponteiro->diciplina);
        }
        printf("-----------------------------------\n");
        ponteiro = ponteiro->next;
    }
    }
void imprimirlista_sec(Lista_sec * lista_sec){
    Node_sec* ponteiro = lista_sec->cabeca;

    if(ponteiro == NULL){
        printf("\n\n----------------- Não existem diciplinas cadastradas -----------------\n\n");  
    }
    for(int cont=0;cont < lista_sec->tamanho;cont++){
        printf("-----------------------------------\n");
        printf("Posição:%d\n", cont);
        printf("Matéria:%s\n", ponteiro->materia);
        printf("Menção:%s\n", ponteiro->nota);
        printf("-----------------------------------\n");

        ponteiro = ponteiro->next;
    }
    printf("\n");
    }


int Buscar(Lista* lista, char *busca, Node* ponteiro, int i){
    int r;
    char res;

    if(ponteiro == NULL){
        return -1;    
    }
    for(i;i<lista->tamanho;ponteiro = ponteiro->next){
        i++;
        if(i == lista->tamanho){
            return -1;
            }
        if(strstr(ponteiro->nome,busca) || strstr(ponteiro->email,busca)){
            printf("-----------------------------------\n");
            printf("Aluno %d\n", i);
            printf("Nome:%s\n",ponteiro->nome);
            printf("Email:%s\n",ponteiro->email);
            printf("Matricula:%d\n", ponteiro->matricula);
            printf("-----------------------------------\n");
            printf("Este é o aluno buscado?\nS ou N\nResposta:");
            scanf(" %c", &res);
            if(res == 'S'){
                return i;
                }
            else{
                if(i<lista->tamanho){
                    ponteiro = ponteiro->next;
                    i = Buscar(lista,busca,ponteiro,i);
                    return i;
                }
                else{
                    return -1;
                    }}}}
    return -1;
            }

int Buscar_sec(Lista_sec* lista_sec, char *busca, Node_sec* ponteiro_sec,int i){
    int r;
    char res;

    if(ponteiro_sec == NULL){
        return -1;    
    }
    for(i;i<lista_sec->tamanho;ponteiro_sec = ponteiro_sec->next){
        i++;
        if(i == lista_sec->tamanho){
            return -1;
            }
        if(strstr(ponteiro_sec->materia,busca)){

            printf("-----------------------------------\n");
            printf("Materia:%s\n",ponteiro_sec->materia);
            printf("Menção:%s\n",ponteiro_sec->nota);
            printf("-----------------------------------\n");
            printf("Este é a matéria buscado?\nS ou N\nResposta:");
            scanf(" %c", &res);
            if(res == 'S'){
                return i;
                }
            else{
                if(i<lista_sec->tamanho){
                    ponteiro_sec = ponteiro_sec->next;
                    i = Buscar_sec(lista_sec,busca,ponteiro_sec,i);
                    return i;
                }
                else{
                    return -1;
                    }}}}
    return -1;
            }

void Editar(Lista* lista){
    int i=-1;
    char x, a, y,t,*b = NULL;
    Node* ponteiro = lista->cabeca;

    if(ponteiro == NULL){
        printf("\n\n--------------- Não existem alunos para serem editados ---------------\n\n");
        return; 
    }
    printf("\nDigite o nome ou email do aluno que deseja editar: "); getchar();
    b = cap_texto(b);

    i = Buscar(lista,b,ponteiro,i);
    if(i == -1){
        printf("\n---------------Sem Correspondência---------------\n");
        return;
    }
    ponteiro = at_pos(lista, i);

    printf("Deseja alterar o nome?\n S ou N\nResposta:"); 
    scanf(" %c", &a);getchar();

    if(a == 'S'){
        printf("Nome:");
        ponteiro->nome = cap_texto(ponteiro->nome);
    }
    printf("Deseja alterar o email?\n S ou N\nResposta:"); 
    scanf(" %c", &y);getchar(); 
    if(y == 'S'){
        printf("email:");
        ponteiro->email = cap_texto(ponteiro->email); 
    }
    
    printf("Deseja alterar a Matrícula:?\n S ou N\nResposta:"); 
    scanf(" %c", &x); 
    if(x == 'S'){               
        printf("Matrícula:");
        scanf(" %d",&ponteiro->matricula);
    }
    }

void Editar_sec(Lista_sec* lista_sec){
    int i=-1;
    char x, a, y,t,*validar,*b = NULL;
    Node_sec* ponteiro_sec = lista_sec->cabeca;

    if(lista_sec->tamanho == 0){
        printf("\n\n-------------- Não existem matéria para serem editadas --------------\n\n");
        return; 
    }
    getchar();
    printf("\n Digite o nome da matéria que deseja editar:  ");
    b = cap_texto(b);

    i = Buscar_sec(lista_sec,b,ponteiro_sec,i);
    if(i == -1){
        printf("\n---------------Sem Correspondência---------------\n");
        return;
    }
    ponteiro_sec = at_pos_sec(lista_sec, i);


    printf("Deseja alterar essa Materia?\n S ou N\nResposta:"); 
    scanf(" %c", &a);getchar();

    if(a == 'S'){
        printf("Materia:");
        ponteiro_sec->materia = cap_texto(ponteiro_sec->materia);
    }
    printf("Deseja alterar a Menção?\n S ou N\nResposta:"); 
    scanf(" %c", &y);getchar(); 
    if(y == 'S'){
        printf("Nota:");
        validar= cap_texto(ponteiro_sec->nota);
        validar = verificar(validar);
        ponteiro_sec->nota = validar; 
    }
    }


void Excluir(Lista* lista, Node* node){
	int i = -1,r;
	char *b;
	Node * ponteiro = lista->cabeca;

    if(ponteiro == NULL){
        printf("\n\n-------------- Não existem alunos para serem excluidos ---------------\n\n");
        return; 
    }

    printf("Digite a opçao que deseja ultilizar:\n  1-Exclusão por nome\n  2-Exclusão por posição\n  Resposta:");
    scanf(" %d", &r);

    if(r == 1){
    	printf("\n Digite o nome do aluno que deseja Excluir:"); getchar();
    	b = cap_texto(b);
    	i = Buscar(lista,b,ponteiro,i);
    }
    if(r == 2){
    	printf("Digite a posição do aluno que deseja Excluir:");
    	scanf(" %d", &i);
    }
    if(r != 1 && r != 2){
    	system("clear");
    	Excluir(lista,node);
    }

    if(i == 0){
    	Node * ponteiro = lista->cabeca;
    	for(int cont=0;cont<ponteiro->diciplina;cont++){
     	Node_sec* aux = ponteiro->materias->cabeca;
	    ponteiro->materias->cabeca = aux->next;
	    free(aux);	
     	aux = aux->next;
     	}
     	ponteiro->diciplina = 0;
	    lista->cabeca = ponteiro->next;
	    free(ponteiro);
	    lista->tamanho--;
	    return; 
	    }

    else{

     	ponteiro = at_pos(lista, i);

     	 if(ponteiro == NULL){
       	printf("\n---------------Sem Correspondência---------------\n");
        return;}

     	for(int cont=0;cont<ponteiro->diciplina;cont++){
     	Node_sec* aux = ponteiro->materias->cabeca;
	    ponteiro->materias->cabeca = aux->next;
	    free(aux);	
     	aux = aux->next;
     }
     	Node* node_anterior = at_pos(lista, (i-1));
     	ponteiro->diciplina = 0;
     	node_anterior->next = ponteiro->next;
     	free(ponteiro);
     	lista->tamanho--;
     	return;
}
}
void Excluir_sec(Node* node, Lista_sec* lista_sec){
	int i = -1,r;
	char *b;
	Node_sec * ponteiro_sec = lista_sec->cabeca;

    if(ponteiro_sec == NULL){
        printf("\n\n-------------- Não existem maérias para serem excluidas --------------\n\n");
        return; 
    }

    printf("Digite a opçao que deseja ultilizar:\n  1-Exclusão por Matéria\n  2-Exclusão por posição\n  Resposta:");
    scanf(" %d", &r);

    if(r == 1){
    	printf("\n Digite o nome da matéria que deseja Excluir:"); getchar();
    	b = cap_texto(b);
    	i = Buscar_sec(lista_sec,b,ponteiro_sec,i);
    }
    if(r == 2){
    	printf("Digite a posição da matéria que deseja Excluir:");
    	scanf(" %d", &i);
    }
    if(r != 1 && r != 2){
    	system("clear");
    	Excluir_sec(node,lista_sec);
    }

    if(i == 0){
    	Node_sec * ponteiro_sec = lista_sec->cabeca;
	    lista_sec->cabeca = ponteiro_sec->next;
	    free(ponteiro_sec);
	    lista_sec->tamanho--;
	    node->diciplina--;
	    return; 
	    }

    else{

     	ponteiro_sec = at_pos_sec(lista_sec, i);

     	if(ponteiro_sec == NULL){
       	printf("\n---------------Sem Correspondência---------------\n");
        return;}

     	Node_sec* node_anterior = at_pos_sec(lista_sec, (i-1));
     	node_anterior->next = ponteiro_sec->next;
     	free(ponteiro_sec);
     	lista_sec->tamanho--;
     	node->diciplina--;
     	return;
}


}

void Sair(Lista* lista, Node* node){
	for(int i = 0;i<lista->tamanho;i++){
		Node * ponteiro = lista->cabeca;
    	for(int cont=0;cont<ponteiro->diciplina;cont++){
     	Node_sec* aux = ponteiro->materias->cabeca;
	    ponteiro->materias->cabeca = aux->next;
	    free(aux);	
     	aux = aux->next;
     	}
     	ponteiro->diciplina = 0;
	    lista->cabeca = ponteiro->next;
	    free(ponteiro);
	}
	lista->tamanho = 0;
}

void filtrar(Lista_sec* lista_sec){
    int i=0;
    char *validar = NULL;
    Node_sec* ponteiro_sec = lista_sec->cabeca;

    if(ponteiro_sec == NULL){
        printf("\n\n-------------- Não existem matérias para serem filtradas -------------\n\n");
        return; 
    }
    printf("\n Digite a menção que deseja filtrar :"); getchar();
        validar= cap_texto(validar);
        validar = verificar(validar);

     for(int cont=0;cont < lista_sec->tamanho;cont++){

        if(strcmp(ponteiro_sec->nota,validar) == 0){
        printf("-----------------------------------\n");
        printf("Materia:%s\n",ponteiro_sec->materia);
        printf("Nota:%s\n",ponteiro_sec->nota);
        printf("-----------------------------------\n");
        i++;
        }

        ponteiro_sec = ponteiro_sec->next;
    }
    if(i == 0){
        printf("\n\n-----Nenhuma matéria encontrada com essa menção-----\n\n");
        return; 
    }
}

void relatorio(Lista_sec* lista_sec){
    int A = 0, R = 0, T = 0;
    Node_sec* ponteiro_sec = lista_sec->cabeca;


    for(int cont=0;cont < lista_sec->tamanho;cont++){

        if (strcmp(ponteiro_sec->nota,"MM")== 0){
            A++; }
        if (strcmp(ponteiro_sec->nota,"MS")== 0){
            A++; }
        if (strcmp(ponteiro_sec->nota,"SS")== 0){
            A++; }
        if (strcmp(ponteiro_sec->nota,"MI")== 0){
            R++; }
        if (strcmp(ponteiro_sec->nota,"II")== 0){
            R++; }
        if (strcmp(ponteiro_sec->nota,"SR")== 0){
            R++; }
        if (strcmp(ponteiro_sec->nota,"TR")== 0){
            T++; }

        ponteiro_sec = ponteiro_sec->next;
    }
    printf("-----------------------------------\n");
    printf("Disciplinas cursadas:%d\n",lista_sec->tamanho);
    printf("Aprovações:%d\n", A );
    printf("Reprovações:%d\n", R );
    printf("Trancamentos:%d\n", T );
    printf("-----------------------------------\n");
}

void Menu_visualizar_aluno(Lista* lista, Node* node){
    int op = 1;
    int i = -1;
    char *b;
    Node* ponteiro = lista->cabeca;

    if(ponteiro == NULL){
        printf("\n\n------------- Não existem alunos para serem visualizados -------------\n\n");
        return; 
    }

    printf("\nDigite o nome ou email do aluno que deseja visualizar: "); getchar();
    b = cap_texto(b);
   	i = Buscar(lista,b,ponteiro,i);
    if(i == -1){
        printf("\n---------------Sem Correspondência---------------\n");
        return; 
    }
    ponteiro = at_pos(lista, i);

    

    while(op){
    printf("\nMenu de visualizaçao:\n\n\
        1. Cadastrar disciplina\n\
        2. Listar disciplinas do aluno\n\
        3. Editar disciplina do aluno\n\
        4. Excluir disciplina do aluno\n\
        5. Filtrar disciplinas por menção\n\
        6. Apresentar relatório geral do aluno\n\
        7. Voltar para o menu principal\n\n\
        Por favor,Digite o número da opção que dejesa selecionar: ");

    scanf(" %d", &op);  

        switch (op){

        case 1:
        Cadastrar_disciplina(ponteiro, ponteiro->materias);
        system("clear");
        break; 
            
        case 2:
        system("clear");
        imprimirlista_sec(ponteiro->materias);
        break; 
           
        case 3:
        system("clear");
        Editar_sec(ponteiro->materias);
        break; 
         
        case 4:
        system("clear");
        Excluir_sec(ponteiro, ponteiro->materias);
        break; 
           
        case 5:
        system("clear");
        filtrar(ponteiro->materias);
        break; 

        case 6:
        system("clear");
        relatorio(ponteiro->materias);
        break; 

        case 7:
        op = 0;
        system("clear");
        break;

        default:
            system("clear");
            printf("\n\n\n---------------Por favor digite uma opção válida---------------\n\n\n");
            
            }
        }
    }

void Menu_inicial(Lista* lista, Node* node){
	while(true){
	int op;
	printf("\nMenu inicial:\n\n\
        1. Cadastrar aluno\n\
        2. Listar aluno\n\
        3. Visualizar aluno\n\
        4. Editar aluno\n\
        5. Excluir aluno\n\
        6. Sair do programa\n\n\
        Por favor,Digite o numero da opcao que dejesa selecionar: ");

    scanf(" %d", &op);	

    	switch (op){

		case 1:
        Cadastrar(lista,node);
        system("clear");
        break; 
            
		case 2:
        system("clear");
        imprimirlista(lista);
        break; 

		case 3:
        system("clear");
        Menu_visualizar_aluno(lista,node);
        break; 
         
		case 4:
        system("clear");
        Editar(lista);
        break; 
           
        case 5:
        system("clear");
        Excluir(lista,node);
        break; 

        case 6:
        system("clear");
        exit(0);
            
        default:
            system("clear");
            printf("\n\n\n---------------Por favor digite uma opção valida---------------\n\n\n");
            
    		}
    	}
	}

