#pragma once
#include <iostream>
#include <cmath>
#include <conio.h>

class figure {//������� ����������� ����� ������
protected:
    double r1, r2, r3;
public:
    figure() {
        r1 = r2 = r3 = 0;
    }
    virtual double GetArea() = 0;//����� ��� ���������� ������� ������
    virtual double GetVolume() = 0;//����� ��� ���������� ������ ������
};

class Sphere : public figure {//����� ��������� �����
public:
    Sphere(double r) {
        r1 = r;
    }
    double GetArea();
    double GetVolume();
};

class Tor : public figure {//����� ��������� ���
public:
    Tor(double r1, double r2) {
        this->r1 = r1;
        this->r2 = r2;
    }
    double GetArea();
    double GetVolume();
};

class Elipsoid : public figure {//����� ��������� ���������
public:
    Elipsoid(double r1, double r2, double r3) {
        this->r1 = r1;
        this->r2 = r2;
        this->r3 = r3;
    }
    double GetArea();
    double GetVolume();
};

void interface();
void Print(figure*, std::string);