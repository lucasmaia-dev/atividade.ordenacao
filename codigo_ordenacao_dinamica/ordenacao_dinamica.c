
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int comparacoes = 0;
int trocas = 0;

/* ---------- Função para mostrar vetor ---------- */
void mostrar(int v[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

/* ---------- BUBBLE SORT ---------- */
void bubbleSort(int v[], int n){
    comparacoes = 0;
    trocas = 0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            comparacoes++;
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                trocas++;
            }
        }
    }
}

/* ---------- SELECTION SORT ---------- */
void selectionSort(int v[], int n){
    comparacoes = 0;
    trocas = 0;

    for(int i=0;i<n-1;i++){
        int min = i;

        for(int j=i+1;j<n;j++){
            comparacoes++;
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(min != i){
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            trocas++;
        }
    }
}

/* ---------- INSERTION SORT ---------- */
void insertionSort(int v[], int n){
    comparacoes = 0;
    trocas = 0;

    for(int i=1;i<n;i++){
        int chave = v[i];
        int j = i-1;

        while(j>=0){
            comparacoes++;
            if(v[j] > chave){
                v[j+1] = v[j];
                j--;
                trocas++;
            }else{
                break;
            }
        }
        v[j+1] = chave;
    }
}

/* ---------- QUICK SORT ---------- */

void troca(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
    trocas++;
}

int particao(int v[], int inicio, int fim){
    int pivo = v[fim];
    int i = inicio - 1;

    for(int j=inicio;j<fim;j++){
        comparacoes++;
        if(v[j] < pivo){
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i+1], &v[fim]);
    return i+1;
}

void quickSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int p = particao(v,inicio,fim);
        quickSort(v,inicio,p-1);
        quickSort(v,p+1,fim);
    }
}

/* ---------- MERGE SORT ---------- */

void merge(int v[], int inicio, int meio, int fim){
    int i=inicio, j=meio+1, k=0;
    int temp[MAX];

    while(i<=meio && j<=fim){
        comparacoes++;
        if(v[i] <= v[j]){
            temp[k++] = v[i++];
        }else{
            temp[k++] = v[j++];
            trocas++;
        }
    }

    while(i<=meio)
        temp[k++] = v[i++];

    while(j<=fim)
        temp[k++] = v[j++];

    for(i=inicio,k=0;i<=fim;i++,k++)
        v[i] = temp[k];
}

void mergeSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(){

    int vetor[MAX];
    int n = 0;
    int qtd;
    int opcao;
    int valor;

    printf("Escolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Quick Sort\n");
    printf("5 - Merge Sort\n");

    printf("Opcao: ");
    scanf("%d",&opcao);

    printf("\nQuantos valores deseja inserir? ");
    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){

        printf("\nDigite o valor: ");
        scanf("%d",&valor);

        vetor[n] = valor;
        n++;

        if(opcao==1)
            bubbleSort(vetor,n);

        else if(opcao==2)
            selectionSort(vetor,n);

        else if(opcao==3)
            insertionSort(vetor,n);

        else if(opcao==4){
            comparacoes = 0;
            trocas = 0;
            quickSort(vetor,0,n-1);
        }

        else if(opcao==5){
            comparacoes = 0;
            trocas = 0;
            mergeSort(vetor,0,n-1);
        }

        printf("Estrutura atual: ");
        mostrar(vetor,n);

        printf("Comparacoes: %d\n", comparacoes);
        printf("Trocas: %d\n", trocas);
    }

    return 0;
}
