#include <iostream>
#include "../include/Heap.h"
#include <queue>
using namespace std;

void Heap::criarvetor()
{
    int valor, i = 0;
    queue<int> lista;
    cout << "Digite valores maior que 0 ou -1 para encerrar." << endl;
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
    for(i=0; i<(2*tam+1); i++)
    {
        heap[i] = -1;
    }
    if(tam>0)
    {
        for(i= tam/2; i>=0; i--)
        {
            heapify(i);
        }
        isHeap = 1;
    }
    else
    {
        cout << "Vetor vazio!"  << endl;
    }
    for(i=0; i<tam; i++)
    {
        heap[i] = vetor[i];
    }



}
void Heap::descer(int i, int n)
{
    int aux;
    if(vetor[i]<vetor[FILHO_ESQUERDO(i)])
    {
        aux = vetor[i];
        vetor[i] = vetor[FILHO_ESQUERDO(i)];
        vetor[FILHO_ESQUERDO(i)] = aux;
    }
    if(vetor[i]<vetor[FILHO_DIREITO(i)])
    {
        aux = vetor[i];
        vetor[i] = vetor[FILHO_DIREITO(i)];
        vetor[FILHO_DIREITO(i)] = aux;
    }

}
void Heap::heapify(int index){
    int maior;
    if(FILHO_ESQUERDO(index)<tam && vetor[FILHO_ESQUERDO(index)]>vetor[index])
        maior=FILHO_ESQUERDO(index);
    else
        maior=index;
    if(FILHO_DIREITO(index)<tam && vetor[FILHO_DIREITO(index)]>vetor[maior])
        maior=FILHO_DIREITO(index);
    if(maior!=index)
    {
        int aux=vetor[index];
        vetor[index]=vetor[maior];
        vetor[maior]=aux;
        heapify(maior);
    }
}

void Heap::imprimirheap()
{
    if(isHeap==1 && tam!=0)
    {
        int i = 0;

        cout << "Raiz: " << heap[i] << " ";
        if(heap[1] != 0)
            cout << "FE: " <<  heap[1] << " ";
        if(heap[2] != 0)
            cout<< "FD: " << heap[2] << endl;
        i++;

        while(i < tam)
        {
            cout<< "No: " << heap[i]<<" ";
            if(heap[FILHO_ESQUERDO(i)] != 0)
            cout<< "FE: " <<  heap[FILHO_ESQUERDO(i)]<< " ";
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
