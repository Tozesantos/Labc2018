#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdbool.h>
int read_line(FILE *in, char *buffer, size_t max){
  return fgets(buffer, max, in) == buffer;
}
/*void CriarTopico(){
  int idpost=0;
  FILE* post;
  post = fopen("post.txt", "a+");
  fprintf(post, "/***************************************");
/*

}


void menu_adm(){
   int	cmadm;
   printf("***Menu***\n");
   printf("1) Criar Novo Tópicos\n");
   printf("2) Gerir Tópicos/Utilizadores\n");
   printf("3) Ver Estatisticas\n");
   printf("4) Logout\n"); 
   scanf("%d",cmadm);
   do {
        if (cmadm == 1){
        CriarTopico();
        }
        if (cmadm == 2){

        }
        if (cmadm == 3){

        }
        if (cmadm == 4){
          exit(0);
      	}
    }while(cmadm<1 || cmadm>4)
*/

void gestaocliente(){
  FILE* fp;
  int v;
  char ch, utilizador[12], *utl,*pass,*estado,*nome,*cont, line[200];
  fp = fopen("teste.txt", "a+");
  if( fp != NULL){
  	printf("Lista de clientes:\n");
  while( (ch=fgetc(fp))!= EOF ){ // Escreve na tela todo o conteudo do ficheiro
		putchar(ch);}
  fp = fopen("teste.txt", "a+");
  printf("\n");
  printf("Digite o Nome do utilizador\n");
  scanf("%s",utilizador);
  while (read_line(fp, line, sizeof line) && line!=NULL){
    utl=strtok(line, ":");
    pass=strtok(NULL,":");
    estado=strtok(NULL,":");
    nome=strtok(NULL,":");
    cont=strtok(NULL,":");
    v = strcmp(utilizador, utl);
    if (v==0){ 
    	printf("Utilizador: %s\n", utl);
    	printf("Password: %s\n", pass);
    	printf("Estado de cliente: %s   (0=Ativo 1=Desativo)\n", estado);
    	printf("Nome Completo: %s\n", nome);
    	printf("Contacto: %s\n", cont);
    }

  }
  }
  else 
    printf("Erro De abertura.\n");  
}
void gestaoadm(){
	int q;
	char utilizador[20], password[20], *utladm,*passadm, line[200];
	FILE* fa;
    fa = fopen("Administrador.txt", "r+");
    utladm= strtok(line,":");
    passadm= strtok(line,":");
    printf(" %s     %s  \n",  utladm, passadm);
	/*while(q<1 || q>2) {
		printf("1) Área restrita ao administrador principal\n");
		printf("2) Menu principal.\n");
		scanf("%q", &q);
		if (q==1){
			printf("Utilizador: ");
			scanf("%s", utilizador);
			printf("Senha: ");
			scanf("%s", password);


		}
    }*/


}












int main(){
	gestaoadm();
}
