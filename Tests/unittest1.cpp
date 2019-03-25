#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/pch.h";
#include "../ConsoleApplication1/pch.cpp"
#include <string>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_shapes;
namespace Tests
{
	TEST_CLASS(Test_out)
	{
	public:
		TEST_METHOD(Plane_Out)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			OutPlane((plane*)test, ofst);
			ofst.close();
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Plane: грузоподъемность = 1000, дальность полета = 1, груз в данный момент = 187";
			Assert::AreEqual(expected_string, test_string);
		};
		TEST_METHOD(Traine_Out)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);
			test = In(ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			OutTraine((traine*)test, ofst);
			ofst.close();
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Traine: кол-во вагонов = 30";
			Assert::AreEqual(expected_string, test_string);
		};
		TEST_METHOD(Ship_Out)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);
			test = In(ifst);
			test = In(ifst);
			test = In(ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			OutShip((ship*)test, ofst);
			ofst.close();
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Ship: Водоизмещение = 3, тип судна = TUG";
			Assert::AreEqual(expected_string, test_string);
		};
		TEST_METHOD(Transport_Out)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			Out(test, ofst);
			ofst.close();
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Plane: грузоподъемность = 1000, дальность полета = 1, груз в данный момент = 187, расстояние мужду пунктами = 150, скорость = 25";
			Assert::AreEqual(expected_string, test_string);
		};
		TEST_METHOD(Container_Out)
		{
			container test;
			Init(test);
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			In(test, ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			Out(test, ofst);
			ofst.close();

			string expected_string = " Container contains 4 elements.";
			//expected_string=expected_string+'\n';
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "0: It is Plane: грузоподъемность = 1000, дальность полета = 1, груз в данный момент = 187, расстояние мужду пунктами = 150, скорость = 25";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "1: It is Traine: кол-во вагонов = 30, расстояние мужду пунктами = 8000, скорость = 80";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 100";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "2: It is Plane: грузоподъемность = 1000, дальность полета = 15000, груз в данный момент = 900, расстояние мужду пунктами = 1500, скорость = 2500";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 0.6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "3: It is Ship: Водоизмещение = 3, тип судна = TUG, расстояние мужду пунктами = 700, скорость = 700";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 1";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);
		};
		TEST_METHOD(Out_only_plane_test)
		{
			container test;
			Init(test);
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			In(test, ifst);
			ofstream ofst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			Out_only_plane(test, ofst);
			ofst.close();

			string expected_string = "Only planes.";
			//expected_string=expected_string+'\n';
			string test_string;
			ifstream iffst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\fileout.txt");
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "0: It is Plane: грузоподъемность = 1000, дальность полета = 1, груз в данный момент = 187, расстояние мужду пунктами = 150, скорость = 25";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "1: ";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);


			expected_string = "2: It is Plane: грузоподъемность = 1000, дальность полета = 15000, груз в данный момент = 900, расстояние мужду пунктами = 1500, скорость = 2500";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "идеальное время пути = 0.6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "3: ";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

		}

	};
	TEST_CLASS(Test_container_function)
	{
	public:
		TEST_METHOD(Castl_test)
		{
			container test;
			Init(test);
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			In(test, ifst);
			castl(test.Top, test.Top->Next);//меняем местами
			float test_time = 100;
			Assert::AreEqual(test_time, Travel_time(*test.Top->data));
		};
		TEST_METHOD(Sort_test)
		{
			container test;
			Init(test);
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			In(test, ifst);
			Sort(test);
			float test_time = 100;
			Assert::AreEqual(test_time, Travel_time(*test.Top->data));
			test_time = 6;
			Assert::AreEqual(test_time, Travel_time(*test.Top->Next->data));
			test_time = 1;
			Assert::AreEqual(test_time, Travel_time(*test.Top->Next->Next->data));
			test_time = 0.6;
			Assert::AreEqual(test_time, Travel_time(*test.Top->Next->Next->Next->data));
		}
	};
	TEST_CLASS(Test_transport_function)
	{
	public:
		TEST_METHOD(Travel_time_test)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);
			test->distance = 1000;
			test->spead = 80;
			float time_test = 12.5;
			Assert::AreEqual(time_test, Travel_time(*test));
			//объект другого типа
			test = In(ifst);
			test->distance = 1000;
			test->spead = 80;
			time_test = 12.5;
			Assert::AreEqual(time_test, Travel_time(*test));
		};
		TEST_METHOD(Compare_test)
		{
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test_1 = In(ifst);
			transport *test_2 = In(ifst);
			test_1->distance = 100;
			test_1->spead = 20;
			test_2->distance = 250;
			test_2->spead = 25;
			bool compare_test = 1;
			Assert::AreEqual(compare_test, Compare(test_1, test_2));
		}
	};
	TEST_CLASS(Test_In)
	{
	public:

		TEST_METHOD(Plane_In_test)
		{
			int c_test = 1000;
			int range_test = 1;
			int cargo_test = 187;
			int key;

			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			ifst >> key;
			plane test;
			InPlane(test, ifst);
			//test.InData(ifst);
			Assert::AreEqual(c_test, test.c);
			Assert::AreEqual(range_test, test.range);
			Assert::AreEqual(cargo_test, test.cargo);
			// TODO: Разместите здесь код своего теста
		};

		TEST_METHOD(Traine_In_test)
		{
			int count_test = 1000;
			int key;

			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			ifst >> key;
			traine test;
			InTraine(test, ifst);
			//test.InData(ifst);
			Assert::AreEqual(count_test, test.count);
			// TODO: Разместите здесь код своего теста
		};

		TEST_METHOD(Ship_In_test)
		{
			int water_displacement_test = 1000;
			type_of_ship type_test = LINER;
			int key;

			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			ifst >> key;
			ship test;
			InShip(test, ifst);
			Assert::AreEqual(water_displacement_test, test.water_displacement);
			Assert::AreEqual(to_string(type_test), to_string(test.type));

			// TODO: Разместите здесь код своего теста
		};
		TEST_METHOD(transport_in)
		{
			int distance_test = 150;
			int spead_test = 25;
			int c_test = 1000;
			int range_test = 1;
			int cargo_test = 187;


			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			transport *test = In(ifst);

			Assert::AreEqual(distance_test, test->distance);
			Assert::AreEqual(spead_test, test->spead);
			Assert::AreEqual(to_string(c_test) + to_string(cargo_test) + to_string(range_test), get_all((plane*)test));
			// TODO: Разместите здесь код своего теста
		};
		TEST_METHOD(container_in)
		{
			int count_test = 4;
			ifstream ifst("C:\\Users\\Владислав\\Desktop\\Github\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\filein.txt");
			container test;
			Init(test);
			In(test, ifst);
			Assert::AreEqual(count_test, test.count);
		}


	};
}