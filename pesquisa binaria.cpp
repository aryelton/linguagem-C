#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int v[],int tam);

void printaVetor(int vet[], int tam);

void popularVetor(int v[], FILE *f, int tam);

int pesquisaBinaria (int v[], int chave, int tam);

int pesquisaLinear(int v[], int chave, int tam);


int main(){

    FILE *arquivo;
    int op; 
    int *vet;
        
    do{
        printf("#------------------- MANIPULANDO OPERACOES EM ESTRUTURA DE DADOS ---------------------#\n");    
        printf("SELECIONE AS OPCOES\n");
        printf("1 - CRIAR ARQUIVO\n");
        printf("2 - OPERACOES (ORDENACAO | PESQUISA)\n");
        printf("3 - SAIR\n");
        printf("OPCAO ESCOLHIDA: ");
        scanf("%d",&op);
    
        printf("\n");
        
        switch(op){
        
            case 1: //criar arquivo com numeros 
            {
                printf("#------------(1) - CRIACAO DE ARQUIVO ------------------\n");
                
                int qtdElem;
                
                printf("QUANTIDADE DE NUMEROS GERADOS: ");
                scanf("%d",&qtdElem);
                
                
                arquivo = fopen("numeros_aleatorios.txt","w");
                
                if(arquivo != NULL)
                    printf("ERRO - arquivo nao foi criado\n");
                
                srand(time(NULL));
                
                for(int i = 0; i < qtdElem; i++)
                    fprintf(arquivo, "%d\t", rand() % 1000);
                
                fclose(arquivo);            
            
            break;
            }
            
            case 2: //operacoes (ordenacao | pesquisa)
            {
                printf("#-----------------(2) - OPERACOES -----------------#\n");
            
                int num, op2;
                int qtdNum = 0;
                
                //abrir arquivo
                arquivo = fopen("numeros_aleatorios.txt","r");
                
                if(arquivo == NULL)
                    printf("ERRO - arquivo nao foi aberto\n");
                    
                //contar a quantidade de numeros no arquivo
                while(fscanf(arquivo, "%d", &num) == 1)
                    qtdNum++;
                
                //alocar o vetor
                vet = (int*)malloc(qtdNum*sizeof(int));
                
                //popular o vetor com os numeros salvos no arquivo
                popularVetor(vet, arquivo, qtdNum);
                                             
                //submenus
                
                printf("OPCOES DE MANIPULACAO\n");
                printf("1 - ORDENACAO\n");
                printf("2 - PESQUISA LINEAR\n");
                printf("3 - PESQUISA BINARIA\n");
                printf("OPCAO ESCOLHIDA: ");
                scanf("%d",&op2);
                
                
                //validacao
                if( op2 <= 0 || op2 > 3)
                    printf("\nOPCAO DESCONHECIDA!\n");
                    
                if(op2 == 1){ //ordenar
                
                    printf("# --------------(2.1) - ORDENANDO POR BUBBLE SORT\n");
                    
                    printf("\n------- VETOR ANTES DA ORDENACAO ----------\n");
                    printaVetor(vet,qtdNum);
                    
                    //ordenar
                    bubbleSort(vet, qtdNum);
                    
                    printf("\n------- VETOR APOS A ORDENACAO ----------\n");
                    printaVetor(vet,qtdNum);
                    
                
                }
                
                if(op2 == 2){//pesquisa linear
                    printf("# --------------(2.2) - PESQUISA LINEAR\n");
                    
                    int pos;
                    int chave;
                    
                    printf("VOCE DESEJA PROCURAR O NUMERO: ");
                    scanf("%d",&chave);
                    
                    printf("\n");
                    
                    pos = pesquisaLinear(vet, chave, qtdNum);
                    
                    if(pos != -1)
                        printf("O VALOR %d FOI ENCONTRADA NA POSICAO %d DO VETOR\n", chave, pos);
                    else
                        printf("O VALOR %d NAO FOI ENCONTRADO NO VETOR\n", chave);
                
                }
                
                if(op2 == 3){//pesquisa binaria
                    printf("# --------------(2.3) - PESQUISA BINARIA\n");
                    
                    
                
                
                }
            
            
            break;
            }
            
            default:   
        
        
    
    
    }while(op != 3);

    return(0);
}

void popularVetor(int v[], FILE *f, int tam){
    
    int num;
        
    //INICIALIZAR O ARQUIVO PELO INICIO         
    fseek ( f , 0 , SEEK_SET );

    for(int i=0;i < tam; i++){              
        fscanf(f,"%d",&num);
        v[i] = num;
    }
        
}

void bubbleSort (int v[], int tam) {
    
    int k, j, aux;

    for (k = 1; k < tam; k++) {
        
        for (j = 0; j < tam - k; j++) {
           
            if (v[j] > v[j + 1]) {
                aux      = v[j];
                v[j]     = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void printaVetor(int vet[], int tam){
    
    for (int k = 0; k < tam; k++) 
        printf("%d\t ", vet[k]);        
}


int pesquisaLinear(int v[], int chave, int tam){

    for(int i=0; i< tam; i++){
        if(v[i] == chave)
            return i;
    
    }
    return -1;
}

