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

	int c; //переменная для управления меню
	int flag = 1; //переменная для выхода в главное меню
	int value; //элемент, добавляемый в очередь
	int index = 0; //номер очереди, с которой работаем
	float res = 0; //переменная для выполнения задания варианта
	int chosen_q; //номер выбранной очереди
	int* buff = {0}; //буффер обмена
	int buffsize; //размер буффера обмена

	while (flag == 1)
	{
		cout << "1 - Добавление элемента очереди" << endl;
		cout << "2 - Извлечение элемента очереди" << endl;
		cout << "3 - Вывод очереди на экран" << endl;
		cout << "4 - Нахождение среднего гармонического очереди" << endl;
		cout << "5 - Создание копии очереди" << endl;
		cout << "6 - Вставить копию очереди" << endl;
		cout << "7 - Слияние двух очередей" << endl;
		cout << "8 - Выбор иной очереди" << endl;
		cout << "9 - С какой очередью я сейчас работаю?" << endl;
		cout << "0 - Вернуться к выбору класса-наследника" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 1: //добавление элемента очереди
			system("cls");
			cout << "Введите значение: ";
			cin >> value;
			q[index].push(value);
			cout << "Значение добавлено в очередь.\n " << endl;
			break;

		case 2: //извлечение элемента очереди
			if (q[index].isEmpty()){
				cout << "Очередь уже пуста, извлекать нечего.\n " << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				value = q[index].pop();
				cout << "Извлеченный элемент: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: //вывод очереди на экран
			if (q[index].isEmpty()){
				cout << "Очередь пуста, выводить нечего.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				q[index].print();
				cout << "\n";
			}
			break;
		case 4: //нахождение среднего гармонического очереди
			if (q[index].isEmpty()){
				cout << "Очередь пуста, задание выполнить невозможно.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				res = q[index].harmonicMean();
				cout << "Среднее гармоническое очереди: " << res << endl;
				cout << "\n";
			}
			break;
		case 5: //создание копии очереди
			if (q[index].isEmpty()){
				cout << "Очередь пуста, копировать нечего.\n" << endl;
				system("pause");
				break;
			}
			else{
				system("cls");
				buffsize = q[index].copy(q[index], buff);		
				cout << "Очередь успешно скопирована в буффер.\n" << endl;
			}
			break;
		case 6: //вставка копии очереди
			system("cls");
			cout << "Введите номер очереди, куда ходить скопировать данные с буффера ";
			cin >> chosen_q;
			if (chosen_q < 0 || chosen_q >= n_q){
				cout << "Введен некорректный номер очереди" << endl;
				system("pause");
				break;
			}
			q[chosen_q].insert(buff, buffsize);
			cout << "Данные с буффера успешно вставлены в очередь под номером " << chosen_q << ".\n" << endl;
			break;
		case 7: //слияние очередей
			if (n_q == 1){
				cout << "Существует только одна очередь.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "С какой очередью произвести слияние?" << endl;
				cin >> chosen_q;
				if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index)){
					cout << "Некорректное значение!\n" << endl;
					system("pause");
					break;
				}
				if (q[chosen_q].isEmpty()){
					cout << "Невозможно произвести слияние, так как вторая очередь пуста.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[index].merge(q[chosen_q]);
				cout << "\n";
			}
			break;
		case 8: //переход на другую очередь
			system("cls");
			cout << "Сейчас вы работаете с очередью №" << index << endl;
			cout << "Введите номер очереди (от 0 до " << n_q - 1 << ") , на которую хотите переключиться: ";
			cin >> chosen_q;
			if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
			{
				cout << "Некорректное значение или количество очередей превышено!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				system("cls");
				cout << "Вы переключились на очередь №" << index << endl;
				cout << "\n";
			}
			break;
		case 9: //номер очереди на которой мы находимся
			system("cls");
			cout << "Вы сейчас работаете с очередью №" << index << endl;
			cout << "\n";
			break;
		case 0: // выход в главное меню
			cout << "\n";
			flag = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int num_q = -1; //переменная количества очередей
	int c; //переменная для управления меню
	int flag = 1; //переменная для выхода из программы

	sonQueue_private* q1 = NULL;
	sonQueue_protected* q2 = NULL;
	sonQueue_public* q3 = NULL;
	while (num_q <= 0)
	{
		cout << "Введите количество очередей: ";
		cin >> num_q;
		if (num_q <= 0) {
			cout << "Введенно некорректное количество очередей." << endl;
			system("pause");
		}
		system("cls");
	}
	cout << "Выберите, с каким классом-наследником Вы будете работать: " << endl;

	while (flag == 1)
	{
		cout << "1 - Приватный" << endl;
		cout << "2 - Защищенный" << endl;
		cout << "3 - Публичный" << endl;
		cout << "0 - Выход из программы" << endl;
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
			cout << "Некорректный ввод!" << endl;
			break;

		}
	}
	return 0;
}