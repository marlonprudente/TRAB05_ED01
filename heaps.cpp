#include <iostream>

#define MAX_DEPTH 100

#define FILHO_ESQUERDO(i) (2*i)+1
#define FILHO_DIREITO(i) (2*i)+2

void descer(int i, int* heap, int size);
void subir(int i, int* heap);
void inserirMaxHeap();
void inserirMaxHeap(int valor);
void removerMaxHeap();
void imprimirMaxHeap();
void vetor_heapify(int* vetor, int*destino);
void build_heap();
void heapify(int index_i);

int PAI(int i){
    if(i!=0)
        return (int)(i-1)/2;
    else
        return 0;
}

int* maxHeap;
int* vetor;

int maxHeapSize;
int maxVetorSize;

void build_heap(){
    int i;

    for (i = (maxVetorSize/2); i>=0 ; i--)
    {
        heapify(i);
    }
}
void heapify(int index_i){
    std::cout<<"INDEX:"<<index_i<<"- VALOR:"<<vetor[index_i];
    int maior;
    if(FILHO_ESQUERDO(index_i)<maxVetorSize && vetor[FILHO_ESQUERDO(index_i)]>vetor[index_i])
        maior=FILHO_ESQUERDO(index_i);
    else
        maior=index_i;
    if(FILHO_DIREITO(index_i)<maxVetorSize && vetor[FILHO_DIREITO(index_i)]>vetor[maior])
        maior=FILHO_DIREITO(index_i);
    if(maior!=index_i)
    {
        std::cout<<"Troquei o "<<index_i<<" com o "<<maior<<"que eram "<<vetor[index_i]<<" e "<<vetor[maior]<<std::endl;
        int aux=vetor[index_i];
        vetor[index_i]=vetor[maior];
        vetor[maior]=aux;
        heapify(maior);
    }
}
void vetor_heapify(int* vetor, int*destino){
    int entrada=1;
    int i=0;
    while(entrada>=0)
    {
        std::cout << "Digite valores positivos para colocar no vetor, um valor negativo encerrará a sequência:";
        std::cin >> entrada;
        if(entrada>=0 && i<MAX_DEPTH)
        {
            vetor[i]=entrada;
            i++;
        }
    }
    maxVetorSize=i;
    std::cout<<"Seu vetor é: ";
    for(int j=0;j<i;j++)
        std::cout<<vetor[j]<<"  ";

    build_heap();

    for(int k=0;k<MAX_DEPTH;k++)
    {
        maxHeap[k]=-1;
    }
    maxHeapSize=0;
    for(int j=0;j<i;j++)
    {
        maxHeap[j]=vetor[j];
        maxHeapSize++;
    }
    std::cout<<std::endl<<"APOS O HEAPIFY: "<<std::endl;
    imprimirMaxHeap();

}
void inserirMaxHeap(int valor){

	maxHeap[maxHeapSize] = valor;

	subir(maxHeapSize, maxHeap);

	maxHeapSize++;
}
void inserirMaxHeap(){
	if(maxHeapSize >= MAX_DEPTH)
	{
		std::cout<<"A árvore está cheia!"<<std::endl;
		return;
	}

	int valor;
	std::cout<<std::endl<<"Entre o valor: ";
	std::cin>>valor;

	maxHeap[maxHeapSize] = valor;
    //imprimirMaxHeap();
	subir(maxHeapSize, maxHeap);

	maxHeapSize++;
	std::cout << "Valor inserido com sucesso!"<<std::endl;
}
void removerMaxHeap(){
	if(maxHeapSize <= 0)
	{
		std::cout<<"A Heap já está vazia!"<<std::endl;
		return;
	}

	int aux = 0;

    if(maxHeapSize>1)
    {
        aux = maxHeap[0];
        maxHeap[0] = maxHeap[maxHeapSize-1];
        maxHeap[maxHeapSize-1]=-1;
        maxHeapSize--;

        descer(0,maxHeap,maxHeapSize);   //TÁ BUGADO!
        std::cout << "Valor removido com sucesso!"<<std::endl;
    }
    else
    {
        maxHeap[0]=-1;
        maxHeapSize--;
        std::cout << "Heap esvaziada!"<<std::endl;
    }


}

/*void inserirMinHeap()
{
	if(minHeapSize >= MAX_DEPTH)
	{
		std::cout<<"arvore cheia"<<std::endl;
		return;
	}

	int valor;
	std::cin>>valor;

	maxHeap[maxHeapSize] = valor;

	subir(maxHeapSize, maxHeap);
}*/

