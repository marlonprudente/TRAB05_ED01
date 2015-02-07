#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

class Heap
{
private:
    int *vetor;
public:
    Heap()
    {
    }
    ~Heap() {}

    void descer(int i, int* heap, int size);
    void subir(int i, int* heap);
    void inserirMaxHeap();
    void inserirMaxHeap(int valor);
    void removerMaxHeap();
    void imprimirMaxHeap();
    void criarvetor();
    void vetor_heapify(int* vetor, int*destino);
    void build_heap();
    void heapify(int index_i);
};

#endif // HEAP_H_INCLUDED
