#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "include/Heap.h"
using namespace std;

int main(int argc, char * argv[])
{
    Heap heap;
    int op, i, *vetor;
    cout <<"1 - Inserir (Matriz Unidimensional)" << endl;
    cout <<"2 - Inserir (Heap)" <<endl;
    cout <<"3 - Buscar (Heap) " <<endl;
    cout <<"4 - Remover (Heap)"<<endl;
    cout <<"5 - Criar Heap " <<endl;
    cout <<"6 - Imprimir Heap" <<endl;
    cout <<"0 - Sair" << endl;
	cin >> op;
    while(op!=0)
    {
        switch (op)
        {
        case 1:
            heap.criarvetor();
            break;
        case 2:
            heap.inserirnaheap();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            heap.criarheap();
            break;
        case 6:
            heap.imprimirheap();
            break;
        default:
            break;

        }
    cout <<"1 - Inserir (Matriz Unidimensional)" << endl;
    cout <<"2 - Inserir (Heap)" <<endl;
    cout <<"3 - Buscar (Heap) " <<endl;
    cout <<"4 - Remover (Heap)"<<endl;
    cout <<"5 - Heapify " <<endl;
    cout <<"6 - Imprimir Heap" <<endl;
    cout <<"0 - Sair" << endl;
	cin >> op;
    }
    return 0;
}
