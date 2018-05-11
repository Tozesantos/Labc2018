#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"menu_cliente.c" 
void loginadm();
void menuadm();
void menuadminicial();
void utilizadores();
void criaradm();
//void gestaoadm();
void gestaocliente();



void menuadm(){
   int  cmadm;
    while(cmadm<1 || cmadm>4){
   printf("***Menu***\n");
   printf("1) Criação e gestão de tópicos\n");
   printf("2) Criação e gestão de utilizadores\n");
   printf("3) Ver Estatisticas\n");
   printf("4) Logout\n");
     scanf("%d", &cmadm);
     if (cmadm == 1){
        }
     if (cmadm == 2){
      utilizadores();
        }
     if (cmadm == 3){
        }
     if (cmadm == 4){
      menuadminicial();
    }
    }
}


void loginadm(){
 FILE* fa;
 fa = fopen("Administrador.txt", "r+");
 int v=1,n=1;
 char line[200], *token ,*tokenpass, *toke, utilizador[12], password[12];
 //system("clear");
 printf("Utilizador: ");
 scanf("%s", utilizador);
 printf("Senha: ");
 scanf("%s", password);
 while (read_line(fa, line, sizeof line)&& line!=NULL){
      toke =strtok(line, ":");
      tokenpass =strtok(NULL, ":");
      v = strcmp(utilizador, toke);
      n = strcmp(password, tokenpass);
      if (v==0 && n==0){
        fclose(fa);
        //system("clear");
        menuadm();
      }
  }
  if (v!=0 || n!=0)
  {
      printf("Dados incorretos! Volte a tentar!\n");
      loginadm(); 
  }
  
}  

void menuadminicial(){
  int comando=0;
 // system("clear");
  while(comando < 1 || comando > 2){
    printf("*****Administrador*****\n");
    printf(" Menu de Registo:\n");
    printf("1) Login / Autenticação\n");
    printf("2)Sair\n");
    scanf("%d",&comando);
    if (comando == 1 ){
  //  system("clear");
      loginadm();
      } 
    if (comando == 2){
      exit(0);
      }
    }
      
}

void utilizadores(){
  int q=1,w=1,p=1;
 // system("clear");
  while(q==1 || q==2){
  printf("*************************\n");
  printf("1)Criação de utilizadores\n");
  printf("2)Gestão de utilizadores\n");
  scanf("%d",&q);
    if (q==1){
      while(w==1 || w==2){
     //system("clear");
      printf("**************************\n");
      printf("1)Criação de cliente\n");
      printf("2)Criação de administrador\n");
      scanf("%d", &w);
           
      if(w==1){
       // system("clear");
        criarcliente();
        menuadm();}
      if(w==2){
       // system("clear");
        criaradm();
        menuadm();}
      }
      }
      if (q==2){
        while(p==1 || p==2){
          printf("**************************\n");
          printf("1)Gestão de cliente\n");
          printf("2)Gestão de administrador\n");
          scanf("%d", &p);
          if(w==1){
        // system("clear");
            gestãocliente();
            menuadm();}
          if(w==2){
        // system("clear");
            gestãoadm();
            menuadm();}
      }
      }
  
}}

void criaradm(){

  char nome[1000], utilizador[12], password[12], contacto[10], line[200], confpassword[12], *toke;
  int v,i;
  FILE* fa;
  fa = fopen("Administrador.txt", "a+");
  if( fa != NULL){
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
    while (read_line(fa, line, sizeof line)&& line!=NULL){
      toke =strtok(line, ":");
      v = strcmp(utilizador, toke);
      if (i!=0){
        // system("clear");
        printf(" As passwords não são iguais!\n");
        criaradm();
      } 
      if (v==0){
        // system("clear");
        printf("O utilizador escolhido ja foi utilizado!\n");
        criaradm();
       }
      
      if (v!=0 && i==0){
        fprintf(fa,"%s:%s:%s:%s \n", utilizador, password, nome, contacto);
      }
    }
    fclose(fa);
    // system("clear");
    loginadm();
  }
  else 
    printf("Erro De abertura.\n");  
}

void gestaoadm(){

}
void gestaocliente(){
  FILE* fp;
  fp = fopen("teste.txt", "a+");
  while (read_line(fp, line, sizeof line)&& line!=NULL){
    printf("%s\n", line);}
}






























int main(){
  menuadminicial();
}