//Класс массив
//ПЕРЕГРУЖЕНЫ НЕ ВСЕ ОПЕРАТОРЫ
#include <iostream>
using namespace std;

struct Bad_Index
{
	int k;
	Bad_Index(int index) :k(index) {}
};

struct Bad_Dimensions {};

class Vector
{
	int* p;
	int size;
public:
	Vector()
	{
		size = 10;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = rand() % 9 + 1;
	}
	Vector(const Vector& v)
	{
		size = v.size;
		p = new  int[size];
		for (int i = 0; i < size; i++)
			p[i] = v.p[i];
	}
	Vector(int n) {};
	~Vector() {};
	Vector& operator=(const Vector& p);
	friend Vector operator + (const Vector& v1, const Vector& v2);
	friend Vector operator - (const Vector& v1, const Vector& v2);
	friend Vector operator * (const Vector& v1, const Vector& v2);
	friend Vector operator / (const Vector& v1, const Vector& v2);
	
	friend Vector operator + (int z, Vector p2);
	friend Vector operator + (Vector p1, int z);
	friend Vector operator - (Vector p1, int z);
	friend Vector operator - (int z, Vector p2);
	friend Vector operator * (int z, Vector p2); 
	friend Vector operator * (Vector p1, int z);
	friend Vector operator / (Vector p1, int z);
	friend Vector operator / (int z, Vector p2); //
	
	Vector& operator += (const Vector& p);
	Vector& operator -= (const Vector& p);
	Vector& operator *= (const Vector& p);
	Vector& operator /= (const Vector& p);
	Vector& operator += (int k);
	Vector& operator -= (int k);
	Vector& operator *= (int k);
	Vector& operator /= (int k);
	friend bool operator == (const Vector& p1, const Vector& p2);
	friend bool operator != (const Vector& p1, const Vector& p2);
	friend bool operator >= (const Vector& p1, const Vector& p2);
	friend bool operator <= (const Vector& p1, const Vector& p2);
	friend bool operator > (const Vector& p1, const Vector& p2);
	friend bool operator < (const Vector& p1, const Vector& p2);
	friend Vector operator - (Vector p);
	friend Vector operator + (Vector p);
	Vector operator ++(int);
	Vector& operator ++();
	Vector operator --(int);
	Vector& operator --();
	friend istream& operator>>(istream& in, const Vector& p);
	friend ostream& operator<<(ostream& out, const Vector& p);
};

// Некоторые методы
Vector& Vector::operator= (const Vector& v)
{
	if (this != &v)
	{
		size = v.size;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = v.p[i];
	}
	return *this;
}
Vector& Vector::operator +=(const Vector& v)
{
	if (v.size != size)
		throw Bad_Dimensions();
	for (int i = 0; i < size; i++)
		p[i] += v.p[i];
	return *this;
}
Vector& Vector::operator -=(const Vector& v)
{
	if (v.size != size)
		throw Bad_Dimensions();
	for (int i = 0; i < size; i++)
		p[i] -= v.p[i];
	return *this;
}
Vector& Vector::operator *=(const Vector& v)
{
	if (v.size != size)
		throw Bad_Dimensions();
	for (int i = 0; i < size; i++)
		p[i] *= v.p[i];
	return *this;
}
Vector& Vector::operator /=(const Vector& v)
{
	if (v.size != size)
		throw Bad_Dimensions();
	for (int i = 0; i < size; i++)
		p[i] /= v.p[i];
	return *this;
}

Vector& Vector::operator *=(int a)
{
	for (int i = 0; i < size; i++)
		p[i] *= a;
	return *this;
}

Vector operator + (const Vector& v1, const Vector& v2)
{
	Vector v(v1);
	v += v2;
	return v;
}
Vector operator - (const Vector& v1, const Vector& v2)
{
	Vector v(v1);
	v -= v2;
	return v;
}
Vector operator * (const Vector& v1, const Vector& v2)
{
	Vector v(v1);
	v *= v2;
	return v;
}
Vector operator / (const Vector& v1, const Vector& v2)
{
	Vector v(v1);
	v /= v2;
	return v;
}

Vector operator * (const Vector& v, int a)
{
	Vector v1(v);
	v1 *= a;
	return v1;
}
Vector operator * (int z, Vector p2)
{
	Vector v1(z);
	v1 *= z;
	return v1;
}
Vector operator / (int z, Vector p2)
{
	Vector v1(z);
	v1 /= z;
	return v1;
}
Vector operator / (Vector p2, int z)
{
	Vector v1(z);
	v1 /= z;
	return v1;
}

ostream& operator<< (ostream& out, const Vector& v)
{
	out << "(" << v.p[0];
	for (int i = 1; i < v.size; i++)
		out << "," << v.p[i];
	out << ")" << endl;
	return out;
}


int main()
{
	try
	{
		//int n, m;
		setlocale(LC_ALL, ".1251");

		Vector A, B, C, D;
		cout << A;
		cout << B;
		//C = A * B + B * 2;
		C = 2 * A - B / 2;
		cout << C;
		D += C;
		cout << D;
		D = C - B / 2;
		cout << D;
		//C = C + D * 5;
	}
	catch (Bad_Index D)
	{
		cout << D.k << " is a bad index" << endl;
	}
	catch (Bad_Dimensions d)
	{
		cout << "Bad dimensions" << endl;
	}
	return 0;
}