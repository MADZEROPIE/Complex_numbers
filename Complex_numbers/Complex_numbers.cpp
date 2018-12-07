#include "pch.h"
#include <iostream>
#include <locale.h>


using namespace std;

class ComplexNum
{
public:
	ComplexNum();
	ComplexNum (double Re,double Im);
	~ComplexNum();
	ComplexNum& operator +(ComplexNum& a);
	ComplexNum& operator -(ComplexNum& a);
	ComplexNum& operator *(ComplexNum& a);
	ComplexNum& operator /(ComplexNum& a);
	ComplexNum& operator ^  (double a);
	ComplexNum& operator ^  (int a);
	void print_num();
	void set_num(double Re, double Im);

private:
	double Re;
	double Im;
	double modulus;
};

ComplexNum::ComplexNum()
{
	Re = 0;
	Im = 0;
	modulus = 0;
}

ComplexNum::ComplexNum(double Re, double Im)
{
	this->Re = Re;
	this->Im = Im;
	this->modulus = pow(Re*Re + Im * Im, 0.5);
}

ComplexNum::~ComplexNum()
{
}

ComplexNum & ComplexNum::operator +(ComplexNum &a)
{
	ComplexNum res (this->Re + a.Re, this->Im + a.Im);
	return res;
}

ComplexNum & ComplexNum::operator-(ComplexNum & a)
{
	ComplexNum res(this->Re - a.Re, this->Im - a.Im);
	return res;
}

ComplexNum & ComplexNum::operator*(ComplexNum & a)
{
	ComplexNum res(this->Re * a.Re - this->Im * a.Im, this->Re *a.Im+this->Im*a.Re);
	return res;
}

ComplexNum & ComplexNum::operator/(ComplexNum & a)
{
	ComplexNum res;
	res.Re = (this->Re * a.Re + this->Im * a.Im) / (a.Re * a.Re + a.Im*a.Im);
	res.Im = (a.Re*this->Im - this->Re*a.Im) / (a.Re * a.Re + a.Im*a.Im);
	return res;
}

ComplexNum & ComplexNum::operator^(double a)
{
	ComplexNum res;
	//TODO: Realize Exponentiation
	return res;
}

ComplexNum & ComplexNum::operator^(int n)
{
	
	if (!n && !(this->Im) && !(this->Re)) {
		cout<<"I don't know what's going on here"<<endl;
		ComplexNum res(1,0);
		return res;
	}
	else if (!n) {
		ComplexNum res(1, 0);
		return res;
	}
	
	if (n < 0) {
		ComplexNum tmp(this->Re, this->Im);
		ComplexNum tmp2(1, 0);
		ComplexNum tmp3(tmp ^ (-n));
		ComplexNum res(tmp2 / tmp3);
		return res;
	}
	ComplexNum res(this->Re, this->Im);
	for (int i = 1; i < n; i++) {
		double tmp = res.Re;
		res.Re = this->Re * res.Re - this->Im * res.Im;
		res.Im = this->Re *res.Im + this->Im*tmp;
	}
	res.modulus= pow(Re*Re + Im * Im, 0.5);
	return res;
}

void ComplexNum::print_num()
{
	printf("%lf+(%lf)i\n", this->Re, this->Im);
}

void ComplexNum::set_num(double Re, double Im)
{
	this->Re = Re;
	this->Im = Im;
	this->modulus = pow(Re*Re + Im * Im, 0.5);
}




int main()
{
	setlocale(LC_CTYPE, "rus");
	ComplexNum a(-2, 1);
	ComplexNum b(1, -1);
	ComplexNum tmp(1, 0);
	ComplexNum c;
	cout << "Число a ";
	a.print_num();
	cout << "Число b ";
	b.print_num();
	c = a + b;
	cout << "Результат сложения a и b ";
	c.print_num();
	c = a - b;
	cout << "Результат вычитания b из a ";
	c.print_num();
	c = a *a;
	cout << "Квадрат a ";
	c.print_num();
	c = a ^ 2;
	cout << "Квадрат a ";
	c.print_num();
	c = tmp / a;
	cout << "Обратный к a ";
	c.print_num();
	c = a ^ (-1);
	cout << "Обратный к a ";
	c.print_num();
	c = a * b;
	cout << "Результат умножения a и b ";
	c.print_num();
	c = a / b;
	cout << "Результат деления a на b ";
	c.print_num();
	c = a ^ 1;
	cout << " a ";
	c.print_num();
	c = a ^ (-1);
	cout << "Обратный к a ";
	c.print_num();
}
