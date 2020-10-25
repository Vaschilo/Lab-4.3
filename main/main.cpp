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
		cout << "������� ��� �����, � ������� ����� �������� ����� ������������������:\n";
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
	cout << "\n\n ����� ���������� " << msec << " �����������\n";
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

	cout << "� ����� " << filename << " " << counter << " �����";

	std::chrono::time_point<std::chrono::system_clock> end;
	int msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << "\n\n ����� ���������� " << msec << " �����������\n";
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
	cout << "������� ������, ������� ������ �������� "; 
	getline(cin, s_del);
	getline(cin, s_del);

	cout << "������� ������, �� ������� ������ �������� ������ " << s_del << endl;
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
	cout << "\n\n ����� ���������� " << msec << " �����������\n";
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
			if (choose < 0 || choose > 3) cout << "������� ���������� ��������";
			cout << "\n\n��� �� ������ �������?\n\n";
			cout << "0 - �����\n";
			cout << "1 - ������� ��� ����� �� ������\n";
			cout << "2 - ������ ���������� ���� � ������ �����\n";
			cout << "3 - �������� ������ ������������������ �� ��������\n";
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

std::cout << "����� ����������: " << elapsed_seconds << "s\n"; 

*/