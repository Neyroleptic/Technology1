#include <iostream>
#include "Queue1.h"

using namespace std;

float sonQueue_private::harmonicMean()
{
	Unit* last = get_last();
	float result = 0;
	float sum = 0;

	if (size == 0){
		cout << "Очередь пуста!" << endl;
	}
	else{
		while (last != nullptr)
		{
			sum = sum + 1.0 / (last->data);
			last = last->prev;
		}
		result =  size / sum;
	}
	return result;
}

int sonQueue_private::pop() { return parQueue::pop(); }
void sonQueue_private::push(int el) { return parQueue::push(el); }
void sonQueue_private::print() { return parQueue::print(); }
void sonQueue_private::merge(sonQueue_private& Q1) { return parQueue::merge(Q1); }
int sonQueue_private::copy(sonQueue_private& Q1, int* &buff) { return parQueue::copy(Q1, buff); }
void sonQueue_private::insert(int* buff, int buffsize) { return parQueue::insert(buff, buffsize); }
bool sonQueue_private::isEmpty() { return parQueue::isEmpty(); }



