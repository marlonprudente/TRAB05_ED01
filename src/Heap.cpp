#include <iostream>
#include "../include/Heap.h"
#include <queue>
using namespace std;
int Heap::PAI(int i)
{
    if(i!=0)
        return (int)(i-1)/2;
    else
        return 0;
}
void Heap::criarvetor()
{
    int valor, i = 0;
    queue<int> lista;
    cout << "Digite valores maior que 0 ou -1 para encerrar." << endl;
    cin >> valor;
    while(valor>=0)
    {
        lista.push(valor);
        //vetor[i] = valor;
        //i++;
        cin >> valor;
    }
    vetor = new int(lista.size());
    tamv = lista.size();
    cout << "Vetor criado, com tamanho: " << lista.size() << endl;
    while(!lista.empty())
    {
        vetor[i] = lista.front();
        lista.pop();
        i++;
    }
    tamh = 3*tamv;
    for(i=0;i<tamv;i++)
    {
        cout << "Vetor " << i << " <=" << vetor[i] << endl;
    }
}

void Heap::inserirnaheap()
{
    if(isHeap==1)
    {
        if(nro_elem!=tamh)
    {
        int valor;
        cout<<"Digite o valor: " << endl;
        cin>>valor;
        nro_elem++;
        heap[nro_elem] = valor;
        subir(nro_elem);

        cout << "Valor inserido com sucesso!"<<endl;
    }
    else
    {
        cout << "Heap Cheia!" << endl;
    }
    }
    else
    {
        cout << "Heap não criada!" << endl;
    }


}
void Heap::buscarnaheap()
{
    if(isHeap==1)
    {
        int valor, i;
    cout << "Digite o valor a ser procurado: ";
    cin >> valor;
    for(i=0; i<tamh; i++)
    {
        if(heap[i]==valor)
        {
            cout << "Encontrado o valor "<<valor<<" no Heap! Estava no indice "<<i<<endl;
            break;
        }
    }
    if(i==tamh)
        cout << "Valor não encontrado na Heap!"<<endl;
    }
    else
    {
        cout << "Heap não criada!" << endl;
    }

}
void Heap::removerdaheap()
{
    if(isHeap==1)
    {
         if(nro_elem <= 0)
    {
        std::cout<<"A Heap já está vazia!"<<std::endl;
        return;
    }

   // int aux;

    if(nro_elem>1)
    {
        //int aux = heap[0];
        heap[0] = heap[nro_elem-1];
        heap[nro_elem-1]=-1;
        nro_elem--;
        descer(0,nro_elem);   //TÁ BUGADO!
        std::cout << "Valor removido com sucesso!"<<std::endl;
    }
    else
    {
        heap[0]=-1;
        nro_elem--;
        std::cout << "Heap esvaziada!"<<std::endl;
    }
    }
    else
    {
        cout << "Heap não criada!" << endl;
    }

}

void Heap::criarheap()
{
    int i;
    heap = new int(tamh);
    for(i=0; i<tamh; i++)
    {
        heap[i] = -1;
    }
    if(tamv>0)
    {
        for(i= tamv/2; i>=0; i--)
        {
            heapify(i);
        }
        isHeap = 1;
        cout << "Heap Criada!" << endl;
    }
    else
    {
        cout << "Vetor vazio!"  << endl;
    }
    for(i=0; i<tamv; i++)
    {
        heap[i] = vetor[i];
        nro_elem++;
    }
    for(i=0;i<tamh;i++)
    {

        cout << "Heap " << i << " <=" << heap[i] << endl;

    }
}

void Heap::subir(int index) //Bug detectado.
{
    if((index>1) && (heap[PAI(index)] < heap[index]))
    {
        int aux = heap[PAI(index)];
        heap[PAI(index)] = heap[index];
        heap[index] = aux;
        subir(PAI(index));

    }
}

void Heap::descer(int i, int n)
{
    int filho;
    if((FILHO_DIREITO(i) < n) && (heap[FILHO_DIREITO(i)] > heap[FILHO_ESQUERDO(i)]))
        filho = FILHO_DIREITO(i);
    else
        filho = FILHO_ESQUERDO(i);
    if((filho<n) && (heap[filho] > heap[i]))
    {
        int aux;
        aux = heap[i];
        heap[i] = heap[filho];
        heap[filho] = aux;
        descer(filho, n);
    }
}

void Heap::heapify(int index)
{
    int maior;
    if(FILHO_ESQUERDO(index)<tamv && vetor[FILHO_ESQUERDO(index)]>vetor[index])
        maior=FILHO_ESQUERDO(index);
    else
        maior=index;
    if(FILHO_DIREITO(index)<tamv && vetor[FILHO_DIREITO(index)]>vetor[maior])
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
    if(isHeap==1 && nro_elem!=0 /*&& heap[0]!=-1*/)
    {
        int i = 0;

        cout << "Raiz: " << heap[i] << " ";
        if(heap[1] != 0)
            cout << "FE: " <<  heap[1] << " ";
        if(heap[2] != 0)
            cout<< "FD: " << heap[2] << endl;
        i++;

        while(i < nro_elem)
        {
            if(heap[i]!=-1)
            {
                if(heap[FILHO_ESQUERDO(i)] == -1 && heap[FILHO_DIREITO(i)] == -1)
                {

                }
                else
                {
                        cout<< "No: " << heap[i]<<" ";
                    if(heap[FILHO_ESQUERDO(i)] != 0)
                        cout<< "FE: " <<  heap[FILHO_ESQUERDO(i)]<< " ";
                    if(heap[FILHO_DIREITO(i)] != 0)
                        cout<< "FD: " << heap[FILHO_DIREITO(i)]<< endl;
                }
            }
            i++;
        }
    }
    else
    {
        cout<<"Não Existe Heap para ser Impressa!"<<endl;
    }

}
