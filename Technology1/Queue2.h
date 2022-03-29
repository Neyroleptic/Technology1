#include "Queue.h"

class sonQueue_protected : protected parQueue
{
public:
	float harmonicMean();
	int pop();
	void push(int el);
	void print();
	void merge(sonQueue_protected& Q1);
	int copy(sonQueue_protected& Q, int*& buff);
	void insert(int* buff, int buffsize);
	bool isEmpty();
};