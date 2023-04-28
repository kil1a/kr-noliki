#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
int player1{}, player2{};
const int SIZE = 4;
char kn[SIZE][SIZE];
int u = rand() % 4;
int p = rand() % 4;
bool proverka(char nut) {
	for (int i = 0; i < SIZE; ++i) {
		if (
			((kn[i][0] == nut) && (kn[i][1] == nut) && (kn[i][2] == nut) && (kn[i][3] == nut)) ||
			(kn[0][i] == nut) && (kn[1][i] == nut) && (kn[2][i] == nut) && (kn[3][i] == nut) ||
			((kn[0][0] == nut) && (kn[1][1] == nut) && (kn[2][2] == nut) && (kn[3][3] == nut)) ||
			((kn[3][0] == nut) && (kn[2][1] == nut) && (kn[1][2] == nut) && (kn[0][3] == nut)))
		{
			return 1;
		}
	}

}

bool occupied(int x, int y) { // проверка на пустую позицию
	return(kn[x - 1][y - 1] == '*');
}

void GenField() {
	for (int i = 0; i < SIZE; i++) {
		cout << "\t\t\t\t\t\t\t ";
		for (int j = 0; j < SIZE; j++) {
			kn[i][j] = '*';
		}
		cout << endl;
	}
}

void PrintField() {
	for (int i = 0; i < SIZE; i++) {
		cout << "\t\t\t\t\t\t\t ";
		for (int j = 0; j < SIZE; j++) {
			//kn[i][j] = '*';
			cout << kn[i][j] << " ";
		}
		cout << endl;
	}
}

