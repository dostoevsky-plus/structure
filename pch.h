// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H

enum type_of_key { PLANE, TRAINE, SHIP };
enum type_of_ship { LINER, TUG, TANKER };
struct plane {
	type_of_key key;
	int spead;
	int distance;
	int cargo;
	int range;
	int c;
};
struct traine {

	type_of_key key;
	int spead;
	int distance;
	int count;
};
struct ship {
	type_of_key key;
	int spead;
	int distance;
	int water_displacement;
	type_of_ship type;
};
struct transport {
	type_of_key key;
	int spead;
	int distance;
};

struct node {
	node() {
		this->next = nullptr;
		this->prev = nullptr;
		this->data = nullptr;
	};
	node* next;
	node* prev;
	transport* data;
};
struct container {
	node* top;
	int count;
};

// TODO: add headers that you want to pre-compile here

#endif //PCH_H
