#include <iostream>
#include "../include/Heap.h"
#include <queue>
using namespace std;

void Heap::criarvetor()
{
    int valor, i = 0;
    queue<int> lista;
    cout << "Digite valores maior que 0 ou -1 para encerrar.";
    cin >> valor;
    while(valor>=0)
    {
        lista.push(valor);
        cin >> valor;
    }
    vetor = new int(lista.size());
    tam = lista.size();
    cout << "Tamanho da lista: " << lista.size() << endl;
    while(!lista.empty())
    {
        vetor[i] = lista.front();
        lista.pop();
        i++;
    }
}

void Heap::criarheap()
{
    int i;
    heap = new int(2*tam+1);
    for(i=0;i<(2*tam+1);i++)
    {
        heap[i] = -1;
    }
    if(tam>0)
    {
        for(i= tam/2 - 1; i>=0; i--)
        {
            descer(i, tam-1);
        }
        isHeap = 1;
    }
    else
    {
       cout << "Vetor vazio!"  << endl;
    }
    for(i=0;i<tam;i++)
    {
    heap[i] = vetor[i];
    }

}
void Heap::descer(int i, int n)
{
	int filho;
	if((FILHO_DIREITO(i) < n) && (vetor[FILHO_DIREITO(i)] > vetor[FILHO_ESQUERDO(i)]))
		filho = FILHO_DIREITO(i);
	else
		filho = FILHO_ESQUERDO(i);
	if((filho<n) && (vetor[filho] > vetor[i]))
	{
		int aux;
		aux = vetor[i];
		vetor[i] = vetor[filho];
		vetor[filho] = aux;
		descer(filho, n);
	}

}
void Heap::heapify(int i){
    int maior;
    cout<<"INDEX:"<<i<<"VALOR:"<<vetor[i] << endl;
    if(FILHO_ESQUERDO(i)<tam && vetor[FILHO_ESQUERDO(i)]>vetor[tam])
    {
        maior=FILHO_ESQUERDO(i);
    }
    else
    {
        maior=tam;
    }

    if(FILHO_DIREITO(i)<tam && vetor[FILHO_DIREITO(i)]>vetor[maior])
        maior=FILHO_DIREITO(i);
    if(maior!=i)
    {
        cout<<"Troquei o "<<i<<" com o "<<maior<<"que eram "<<vetor[i]<<" e "<<vetor[maior]<<std::endl;
        int aux=vetor[i];
        vetor[i]=vetor[maior];
        vetor[maior]=aux;
        heapify(maior);
    }
}

void Heap::imprimirheap(){
    if(isHeap==1 && tam!=0)
    {
        int i = 0;
        cout << "Raiz: " << heap[i] << " - ";
        if(heap[FILHO_ESQUERDO(i)] != 0)
        cout << "FE: " <<  heap[1] << " - ";
        if(heap[FILHO_DIREITO(i)] != 0)
        cout<< "FD: " << heap[2] << endl;

        i++;

        while(i < tam)
        {
            cout<< "No: " << heap[i]<<" - ";

            if(heap[FILHO_ESQUERDO(i)] != 0)
            cout<< "FE: " <<  vetor[FILHO_ESQUERDO(i)]<< " - ";
            if(heap[FILHO_DIREITO(i)] != 0)
            cout<< "FD: " << heap[FILHO_DIREITO(i)]<< endl;
         i++;
        }
    }
    else
    {
        cout<<"Não Existe Heap para ser Impressa!"<<endl;
    }

}
