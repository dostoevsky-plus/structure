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
	transport* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutPlane(plane *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(transport *s, ofstream &ofst);
	int addnode(container &c, ifstream &ifst);
	void OutTraine(traine *t, ofstream &ofst);
	
	void MultiMethod(container &c, ofstream &ofst);
	// Мультиметод
	void MultiMethod(container &c, ofstream &ofst) {
		ofst << "Multimethod." << endl;
		Node* current_i = c.Top;
		for (int i = 0; i < c.count; i++) {
			Node* current_j = current_i->Next;
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
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				default:
					ofst << "Unknown type" << endl;
					
				}
				Out(current_i->data, ofst);
				Out(current_j->data, ofst);
				current_j = current_j->Next;
				
			}
			current_i = current_i->Next;
		}
	}

	plane * InPlane(plane & p, ifstream & ifst)
	{
		ifst >> p.c  >> p.range ;
		return &p;
	}

	traine * InTraine(traine & t, ifstream &ifst)
	{
		ifst >> t.count ;
		return &t;
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
			<< ", дальность полета = " << p->range ;
	}
	void Out(container & c, ofstream &ofst)
	{
		Node* current = c.Top;
		ofst << " Container contains " << c.count
			<< " elements." << endl;
		for (int j = 0; j < c.count; j++) {
			ofst << j << ": ";
			Out(current->data, ofst);
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
	void OutTraine(traine * t, ofstream &ofst)
	{
		ofst << "It is Traine: кол-во вагонов = " << t->count;
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
			return 0;
	}
}