void buscar(int valor, int* heap){
    int index;
    for(index=0;index<maxHeapSize;index++)
    {
        if(maxHeap[index]==valor)
        {
            std::cout << "Encontrado o valor "<<valor<<" no Heap! Estava no index "<<index<<std::endl;
            break;
        }
    }
    if(index==maxHeapSize)
        std::cout << "Valor não encontrado na Heap!"<<std::endl;
}
void subir(int index, int* heap){
	if((index>0) && (heap[PAI(index)] < heap[index]))
	{
		int aux = heap[PAI(index)];
		heap[PAI(index)] = heap[index];
		heap[index] = aux;
		subir(PAI(index), heap);
		//std::cout<<"Troquei o "<<heap[index]<<" com o "<<heap[PAI(index)]<<" que estavam nos indices "<<index<<" e "<<PAI(index)<<std::endl;
	}
}
void descer(int i, int* heap, int size){
	int filho;
	if((FILHO_DIREITO(i) < size) && (heap[FILHO_DIREITO(i)] > heap[FILHO_ESQUERDO(i)]))
		filho = FILHO_DIREITO(i);
	else
		filho = FILHO_ESQUERDO(i);
	if((filho<size) && (heap[filho] > heap[i]))
	{
		int aux;
		aux = heap[i];
		heap[i] = heap[filho];
		heap[filho] = aux;
		descer(filho, heap, size);
	}

}
void imprimirMaxHeap(){
    if(maxHeapSize>0)
    {
        int indice = 0;

        //imprimir raiz antes.. excessão
        std::cout << "Raiz: " << maxHeap[indice] << std::endl;
        if(maxHeap[FILHO_ESQUERDO(indice)] != 0)
            std::cout << "FE: " <<  maxHeap[1] << std::endl;
        if(maxHeap[FILHO_DIREITO(indice)] != 0)
            std::cout<< "FD: " << maxHeap[2] << std::endl;

        indice++;

        while(indice < maxHeapSize)
        {
            std::cout<< "No: " << maxHeap[indice]<<std::endl;

            if(maxHeap[FILHO_ESQUERDO(indice)] != 0)
                std::cout<< "FE: " <<  maxHeap[FILHO_ESQUERDO(indice)]<< std::endl;
            if(maxHeap[FILHO_DIREITO(indice)] != 0)
                std::cout<< "FD: " << maxHeap[FILHO_DIREITO(indice)]<< std::endl;
         indice++;
        }
    }
    else
    {
        std::cout<<"MaxHeap vazia!"<<std::endl;
    }

}
int menu(){

	int op = 0;


    std::cout << "*****************************************************************************************" << std::endl;
    std::cout << "****                       MENU - POR FAVOR ESCOLHA UMA OPCAO                       *****" << std::endl;
    std::cout << "****                                                                                *****" << std::endl;
    std::cout << "**** 1 - Inserir valor no Heap de máximo                                            *****" << std::endl;
    std::cout << "**** 2 - Remover valor do Heap de máximo                                            *****" << std::endl;
    std::cout << "**** 3 - Buscar valor                                                               *****" << std::endl;
    std::cout << "**** 4 - Criar Vetor e fazer Heapify                                                *****" << std::endl;
    std::cout << "**** 5 - Imprimir Heap de máximo                                                    *****" << std::endl;
    std::cout << "**** 6 - SAIR                                                                       *****" << std::endl;
    std::cout << "*****************************************************************************************" << std::endl;
    std::cout << "OPÇÃO: ";

	std::cin>>op;
	return op;
}
int main(){
	int op;
	maxHeapSize = 0;


	maxHeap = new int[MAX_DEPTH];
	vetor = new int[MAX_DEPTH];

    for(int i=0;i<MAX_DEPTH;i++)
    {
        maxHeap[i]=-1;
    }

	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				inserirMaxHeap();
				break;
			case 2:
				removerMaxHeap();
				break;
			case 3:
			    std::cout<<"Digite o valor procurado: ";
			    int entrada;
			    std::cin>>entrada;
				buscar(entrada, maxHeap);
				break;

			case 4:
				vetor_heapify(vetor,maxHeap);
				break;
			case 5:
				imprimirMaxHeap();
				break;
		}
	}while(op<6);

	return 0;
}
