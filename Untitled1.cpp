#include<stdio.h>
#include<stdlib.h>

//registro cadastro - alunos
struct cadastro{

    char nome[50];
    int matricula;
    int idade;
    char curso[100];

};

int main(){

    struct cadastro c;//crio uma variavel c do tipo struct cadastro
    
    printf("nome do aluno:");
    gets(c.nome);
    
    printf("\nMAtricula: ");
    scanf("%d",&c.matricula);
    
    printf("\nCurso: ");
    gets(c.curso);
    
    
    printf("\nIdade: ");
    scanf("%d",&c.idade);
    
    
    printf("\nAluno: %s", c.nome);
    printf("\nCurso: %s",c.curso);
    printf("\nMatricula: %d", c.matricula);
    printf("\nIdade: %d\n",c.idade);

    return 0; 
