#include "Queue.h"

class sonQueue_private : private parQueue
{
public:
	float harmonicMean();
	int pop(); 
	void push(int el); 
	void print(); 
	void merge(sonQueue_private& Q1); //������� ���� ��������
	int copy(sonQueue_private& Q, int* &buff); //����������� ������� � ������ ������
	void insert(int* buff, int buffsize); // ������� �������
	bool isEmpty(); //�������� �� �������������
};