//������ ������� �������������� ��������� ��������.
//��������������� ����������� ������ ����������� ����� ������� � ����.
//������� ����� ���������� ��� ������ �� �������.
//����� �������� �� �����.
//����� ����� �������� �� ������������� ���������� �����.

//������� �� ������ ��� �����.
//���������� ���������� ��������� ����.
//� �������� ������ �������� �������� ������������������ �������� ��
//	������ �������� ������������������ ��������.

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
		cout << "������� ��� �����:\n";
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
		cout << "������� ��� �����:\n";
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
	cout << "\n\n ����� ���������� " << elapsed_seconds << " ������\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	int choose = 0;
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	string filename = GetFilename();
	std::cout << "����� ����������: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() << "s\n";

	while (1)
	{
		system("cls");
		do
		{
			if (choose < 0 || choose > 2) cout << "������� ���������� ��������";
			cout << "\n\n��� �� ������ �������?\n\n";
			cout << "0 - �����\n";
			cout << "1 - ������� ��� ����� �� ������ � ������� �� ����������\n";
			cout << "2 - �������� ������ ������������������ �� ��������\n";
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
				if (choose < 0 || choose > 1) cout << "������� ���������� ��������";
				cout << "\n\n��� �� ������ �������?\n\n";
				cout << "0 - ������� ����� ��� ������ � �������\n";
				cout << "1 - ������� ����� ��� ������ � ����\n";
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

std::cout << "����� ����������: " << elapsed_seconds << "s\n"; 

*/