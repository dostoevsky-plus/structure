// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include <fstream>
#include<string>
// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.


using namespace std;
namespace simple_shapes {
	void Init(container &c);//инициализация контейнера
	void Clear(container &c);//отчистка контейнера
	plane* InPlane(plane &p, ifstream &ifst);//ввод
	traine* InTraine(traine &t, ifstream &ifst);//ввод
	ship* InShip(ship &shp, ifstream &ifst);//ввод
	transport* In(ifstream &ifst);//ввод
	void In(container &c, ifstream &ifst);//ввод
	void OutPlane(plane *p, ofstream &ofst);//вывод
	void Out(container &c, ofstream &ofst);//вывод
	void Out(transport *s, ofstream &ofst);//вывод
	int Addnode(container &c, ifstream &ifst);//добавление звена списка
	void OutTraine(traine *t, ofstream &ofst);//вывод
	string Get_all(plane*p);// ф-ция для тестов


	float Travel_time(transport &s);// подсчет дополнительного параметра
	bool Compare(transport *first, transport* second);//сравнение дополнительного параметра у двух элементов списка
	void Sort(container &c); //сортировка списка
	void Castl(node* &current, node*&currentnext);//смена местами данныз двух элементов списка
	void OutShip(ship *shp, ofstream &ofst);//вывод 
	// проверка данных файла на корректность
	void From_file_to_int(ifstream &ifst, int &field);

