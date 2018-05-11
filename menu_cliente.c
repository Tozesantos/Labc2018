#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdbool.h>

int read_line(FILE *in, char *buffer, size_t max){
  return fgets(buffer, max, in) == buffer;
}
void criarcliente(){
  char nome[1000], utilizador[12], password[12], contacto[10], confpassword[12], line[200], *toke;
  int v,i;
  FILE* fp;
  fp = fopen("teste.txt", "a+");
  if( fp != NULL){
    printf("Nome Completo: ");
    scanf(" %[^\n]", nome);
    printf("\n");
    printf("Contacto:\n");
    scanf("%s", contacto);
    printf("\n");
    printf("Utilizador:\n");
    scanf("%s", utilizador);
    printf("\n");
    printf("Palavra-passe:\n");
    scanf("%s", password);
    printf("\n");
    printf("Confirmação da palavra-passe:\n");
    scanf("%s", confpassword);
    printf("\n");
    i = strcmp(confpassword, password);
    while (read_line(fp, line, sizeof line)&& line!=NULL){
      toke =strtok(line, ":");
      v = strcmp(utilizador, toke);
      if (i!=0){
        // system("clear");
        printf(" As passwords não são iguais!\n");
        criarcliente();
      } 
      if (v==0){
        // system("clear");
        printf("O nome de utilizador ja foi ocupado!\n");
        criarcliente();
       }
      if (v!=0 && i==0){
        fprintf(fp,"%s:%s:1:%s:%s \n", utilizador, password, nome, contacto);
      }
    }
    fclose(fp);
  }
  else 
    printf("Erro De abertura.\n");  
}

                            
