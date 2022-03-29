#include <iostream>
#include <locale>
#include "Queue.h"
#include "Queue1.h"
#include "Queue2.h"
#include "Queue3.h"

using namespace std;

template <class T>

void chosen_class(T* q, int n_q) 
{
	setlocale(LC_ALL, "Rus");

	int c; //���������� ��� ���������� ����
	int flag = 1; //���������� ��� ������ � ������� ����
	int value; //�������, ����������� � �������
	int index = 0; //����� �������, � ������� ��������
	float res = 0; //���������� ��� ���������� ������� ��������
	int chosen_q; //����� ��������� �������
	int* buff = {0}; //������ ������
	int buffsize; //������ ������� ������

	while (flag == 1)
	{
		cout << "1 - ���������� �������� �������" << endl;
		cout << "2 - ���������� �������� �������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ���������� �������� �������������� �������" << endl;
		cout << "5 - �������� ����� �������" << endl;
		cout << "6 - �������� ����� �������" << endl;
		cout << "7 - ������� ���� ��������" << endl;
		cout << "8 - ����� ���� �������" << endl;
		cout << "9 - � ����� �������� � ������ �������?" << endl;
		cout << "0 - ��������� � ������ ������-����������" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 1: //���������� �������� �������
			system("cls");
			cout << "������� ��������: ";
			cin >> value;
			q[index].push(value);
			cout << "�������� ��������� � �������.\n " << endl;
			break;

		case 2: //���������� �������� �������
			if (q[index].isEmpty()){
				cout << "������� ��� �����, ��������� ������.\n " << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				value = q[index].pop();
				cout << "����������� �������: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: //����� ������� �� �����
			if (q[index].isEmpty()){
				cout << "������� �����, �������� ������.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				q[index].print();
				cout << "\n";
			}
			break;
		case 4: //���������� �������� �������������� �������
			if (q[index].isEmpty()){
				cout << "������� �����, ������� ��������� ����������.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				res = q[index].harmonicMean();
				cout << "������� ������������� �������: " << res << endl;
				cout << "\n";
			}
			break;
		case 5: //�������� ����� �������
			if (q[index].isEmpty()){
				cout << "������� �����, ���������� ������.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				buffsize = q[index].copy(q[index], buff);		
				cout << "������� ������� ����������� � ������.\n" << endl;
			}
			break;
		case 6: //������� ����� �������
			system("cls");
			cout << "������� ����� �������, ���� ������ ����������� ������ � ������� ";
			cin >> chosen_q;
			if (chosen_q < 0 || chosen_q >= n_q){
				cout << "������ ������������ ����� �������" << endl;
				system("pause");
				break;
			}
			q[chosen_q].insert(buff, buffsize);
			cout << "������ � ������� ������� ��������� � ������� ��� ������� " << chosen_q << ".\n" << endl;
			break;
		case 7: //������� ��������
			if (n_q == 1){
				cout << "���������� ������ ���� �������.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "� ����� �������� ���������� �������?" << endl;
				cin >> chosen_q;
				if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index)){
					cout << "������������ ��������!\n" << endl;
					system("pause");
					break;
				}
				if (q[chosen_q].isEmpty()){
					cout << "���������� ���������� �������, ��� ��� ������ ������� �����.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[index].merge(q[chosen_q]);
				cout << "\n";
			}
			break;
		case 8: //������� �� ������ �������
			system("cls");
			cout << "������ �� ��������� � �������� �" << index << endl;
			cout << "������� ����� ������� (�� 0 �� " << n_q - 1 << ") , �� ������� ������ �������������: ";
			cin >> chosen_q;
			if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
			{
				cout << "������������ �������� ��� ���������� �������� ���������!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				system("cls");
				cout << "�� ������������� �� ������� �" << index << endl;
				cout << "\n";
			}
			break;
		case 9: //����� ������� �� ������� �� ���������
			system("cls");
			cout << "�� ������ ��������� � �������� �" << index << endl;
			cout << "\n";
			break;
		case 0: // ����� � ������� ����
			cout << "\n";
			flag = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int num_q = -1; //���������� ���������� ��������
	int c; //���������� ��� ���������� ����
	int flag = 1; //���������� ��� ������ �� ���������

	sonQueue_private* q1 = NULL;
	sonQueue_protected* q2 = NULL;
	sonQueue_public* q3 = NULL;
	while (num_q <= 0)
	{
		cout << "������� ���������� ��������: ";
		cin >> num_q;
		if (num_q <= 0) {
			cout << "�������� ������������ ���������� ��������." << endl;
			system("pause");
		}
		system("cls");
	}
	cout << "��������, � ����� �������-����������� �� ������ ��������: " << endl;

	while (flag == 1)
	{
		cout << "1 - ���������" << endl;
		cout << "2 - ����������" << endl;
		cout << "3 - ���������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 1:
			q1 = new sonQueue_private[num_q];
			system("cls");
			chosen_class(q1, num_q);
			delete[] q1;
			break;

		case 2:
			q2 = new sonQueue_protected[num_q];
			system("cls");
			chosen_class(q2, num_q);
			delete[] q2;
			break;

		case 3:
			q3 = new sonQueue_public[num_q];
			system("cls");
			chosen_class(q3, num_q);
			delete[] q3;
			break;

		case 0:
			flag = 0;
			break;

		default:
			system("cls");
			cout << "������������ ����!" << endl;
			break;

		}
	}
	return 0;
}