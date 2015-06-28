#define INCREMENTO 10


typedef struct{
	
	int reservedSize;//Tamaño reservado
	int size; //tamaño lista
	void** pElements; //puntero a los elemntos de la lista
	
	void(*add)();
	
	void(*remov)();
	
	void(*set)();
	
	void* (*get)();
	
	void (*push)();
	
	void*(*pop)();
	
	int(*indexOf)();
	
	int(*sizes)();
	
	int(*contains)();
	
	int(*containsAll)();
	
	int(*isEmpty)();
	
	struct ArrayList*(*clone)();
	
	struct ArrayList*(*sublist)();
	
	void(*clear)();
	
}ArrayList;



ArrayList* newArrayList();

void add(ArrayList*, void*);

void reSizeUp(ArrayList*);

void mostrar(ArrayList*);

void remov(ArrayList*, int);

void clear(ArrayList*);

void set(ArrayList*, int, void*);

void* get(ArrayList*, int);

void push(ArrayList*, int, void*);

void* pop(ArrayList*, int);

int indexOf(ArrayList*, void*);

int sizes(ArrayList*);

int contains(ArrayList*, void*);

int containsAll(ArrayList*, ArrayList*);

int isEmpty(ArrayList*);

ArrayList* clone(ArrayList*);

ArrayList* subList(ArrayList*, int, int);


//Funciones a parte
void decrecimientoLista(ArrayList*);

void incrementoLista(ArrayList*);



