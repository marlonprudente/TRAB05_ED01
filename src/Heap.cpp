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
        cout << "Tamanho da lista: " << lista.size() << endl;
    while(!lista.empty())
    {
        vetor[i] = lista.front();
        //cout << "Vetor[" << i << "] :" << vetor[i] << endl;
        lista.pop();
        i++;
    }
}
