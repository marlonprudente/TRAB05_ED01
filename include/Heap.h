#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define FILHO_ESQUERDO(i) (2*(i + 1))
#define FILHO_DIREITO(i) (2*(i + 1))+1
class Heap
{
private:
    int *vetor, *heap, tam = 0, isHeap;
public:
    Heap()
    {
    }
    ~Heap() {}
    void criarvetor();
    void inserirnaheap();
    void buscarnaheap();
    void removerdaheap();
    void criarheap();
    void imprimirheap();
    void heapify(int i);
    void subir(int i, int n);
    void descer(int i, int n);
};

#endif // HEAP_H_INCLUDED
