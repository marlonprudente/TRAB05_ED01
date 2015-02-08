#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define FILHO_ESQUERDO(i) (2*i)+1
#define FILHO_DIREITO(i) (2*i)+2
class Heap
{
private:
    int *vetor, *heap, tamv = 0, tamr = 30, isHeap = 0, nro_elem = 0;
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
    void subir(int i);
    void descer(int i, int n);
    int PAI(int i);
};

#endif // HEAP_H_INCLUDED
