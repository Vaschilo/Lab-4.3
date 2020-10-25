//Каждое задание обрабатывается отдельной функцией.
//Предоставляется возможность выбора выполняемой части задания в меню.
//Вывести время выполнения для каждой из функций.
//Текст получать из файла.
//Текст может состоять из произвольного количества строк.

//Удалить из текста все цифры.
//Подсчитать количество удаленных цифр.
//В заданном тексте заменить заданную последовательность символов на
//	другую заданную последовательность символов.

#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>
#include <chrono>
using namespace std;

string GetFilename()
{
	string filename;
	fstream file;
	do
	{
		cout << "Введите имя файла:\n";
		cin >> filename;
		file.open(filename);
	} while (!file.is_open());
	file.close();
	return filename;
}
string GetFilenameWithCreating()
{
	string filename;
	ofstream file;
	do
	{
		cout << "Введите имя файла, в который будет записана новая последовательность:\n";
		cin >> filename;
		file.open(filename, ios::trunc);
	} while (!file.is_open());
	file.close();
	return filename;
}

void DelNumsFromText(const string& filename)
{
	std::chrono::time_point<std::chrono::system_clock> start;

	fstream file;
	fstream file2;
	string str;

	file.open(filename);
	file2.open(GetFilenameWithCreating());

	while (!file.eof())
	{
		getline(file, str);
		str.erase(boost::remove_if(str, boost::is_any_of("1234567890")), str.end());
		auto it = str.begin();
		while (it != str.end())
		{
			file2.put(*it);
			it++;
		}
		file2.put('\n');
	}
	file.close();
	file2.close();

	std::chrono::time_point<std::chrono::system_clock> end;
	int msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << "\n\n Время выполнения " << msec << " миллисекунд\n";
}

bool check(char t)
{
	if (t == '0') return true;
	if (t == '1') return true;
	if (t == '2') return true;
	if (t == '3') return true;
	if (t == '4') return true;
	if (t == '5') return true;
	if (t == '6') return true;
	if (t == '7') return true;
	if (t == '8') return true;
	if (t == '9') return true;
	return false;
}
void NumCount(const string& filename)
{
	std::chrono::time_point<std::chrono::system_clock> start;

	fstream file;
	string str;
	int counter = 0;
	string::iterator it;

	file.open(filename);

	while (!file.eof())
	{
		getline(file, str);
		it = str.begin();
		while (it != str.end())
		{
			if (check(*it)) counter++;
			it++;
		}
	}
	file.close();

	cout << "В файле " << filename << " " << counter << " чисел";

	std::chrono::time_point<std::chrono::system_clock> end;
	int msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << "\n\n Время выполнения " << msec << " миллисекунд\n";
}

void swapping(const string& filename)
{
	std::chrono::time_point<std::chrono::system_clock> start;

	fstream file;
	fstream file2;
	string str;
	string s_del;
	string s_add;

	file.open(filename);
	file2.open(GetFilenameWithCreating());

	system("cls");
	cout << "Введите строку, которую хотите заменить "; 
	getline(cin, s_del);
	getline(cin, s_del);

	cout << "Введите строку, на которую хотите заменить строку " << s_del << endl;
	getline(cin, s_add);

	while (!file.eof())
	{
		getline(file, str);
		int pos = str.find(s_del);
		if (pos > -1)
		{
			str.replace(pos, s_del.size(), s_add);
		}
		auto it = str.begin();
		while (it != str.end())
		{
			file2.put(*it);
			it++;
		}
		file2.put('\n');
	}
	file.close();
	file2.close();

	std::chrono::time_point<std::chrono::system_clock> end;
	int msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << "\n\n Время выполнения " << msec << " миллисекунд\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	int choose = 0;
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	string filename = GetFilename();
	std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() << "s\n";

	while (1)
	{
		system("cls");
		do
		{
			if (choose < 0 || choose > 3) cout << "Введите корректное значение";
			cout << "\n\nЧто вы хотите сделать?\n\n";
			cout << "0 - выйти\n";
			cout << "1 - Удалить все цифры из текста\n";
			cout << "2 - Узнать количество цифр в данном файле\n";
			cout << "3 - Заменить данную последовательность на введённую\n";
			cin >> choose;
		} while (choose < 0 || choose > 3);
		switch (choose)
		{
		case 0:
			return 0;
			break;
		case 1:
			DelNumsFromText(filename);
			break;
		case 2:
			NumCount(filename);
			break;
		case 3:
			swapping(filename);
			break;
		}

		system("pause");
	}
	return 0;
}

/*

std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();
end = std::chrono::system_clock::now();

int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

std::cout << "Время выполнения: " << elapsed_seconds << "s\n"; 

*/