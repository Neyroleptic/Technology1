#include "Queue.h"

class sonQueue_private : private parQueue
{
public:
	float harmonicMean();
	int pop(); 
	void push(int el); 
	void print(); 
	void merge(sonQueue_private& Q1); //слияние двух очередей
	int copy(sonQueue_private& Q, int* &buff); //копирование очереди в буффер обмена
	void insert(int* buff, int buffsize); // вставка очереди
	bool isEmpty(); //проверка на заполненность
};