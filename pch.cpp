﻿// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include <fstream>
// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.


using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	plane* InPlane(plane &p, ifstream &ifst);
	traine* InTraine(traine &t, ifstream &ifst);
	ship* InShip(ship &shp, ifstream &ifst);
	transport* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutPlane(plane *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(transport *s, ofstream &ofst);
	int addnode(container &c, ifstream &ifst);
	void OutTraine(traine *t, ofstream &ofst);



	float Travel_time(transport &s);
	bool Compare(transport *first, transport* second);
	void Sort(container &c);
	void castl(Node* &current, Node*&currentnext);
	void pocesssort(Node*& headt, Node*& current, Node*& currentnext);
	void OutShip(ship *shp, ofstream &ofst);

	plane * InPlane(plane & p, ifstream & ifst)
	{
		ifst >> p.c  >> p.range >> p.cargo ;

	void Out_only_plane(container &c, ofstream &ofst);

		return &p;
	}

	traine * InTraine(traine & t, ifstream &ifst)
	{
		ifst >> t.count;
		return &t;
	}

	ship * InShip(ship & shp, ifstream & ifst)
	{
		int t;
		ifst >> shp.water_displacement >> t;
		if (t == 1)
		{
			shp.type = LINER;
		}
		else
			if (t == 2)
			{
				shp.type = TUG;
			}else
				if (t == 3)
				{
					shp.type = LINER;
				}
		return &shp;
	}
	void Init(container & c)
	{
		c.Top = nullptr;
		c.count = 0;
	}

	void Clear(container & c)
	{
		Node* current = c.Top;
		int i = 1;
		while (i < c.count)
		{
			current = current->Next;
			delete current->Prev;
			i++;
		}
		delete current;
		c.count = 0;
	}

	void OutPlane(plane *p, ofstream &ofst)
	{
		ofst << "It is Plane: грузоподъемность = " << p->c
			<< ", дальность полета = " << p->range << ", груз в данный момент = " << p->cargo ;
	}
	void OutTraine(traine * t, ofstream &ofst)
	{
		ofst << "It is Traine: кол-во вагонов = " << t->count;
	}
	void OutShip(ship * shp, ofstream &ofst)
	{
		ofst << "It is Ship: Водоизмещение = " << shp->water_displacement << ", тип судна =" ;
		if (shp->type == LINER)
			ofst << "LINER";
		else if (shp->type == TANKER)
			ofst << "TANKER";
		else if (shp->type == TUG) ofst << "TUG";
	}
	void Out(container & c, ofstream &ofst)
	{
		Node* current = c.Top;
		ofst << " Container contains " << c.count
			<< " elements." << endl;
		for (int j = 0; j < c.count; j++) {
			ofst << j << ": ";
			Out(current->data, ofst);
			ofst << "идеальное время пути = "
				<< Travel_time(*(current->data)) /*<< "часа(ов)"*/ << endl;
			current = current->Next;
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
	int addnode(container &c, ifstream &ifst)
	{
		if (c.count == 0)
		{
			c.Top = new Node;
			c.Top->Next = c.Top;
			c.Top->Prev = c.Top;
			if ((c.Top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			Node *current = c.Top;
			for (int j = 1; j < c.count; j++)
			{
				current = current->Next;
			}
			current->Next = new Node;
			if ((current->Next->data = In(ifst)) != 0)
			{
				c.Top->Prev = current->Next;
				current->Next->Prev = current;
				current->Next->Next = c.Top;
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
		while (!ifst.eof()) {
			if (addnode(c, ifst) != 0)
				c.count++;
		}
	}
	transport * In(ifstream &ifst)
	{
		transport *s = new transport;
		int key;
		ifst >> key;
		if (key == 1) {
			plane* p = new plane;
			s = (transport*)InPlane(*p, ifst);
			s->key = PLANE;
			ifst >> s->distance >> s->spead;
			return s;
		}
		else if (key == 2)
		{
			traine* t = new traine;
			s = (transport*)InTraine(*t, ifst);
			s->key = TRAINE;
			ifst >> s->distance >> s->spead;
			return s;
		}
		else
			if (key == 3)
			{
				ship* shp  = new ship;
				s = (transport*)InShip(*shp, ifst);
				s->key = SHIP;
				ifst >> s->distance >> s->spead;
				return s;
			}
			else
			return 0;
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
		Node* current;
		current = c.Top;
		Node* currentnext = current->Next;
		for (int i = 1; i < c.count; i++) {
			for (int j = 1; j < c.count; j++) {
				if (Compare(current->data, current->Next->data)) {
					currentnext = current->Next;
					pocesssort(c.Top, current, currentnext);
					current = current->Next;
				}
				else
				current = current->Next;
			}
			current = c.Top;
		}
	}
	void castl(Node* &current, Node* &currentnext)
	{
		//Node* currentnext = current->Next;
		//Создаем копии, для смены местами
		transport * q1 = current->data;
		transport * q2 = currentnext->data;
		current->data = q2;
		currentnext->data = q1;
		/*current = q2;
		currentnext = q1;
		currentnext->Next = current->Next;
		current->Next = currentnext;
		current->Prev = currentnext->Prev;
		currentnext->Prev = current;
		currentnext = current->Next;
		currentnext->Next->Prev = currentnext;
		current->Prev->Next = current;*/
	}
	void pocesssort(Node *& headt, Node *& current, Node* &currentnext)
	{
		//Node* currentnext = current->Next;
		if (current == headt)//определяем указывает ли на голову
		{
			if (current->Next->Next == current)
			{
				headt = current->Next;
			}
			else
			{
				castl(current, currentnext);
				//headt = current;
			}
		}
		else
		{
			if (current->Next->Next == current)
			{
				headt = current->Next;
			}
			else
			castl(current, currentnext);
		}
	}
	;
	void Out_only_plane(container &c, ofstream &ofst) {
		ofst << "Only planes." << endl;
		Node* current = c.Top;
		for (int i = 0; i < c.count; i++) {
			ofst << i << ": ";
			if (current->data->key == type_of_key::PLANE)
				Out(current->data, ofst);
			else
				ofst << endl;
			current = current->Next;
		}
	}
}

	


