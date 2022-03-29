#include <iostream>
#include "Queue3.h"

using namespace std;

float sonQueue_public::harmonicMean()
{
	Unit* last = get_last();
	float max = get_last()->data;
	float min = get_last()->data;
	float result = 0;
	float delta = 0;
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