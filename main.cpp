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
    cout << "1 - Inserir (Matriz Unidimensional) // 2 - Inserir (Heap) // 3 - Buscar (Heap) // 4 - Remover (Heap) // 5 - Heapify // 6 - Imprimir Heap // 0 - Sair" << endl;
	cin >> op;
    while(op!=0)
    {
        switch (op)
        {
        case 1:
            heap.criarvetor();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;

        }
    }
    return 0;
}
