#include <iostream>
#include "Queue2.h"

using namespace std;

float sonQueue_protected::harmonicMean()
{
	Unit* last = get_last();
	float result = 0;
	float sum = 0;
	if (size == 0) {
		cout << "Очередь пуста!" << endl;
	}
	else {
		while (last != nullptr)
		{
			sum = sum + 1.0 / (last->data);
			last = last->prev;
		}
		result = size / sum;
	}
	return result;
}

int sonQueue_protected::pop() { return parQueue::pop(); }
void sonQueue_protected::push(int el) { return parQueue::push(el); }
void sonQueue_protected::print() { return parQueue::print(); }
void sonQueue_protected::merge(sonQueue_protected& Q1) { return parQueue::merge(Q1); }
int sonQueue_protected::copy(sonQueue_protected& Q1, int*& buff) { return parQueue::copy(Q1, buff); }
void sonQueue_protected::insert(int* buff, int buffsize) { return parQueue::insert(buff, buffsize); }
bool sonQueue_protected::isEmpty() { return parQueue::isEmpty(); }