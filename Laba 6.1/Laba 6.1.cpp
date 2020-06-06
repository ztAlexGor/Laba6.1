#include "Header.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    interface();
}




void interface()     {
    cout << "Горобец Александр студент гр. ИП-96\nВариант №5 уровень сложность: Б\n";
    _getch();
    system("cls");
    char p;
    bool u = true;
    double r1, r2, r3;

    figure* ptr;//указатель на базовый класс

    while (u) {
        cout << "Нажмите 0 если хотите закончить программу\nНажмите 1 если хотите создать сферу\nНажмите 2 если хотите создать тор\nНажмите 3 если хотите создать эллипсоид" << endl;
        p = _getch();
        system("cls");
        if (p == '0')u = false;
        else if (p == '1') {
            cout << "Введите радиус сферы" << endl;
            cin >> r1;
            ptr = new Sphere(r1);
            Print(ptr, "сферы: ");
        }
        else if (p == '2') {
            cout << "Введите радиус кольца тора" << endl;
            cin >> r1;
            cout << "\nВведите радиус трубы тора" << endl;
            cin >> r2;
            ptr = new Tor(r1, r2);
            Print(ptr, "тора: ");
        }
        else if (p == '3') {
            cout << "Введите радиус 1" << endl;
            cin >> r1;
            cout << "\nВведите радиус 2" << endl;
            cin >> r2;
            cout << "\nВведите радиус 3" << endl;
            cin >> r3;
            ptr = new Elipsoid(r1, r2, r3);
            Print(ptr, "эллипсоида: ");
        }
    }
}

void Print(figure* ptr, string s) {
    cout << "Площадь "<< s << ptr->GetArea() << "\tОбъём " << s << ptr->GetVolume() << endl << endl;
}

double Sphere::GetArea(){//Метод класса сфера для нахождения площади фигуры
    return 4.0 * 3.141592 * r1 * r1;
}

double Sphere::GetVolume(){//Метод класса сфера для нахождения объёма фигуры
    return 4.0 / 3.0 * 3.141592 * r1 * r1 * r1;
}

double Tor::GetArea() {//Метод класса тор для нахождения площади фигуры
    return 4.0 * 3.141592 * 3.141592 * r1 * r2;
}

double Tor::GetVolume() {//Метод класса тор для нахождения объёма фигуры
    return 2.0 * 3.141592 * 3.141592 * r2 * r1 * r1;
}

double Elipsoid::GetArea(){//Метод класса эллипсоид для нахождения площади фигуры
    double p1 = pow(r1 * r2, 1.6075);
    double p2 = pow(r1 * r3, 1.6075);
    double p3 = pow(r3 * r2, 1.6075);
    double v = 4.0 * 3.141592 * pow((p1 + p2 + p3)/3, 0.62208);
    return v;
}

double Elipsoid::GetVolume(){//Метод класса эллипсоид для нахождения объёма фигуры
    return 4.0 / 3.0 * 3.141592 * r1 * r2 * r3;
}