void menu() {
	std::system("cls");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " \t\t\t\t\t\t\tMENU \t \n\t\t\t\t\t\t  КРЕСТИКИ-НОЛИКИ\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t\t\t\t\t 1.играть с другом\n";
	cout << "\t\t\t\t\t\t  2.играть с VLAD\n";
	cout << "\t\t\t\t\t\t     3.правила\n";
	cout << "\t\t\t\t\t 4.история игры и интересные факты\n";
	cout << "\t\t\t\t\t\t      5.выход\n";
}
void play_bot() {
	bool step = true; // флаг для остановки цикла хода
	std::system("cls");
	int x{}, y{}, k{}, dgt{};
	char player{}, bot{};
	char c, z;
	string s, a, b, name1, name2;
	name1 = "1й игрок";
	name1 = "2й игрок";
	a = "НОЛИКИ";
	b = "КРЕСТИКИ";
	z = '0';
	c = 'X';
	cout << "\t\t\t\t\tЗа кого ходит первый игрок?(введите цифру):" << endl;
	cout << "\t\t\t\t\t\t\t0: 1 " << "X: 2" << endl;
	cout << "\t\t\t\t\t\t\t  выбор: \n\n\n";
	cin >> dgt;
	if (dgt == 1)
	{
		player = z;
		bot = c;
	}
	else if (dgt == 2) {
		player = c;
		bot = z;
	}
	PrintField();
	for (int i = 0; i < 16; i++) {
		if ((!(i % 2)) && (dgt == 1)) s = a;
		if ((!(i % 2)) && (dgt == 2)) s = b;
		if ((i % 2) && (dgt == 1)) s = b;
		if ((i % 2) && (dgt == 2)) s = a;
		do {
			cout << "\t\t\t\t\t\t  Сделайте ваш ход (" << s << ")" << endl;
			cout << "Строка: ";
			cin >> x;
			cout << "Столбец: ";
			cin >> y;
			//x--;
			//y--;
			/*if (kn[x][y] != '*') {
				std::system("cls");
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						cout << kn[i][j] << " ";
					}
				cout << "\t\t\t\t\t\t\tпозиция занята!" << endl;
					cout << endl;
				}
			}*/
			if (occupied(x, y))
			{
				system("cls");
				kn[x - 1][y - 1] = player;
				PrintField();
				kn[x - 1][y - 1] = player;

			}
			else {
				cout << "\t\t\t\t\t\t\tпозиция занята!" << endl;
			}
			if (proverka('X') || proverka('0'))
			{

				k++;

				cout << "Игра закончена! ";
				if ((kn[x][y] == z) && (dgt == 1) || (kn[x][y] == c) && (dgt == 2)) {
					cout << name1 << " победил!" << endl;
					return;
				}

				if ((kn[x][y] == c) && (dgt == 1) || (kn[x][y] == z) && (dgt == 2)) {
					cout << name2 << " победил!" << endl;
					return;
				}

			}
			while (step)
			{
				u = rand() % 4;
				p = rand() % 4;
				if (occupied(u, p))
					kn[u - 1][p - 1] = bot;
				else
					continue;

				step = false;
			}
			step = true;
		} while (!occupied(x, y)); /* (kn[x][y] != '*'); */
		if ((!(i % 2)) && (dgt == 1)) kn[x][y] = z;
		if ((!(i % 2)) && (dgt == 2)) kn[u][p] = c;
		if ((i % 2) && (dgt == 1)) kn[x][y] = c;
		if ((i % 2) && (dgt == 2)) kn[u][p] = z;
		if ((!(i % 2)) && (dgt == 1)) kn[u][p] = z;
		if ((!(i % 2)) && (dgt == 2)) kn[x][y] = c;
		if ((i % 2) && (dgt == 1)) kn[u][p] = c;
		if ((i % 2) && (dgt == 2)) kn[x][y] = z;


		std::system("cls");
		k = 0;
		for (int i = 0; i < SIZE; i++) {
			cout << "\t\t\t\t\t\t\t ";
			for (int j = 0; j < SIZE; j++) {
				cout << kn[i][j] << " ";
			}
			cout << endl;
		}
		/*for (int i = 0; i < SIZE; ++i) {
			if (proverka('X'))
			{

				k++;

				cout << "Игра закончена! ";
				if ((kn[x][y] == z) && (dgt == 1) || (kn[x][y] == c) && (dgt == 2)) {
					cout << name1 << " победил!" << endl;
					break;
				}
				return;
				if ((kn[x][y] == c) && (dgt == 1) || (kn[x][y] == z) && (dgt == 2)) {
					cout << name2 << " победил!" << endl;
					break;
				}
				return;
			}
			if (proverka('0'))
			{

				k++;

				cout << "Игра закончена! ";
				if ((kn[x][y] == z) && (dgt == 1) || (kn[x][y] == c) && (dgt == 2)) {
					cout << name1 << " победил!" << endl;
					break;
				}
				return;
				if ((kn[x][y] == c) && (dgt == 1) || (kn[x][y] == z) && (dgt == 2)) {
					cout << name2 << " победил!" << endl;
					break;
				}
				return;
			}

		}*/

	}
	if (!(k)) cout << "Игра закончилась вничью!" << endl;
	std::system("pause");

}
void play() {
	std::system("cls");
	int x, y, k, dgt;
	char c, z;
	string s, a, b, name1, name2;
	name1 = "1й игрок";
	name1 = "2й игрок";
	a = "НОЛИКИ";
	b = "КРЕСТИКИ";
	z = '0';
	c = 'X';
	cout << "\t\t\t\t\tЗа кого ходит первый игрок?(введите цифру):" << endl;
	cout << "\t\t\t\t\t\t\t0: 1 " << "X: 2" << endl;
	cout << "\t\t\t\t\t\t\t  выбор: \n\n\n";
	cin >> dgt;
	for (int i = 0; i < SIZE; i++) {
		cout << "\t\t\t\t\t\t\t ";
		for (int j = 0; j < SIZE; j++) {
			kn[i][j] = '*';
			cout << kn[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 16; i++) {
		if ((!(i % 2)) && (dgt == 1)) s = a;
		if ((!(i % 2)) && (dgt == 2)) s = b;
		if ((i % 2) && (dgt == 1)) s = b;
		if ((i % 2) && (dgt == 2)) s = a;
		do {
			cout << "\t\t\t\t\t\t  Сделайте ваш ход (" << s << ")" << endl;
			cout << "Строка: ";
			cin >> x;
			cout << "Столбец: ";
			cin >> y;
			x--;
			y--;
			if (kn[x][y] != '*') {
				std::system("cls");
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						cout << kn[i][j] << " ";
					}
					cout << endl;
				}
				cout << "\t\t\t\t\t\t\tпозиция занята!" << endl;
			}
		} while (kn[x][y] != '*');
		if ((!(i % 2)) && (dgt == 1)) kn[x][y] = z;
		if ((!(i % 2)) && (dgt == 2)) kn[x][y] = c;
		if ((i % 2) && (dgt == 1)) kn[x][y] = c;
		if ((i % 2) && (dgt == 2)) kn[x][y] = z;
		std::system("cls");
		k = 0;
		for (int i = 0; i < SIZE; i++) {
			cout << "\t\t\t\t\t\t\t ";
			for (int j = 0; j < SIZE; j++) {
				cout << kn[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < SIZE; ++i) {
			if (proverka('0'))
			{

				k++;

				cout << "Игра закончена! ";
				if ((kn[x][y] == z) && (dgt == 1) || (kn[x][y] == c) && (dgt == 2)) {
					cout << name1 << " победил!" << endl;
					break;
				}
				return;
				if ((kn[x][y] == c) && (dgt == 1) || (kn[x][y] == z) && (dgt == 2)) {
					cout << name2 << " победил!" << endl;
					break;
				}
				return;
			}
			if (proverka('X'))
			{

				k++;

				cout << "Игра закончена! ";
				if ((kn[x][y] == z) && (dgt == 1) || (kn[x][y] == c) && (dgt == 2)) {
					cout << name1 << " победил!" << endl;
					break;
				}
				return;
				if ((kn[x][y] == c) && (dgt == 1) || (kn[x][y] == z) && (dgt == 2)) {
					cout << name2 << " победил!" << endl;
					break;
				}
				return;
			}

		}
	}
	if (!(k)) cout << "Игра закончилась вничью!" << endl;
	std::system("pause");







}
void rules()
{
	cout << "Игроки по очереди ставят на свободные клетки поля 4 на 4 знаки (один всегда крестики, другой всегда нолики). Первый, выстроивший в ряд 4 своих фигуры по вертикали, горизонтали или большой диагонали, выигрывает. Если игроки заполнили все 9 ячеек и оказалось, что ни в одной вертикали, горизонтали или большой диагонали нет трёх одинаковых знаков, партия считается закончившейся в ничью. Первый ход делает игрок, ставящий крестики. Обычно по завершении партии выигравшая сторона зачёркивает чертой свои три знака(нолика или крестика), составляющих сплошной ряд.";
}
void factsandhistory()
{
	cout << "История появления игры «Крестики-нолики» Существует много споров вокруг создания игры «Крестики - нолики».Существует всего несколько вариантов его оригинального дизайна. Некоторые предполагают, что Индия была колыбелью крестиков - ноликов около 2000 лет назад.Доска, на которой были выложены фигурки, была разделена таким же образом, как сейчас 3 на 3 квадрата. Позже изобретатель изобрел шахматную доску на основе доски для нулей и крестов, увеличив ее размер до 8 на 8 квадратов. Вторая версия создания игры «Крестики - нолики» утверждает, что ее придумал римский разработчик.Но он не мог вспомнить игру из - за захвата Рима варварами. История снова умалчивает о дальнейшем развитии игры.Но некоторые источники связывают его появление с французским математиком, который случайно вывел комбинацию, основанную на решении трехуровневой системы уравнений.";
}





int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "RUS");
	int men;
	GenField();
	string confirm;
	do
	{

		menu();
		cout << "\t\t\t\t\t\t\tввод: " << endl << "\t\t\t\t\t\t\t  ";
		cin >> men;
		switch (men)
		{
		case 1: play(); break;
		case 2: play_bot(); break;
		case 3: rules(); break;
		case 4: factsandhistory(); break;
		case 5: std::system("cls"); cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       ДО ВСТРЕЧИ\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; return 0; break;
		default: cout << "введите один из вариантов меню"; break;
		}
		cout << endl << "\t\t\t\t\t  введите 1 или 0 для продолжения: ";
		cin >> confirm;
	} while (confirm == "1" || confirm == "0");
	return 0;
}