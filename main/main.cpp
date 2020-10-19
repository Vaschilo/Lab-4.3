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
		cout << "Введите имя файла:\n";
		cin >> filename;
		file.open(filename);
	} while (!file.is_open());
	file.close();
	return filename;
}
void DelNumsFromText(const string& filename, const string& filename2)
{
	std::chrono::time_point<std::chrono::system_clock> start;

	fstream file;
	string str;
	file.open(filename);
	while (!file.eof())
	{
		file >> str;
		str.erase(boost::remove_if(str, boost::is_any_of("1234567890")), str.end());
		cout << str << " ";
	}
	file.close();

	std::chrono::time_point<std::chrono::system_clock> end;
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	cout << "\n\n Время выполнения " << elapsed_seconds << " секунд\n";
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
			if (choose < 0 || choose > 2) cout << "Введите корректное значение";
			cout << "\n\nЧто вы хотите сделать?\n\n";
			cout << "0 - выйти\n";
			cout << "1 - Удалить все цифры из текста и вывести их количество\n";
			cout << "2 - Заменить данную последовательность на введённую\n";
			cin >> choose;
		} while (choose < 0 || choose > 2);
		switch (choose)
		{
		case 0:
			return 0;
			break;
		case 1:
			do
			{
				if (choose < 0 || choose > 1) cout << "Введите корректное значение";
				cout << "\n\nЧто вы хотите сделать?\n\n";
				cout << "0 - вывести текст без текста в консоль\n";
				cout << "1 - вывести текст без текста в файл\n";
				cin >> choose;
			} while (choose < 0 || choose > 1);
			choose == 0 ? DelNumsFromText(filename, "?") : DelNumsFromText(filename, GetFilenameWithCreating());
			choose = 1;
			break;
		/*case 2:
			break;*/
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