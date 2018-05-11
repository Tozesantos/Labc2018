#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<fcntl.h>
#include"menu_cliente.c" 

void menu_pr();
void login();
void criarcliente();
void abertura();

void login(){
 FILE* fp;
 fp = fopen("teste.txt", "r+");
 int v,n,u,p;
 char line[200], *token ,*tokenpass, *toke, utilizador[12], password[12],*z="0";
 system("clear");
 printf("Utilizador: ");
 scanf("%s", utilizador);
 printf("Senha: ");
 scanf("%s", password);
 
 while (read_line(fp, line, sizeof line)&& line!=NULL){
      toke = strtok(line, ":");
      tokenpass = strtok(NULL, ":");
      token = strtok(NULL, ":");
      v = strcmp(utilizador,toke);
      n = strcmp(password,tokenpass);
      u = strcmp(token,z);
      if (v==0 && n==0 && u==0){
        fclose(fp);
        system("clear");
        menu_pr();
      }
      if (v==0 && n==0 && u!=0){
        printf("Por favor contacte um Administrador para lhe dar acesso!\n");
        printf("****************************\n");
        printf("1)Menu de Abertura\n");
        scanf("%d",&p);
        if(p==1){
        abertura();}
        else
          exit (0);
      }
    }
      if (v!=0 || n!=0){
        printf("Dados incorretos! Volte a tentar!\n");
        login(); }
}  
void menu_pr(){
    int cm;
    while(cm<1 || cm>8) {
    printf("****Menu****\n");
    printf("1) Ver feed\n");
    printf("2) Ver tópicos\n");
    printf("3) Procurar tópicos mais ativos\n");
    printf("4) Subscrever tópicos\n");
    printf("5) Publicar num tópico\n");
    printf("6) Gerir lista de subscrições\n");
    printf("7) Ver estatísticas\n");
    printf("8)Logout\n");
    scanf("%d", &cm);
        if (cm == 1){
        
        }
        if (cm == 2){

        }
        if (cm == 3){

        }
        if (cm == 4){

        }
        if (cm == 5){

        }
        if (cm == 6){

        }
        if (cm == 7){

        }
        if (cm==8){
         abertura();
      }
    }
  }

void abertura(){
    int comando;
  system("clear");
  while(comando < 1 || comando > 3){
    printf("*****Cliente*****\n");
    printf(" Menu de Registo:\n");
    printf("1) Login / Autenticação\n");
    printf("2) Pedido de registo de novo utilizador\n");
    printf("3)Sair\n");
    scanf("%d",&comando);
    if (comando == 1 ){
      system("clear");
      login();
    }
    if (comando == 2){
      system("clear");
      criarcliente();
      login();
    }
    if (comando == 3){
      exit(0);
      }
  }
}
int main(){
  abertura();

}