	void MultiMethod(container &c, ofstream &ofst) {
		ofst << "Multimethod." << endl;
		node* current_i = c.top;
		for (int i = 0; i < c.count; i++) {
			node* current_j = current_i->next;
			for (int j = i + 1; j < c.count; j++) {
				switch (current_i->data->key) {
				case PLANE:
					switch (current_j->data->key) {
					case PLANE:
						ofst << "Plane and Plane." << endl;
						break;
					case TRAINE:
						ofst << "Plane and Traine" << endl;
						break;
					case SHIP:
						ofst << "Plane and Ship" << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				case TRAINE:
					switch (current_j->data->key) {
					case PLANE:
						ofst << "Traine and Plane." << endl;
						break;
					case TRAINE:
						ofst << "Traine and Traine" << endl;
						break;
					case SHIP:
						ofst << "Traine and Ship" << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				case SHIP:
					switch (current_j->data->key) {
					case PLANE:
						ofst << "Ship and Plane." << endl;
						break;
					case TRAINE:
						ofst << "Ship and Traine" << endl;
						break;
					case SHIP:
						ofst << "Ship and Ship" << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				default:
					ofst << "Unknown type" << endl;
				}
				Out(current_i->data, ofst);
				Out(current_j->data, ofst);
				current_j = current_j->next;

			}
			current_i = current_i->next;
		}
	}

	plane * InPlane(plane & p, ifstream & ifst)
	{
		From_file_to_int(ifst, p.c);
		From_file_to_int(ifst, p.range);
		From_file_to_int(ifst, p.cargo);

		void Out_only_plane(container &c, ofstream &ofst);
		return &p;
	}
	void simple_shapes::From_file_to_int(ifstream & ifst, int &field)
	{
		string str;
		bool flag=true;
		ifst >> str;
		if (str == "")
		{
			flag = false;
		}
		else
		{

			for (int i = 0; i < str.length(); i++)
			{
				if (isdigit(str[i]))
				{
				}
				else
					flag = false;

			}
		}
		if (flag == false)
		{
			cout << "ERROR IN FAILIN.TXT";
			exit(0);
		}
		else
			field = stoi(str);
	}

	traine * InTraine(traine & t, ifstream &ifst)
	{
		From_file_to_int(ifst, t.count);
		return &t;
	}

	ship * InShip(ship & shp, ifstream & ifst)
	{
		int t;
		From_file_to_int(ifst, shp.water_displacement);
		From_file_to_int(ifst, t);
		if (t == 1)
		{
			shp.type = LINER;
		}
		else
			if (t == 2)
			{
				shp.type = TUG;
			}
			else
				if (t == 3)
				{
					shp.type = LINER;
				}
				else
				{
					cout << "ERROR IN FAILIN.TXT";
					exit(0);
				}
		return &shp;
	}
	void Init(container & c)
	{
		c.top = nullptr;
		c.count = 0;
	}

	void Clear(container & c)
	{
		node* current = c.top;
		int i = 1;
		while (i < c.count)
		{
			current = current->next;
			delete current->prev;
			i++;
		}
		delete current;
		c.count = 0;
	}

	void OutPlane(plane *p, ofstream &ofst)
	{
		ofst << "It is Plane: грузоподъемность = " << p->c
		<< ", дальность полета = " << p->range << ", груз в данный момент = " << p->cargo;
	}
	void OutTraine(traine * t, ofstream &ofst)
	{
		ofst << "It is Traine: кол-во вагонов = " << t->count;
	}
	string Get_all(plane * p)
	{

		return string(to_string(p->c) + to_string(p->cargo) + to_string(p->range));
	}
	void OutShip(ship * shp, ofstream &ofst)
	{
		ofst << "It is Ship: Водоизмещение = " << shp->water_displacement << ", тип судна = ";
		if (shp->type == LINER)
			ofst << "LINER";
		else if (shp->type == TANKER)
			ofst << "TANKER";
		else if (shp->type == TUG) ofst << "TUG";
	}
	void Out(container & c, ofstream &ofst)
	{
		node* current = c.top;
		ofst << " Container contains " << c.count
			<< " elements." << endl;
		for (int j = 0; j < c.count; j++) 
		{
			ofst << j << ": ";
			Out(current->data, ofst);
			ofst << "идеальное время пути = "
			<< Travel_time(*(current->data)) << endl;
			current = current->next;
		}
	}
	void Out(transport *s, ofstream &ofst)
	{
		switch (s->key) {
		case PLANE:
			OutPlane((plane*)s, ofst);
			ofst << ", расстояние мужду пунктами = " << s->distance << ", скорость = " << s->spead << endl;
			break;
		case TRAINE:
			OutTraine((traine*)s, ofst);
			ofst << ", расстояние мужду пунктами = " << s->distance << ", скорость = " << s->spead << endl;
			break;
		case SHIP:
			OutShip((ship*)s, ofst);
			ofst << ", расстояние мужду пунктами = " << s->distance << ", скорость = " << s->spead << endl;
			break;
		default:
			cout << "Incorrect figure!" << endl;
		}
	}
	int Addnode(container &c, ifstream &ifst)
	{
		if (c.count == 0)
		{
			c.top = new node;
			c.top->next = c.top;
			c.top->prev = c.top;
			if ((c.top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			node *current = c.top;
			for (int j = 1; j < c.count; j++)
			{
				current = current->next;
			}
			current->next = new node;
			if ((current->next->data = In(ifst)) != 0)
			{
				c.top->prev = current->next;
				current->next->prev = current;
				current->next->next = c.top;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	void In(container &c, ifstream &ifst)
	{
		while (!ifst.eof())
		{
			if (Addnode(c, ifst) != 0)
				c.count++;
		}
	}
	transport * In(ifstream &ifst)
	{
		transport *s = new transport;
		int key;
		From_file_to_int(ifst, key);
		if (key == 1) {
			plane* p = new plane;
			s = (transport*)InPlane(*p, ifst);
			s->key = PLANE;
			From_file_to_int(ifst, s->distance);
			From_file_to_int(ifst, s->spead);
			//ifst >> s->distance >> s->spead;
			return s;
		}
		else if (key == 2)
		{
			traine* t = new traine;
			s = (transport*)InTraine(*t, ifst);
			s->key = TRAINE;
			From_file_to_int(ifst, s->distance);
			From_file_to_int(ifst, s->spead);
			return s;
		}
		else
			if (key == 3)
			{
				ship* shp = new ship;
				s = (transport*)InShip(*shp, ifst);
				s->key = SHIP;
				From_file_to_int(ifst, s->distance);
				From_file_to_int(ifst, s->spead);
				return s;
			}
			else
			{
				cout << "ERROR IN FAILIN.TXT";
				exit(0);
			};
	}
	float Travel_time(transport &s)
	{
		float travel_time;
		travel_time = static_cast<float>(s.distance) / static_cast<float>(s.spead);
		return travel_time;
	}
	bool Compare(transport * first, transport * second)
	{
		return Travel_time(*first) < Travel_time(*second);
	}

	void Sort(container & c)
	{
		node* current;
		current = c.top;
		node* currentnext = current->next;
		for (int i = 1; i < c.count; i++) {
			for (int j = 1; j < c.count; j++) {
				if (Compare(current->data, current->next->data)) {
					currentnext = current->next;
					Castl(current, currentnext);
					current = current->next;
				}
				else
					current = current->next;
			}
			current = c.top;
		}
	}
	void Castl(node* &current, node* &currentnext)
	{
		transport * q1 = current->data;
		transport * q2 = currentnext->data;
		current->data = q2;
		currentnext->data = q1;
	}

	void Out_only_plane(container &c, ofstream &ofst) {
		ofst << "Only planes." << endl;
		node* current = c.top;
		for (int i = 0; i < c.count; i++)
		{
			ofst << i << ": ";
			if (current->data->key == type_of_key::PLANE)
			{
				Out(current->data, ofst);
				ofst << "идеальное время пути = "
				<< Travel_time(*(current->data)) << endl;
			}
			else
				ofst << endl;
			current = current->next;
		}
	}
}




