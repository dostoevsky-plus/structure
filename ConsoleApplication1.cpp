﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	plane* InPlane(plane &p, ifstream &ifst);
	traine* InTraine(traine &t, ifstream &ifst);
	Node* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutPlane(plane *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(Node *s, ofstream &ofst);
	int addlist(container &c, ifstream &ifst);
	void OutTraine(traine *t, ofstream &ofst);


	float Travel_time(transport &s);
	bool Compare(transport *first, transport* second);
	void Sort(container &c);
	void Out_only_plane(container &c, ofstream &ofst);
}
using namespace simple_shapes;
int main(int argc, char* argv[])
{
	int a;
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);
	if (!ifst)

	{
		cout << "No input file found!" << endl;
		return 0;
	}
	ofstream ofst(argv[2]);
	setlocale(LC_ALL, "Russian");
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;

	Out(c, ofst);

	Sort(c);
	ofst << endl;
	Out(c, ofst);

	ofst << endl;
	Out_only_plane(c, ofst);

	ofst << endl;
	Clear(c);

	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("pause");
	cin >> a;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или1 меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

