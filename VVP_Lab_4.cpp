#include <iostream>
#include <math.h>
using namespace std;
void radian();
void degree();
void sum(float a, float b);

float a, x, y, v1, v2, t, b, detY, detX;
double distances;
int S, det, A1, A2, B1, B2, C1, C2;

int main()
{	
	setlocale(LC_ALL, "ru");
	cout << "Выберите задание, которое хотите проверить:\n" <<
		"1. Дано значение угла a в градусах (0 < a < 360). Определить значение этого же угла в радианах, учитывая, что 180 градусов = Пи радианов.\n" <<
		"2. Дано значение угла a в радианах (0 < a < 2·Пи).\n" <<
		"Определить значение этого же угла в градусах, учитывая, что 180 градусов = Пи радианов.\n" <<
		"3. Известно, что X кг конфет стоит A рублей. Определить, сколько стоит 1 кг и Y кг этих же конфет.\n" <<
		"4. Скорость первого автомобиля V1 км/ч, второго — V2 км/ч, расстояние между ними S км.\n" << 
		"Определить расстояние между ними через T часов, если автомобили удаляются друг от друга.\n" <<
		"5. Решить линейное уравнение A·x + B = 0, заданное своими коэффициентами A и B (коэффициент A не равен 0).\n" <<
		"6. Найти решение системы линейных уравнений вида\n" <<
		"\tA1·x + B1·y = C1,\n" <<
		"\tA2·x + B2·y = C2.\n";
	int number;
	cin >> number;
	switch (number)
	{
	case 1:
		radian();
		break;
	case 2:
		degree();
		break;
	case 3:
		cout << "Введите значения x, a, где x - кг конфет, a - цена конфет: ";
		cin >> x >> a;
		sum(x, a);
		break;
	case 4:
		cout << "Введите скорость первого мотоциклиста: ";
		cin >> v1;
		cout << "Введите скорость второго мотоциклиста: ";
		cin >> v2;
		if (v1>=0 and v2>=0) {
			cout << "Введите начальное расстояние между ними: ";
			cin >> S;
			if (S >= 0) {
				cout << "Введите время, которое прошло: ";
				cin >> t;
				distances = (float)(abs(v1 - v2) * t + S);
				cout << "Расстояние чере " << t << " часов будет равно " << distances << endl;
			}
			else {
				cout << "Расстояние не может быть отрицательным!!!";
			}
		}
		else {
			cout << "Ошибка, скорость не может быть отрицательной!!!";
		}	
		break;
	case 5:
		cout << "Найти x из уравения A·x + B = 0, где a != 0\n" << "Введите A:";
		cin >> a;
		if (a!=0) {
			cout << "Введите B:";
			cin >> b;
			x = (float)(-b) / a;
			cout << "Из уравнения x = " << x << endl;
		}
		else {
			cout << "Деление на 0 запрещено!!!";
		}
		break;
	case 6:
		cout << "Введите коэффициенты:\n" << "Введите A1: ";
		cin >> A1;
		cout << "Введите A2: ";
		cin >> A2;
		cout << "Введите B1: ";
		cin >> B1;
		cout << "Введите B2: ";
		cin >> B2;
		cout << "Введите C1: ";
		cin >> C1;
		cout << "Введите C2: ";
		cin >> C2;
		det = A1 * B2 - B1 * A2;
		detX = C1 * B2 - B1 * C2;
		detY = A1 * C2 - A2 * C1;
		x = (float)(detX / det);
		y = (float)(detY / det);
		cout << "Значение x = " << (float)x << "\nЗначение y = " << (float)y << endl;
		break;
	default:
		cout << "Хватит сюда уже нажимать :\\";
		break;
	}
}

void radian() {
	int a;
	float b;
	do
	{
		cout << "Введите значения градуса a: ";
		cin >> a;
		if (a > 0 and a < 360) {
			b = (float)a / 180;
			cout << "a градусов = " << (float)b << "P радиан" << endl;
		}
		else {
			cout << "Ошибка, введите а в диапозоне 0 < a < 360:\n";
		}
	} while (a <= 0 or a >= 360);
}

void degree() {
	float a;
	int b;
	do
	{
		cout << "Введите a радиан: ";
		cin >> a;
		if (a > 0 and a < 2) {
			b = (float)a * 180;
			cout << "a радиан = " << b << " градусов" << endl;
		}
		else {
			cout << "Ошибка, введите a в диапозоне 0 < a < 2:\n";
		}
	} while (a <= 0 or a >= 2);

}

void sum(float a, float b) {
	float s, y;
	s = (float)b / a;
	cout << "Введите y - кг конфет: ";
	cin >> y;
	y = s * y;
	cout << "1 кг конфет стоит - " << s << " руб.\n" << "y кг конфет стоит - " << y << " руб." << endl;
}