#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void menu_admin ();
void login();
int main(){
  int comando;
  system("clear");
  menu_admin();
  scanf("%d",&comando);
    while(comando!=2){
      if (comando =1){
	system("clear");
	login();
      }
      menu_admin();
      scanf("%d",&comando);
    }
  return 0;
}

void menu_admin (){
  printf("*****Administrador*****\n");
  printf(" Menu de Registo:\n");
  printf("1) Login / Autenticação\n");
  printf("2)Sair\n");}

void login(){
  char utiliza[3], pass[4];
  printf("Username:\n");
  scanf("%c\n"  , &utiliza);
  printf("Password:\n");
  scanf("%c\n", &pass);
  if (utiliza !="adm\n" && pass !="1234\n"){
    system("clear");
    printf("Erro\n");
    login();
  }else {}
}
