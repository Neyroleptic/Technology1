#pragma once


typedef struct Unit //элемент очереди
{
	int data = 0; //значение нынешнего элемента
	Unit* prev = 0; //указатель на предыдущи элемент
} Unit;

class parQueue
{
private:
	Unit* last = 0; //указатель на конец очереди
protected:
	int size; //размер очереди

public:
	parQueue(); 
	~parQueue(); 
	Unit* get_last(); 
	int pop(); 
	void push(int el); 
	void print(); 
	void merge(parQueue& Q1); 
	int copy(parQueue& Q, int* &buff); 	
	void insert(int* buff, int buffsize); 
	bool isEmpty(); 
};