#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de eespaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca de string



int registro()
{
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   
   printf("Digite o CPF a ser cadastrado:");
   scanf("%s", cpf);
   
   strcpy(arquivo, cpf); //responsavel por copiar o valor da string
   
   FILE *file;
   file = fopen(arquivo, "w"); //cria o arquivo
   fprintf(file, cpf); //salva valor da variavel
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado:");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado:");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo (nao foi localizado)\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("essas sao as informacoes do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao existe. \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variavel
	int x=1;
	
	for(x=1;x=1;)
    {
	
    system("cls");  
	
	  
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	

	printf("### Cartório da EBAC ###\n\n"); //printf é o codigo que indica texto ao computador
        printf("> escolha a opção desejada do menu:\n\n");
	      printf("\t1 - Registrar nomes;\n\n");
	      printf("\t2 - Consultar nome;\n\n"); //lembrar de dar espaçamento nos códigos
	      printf("\t3 - Deletar nomes.\n\n"); //fim do menu
	      printf("Digite o numero:");
	      
	      scanf("%d", &opcao); //scanf pausa o programa para tomar uma decisão e escolha do usuario
	      
	        system("cls");
	        
	    switch(opcao)
	    {
	    	case 1:
	       	registro();
	       	break;
	       	
	       case 2:
	       	consulta();
		   break;
		   
		   case 3:
		   	deletar();
			break;
		
		   default:
		   	printf("Essa opcao nao existe\n"); //fim da selecao
		 	system("pause");
		 	break;
		}
    }
}

