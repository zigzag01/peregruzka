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

	friend Vector operator + (const Vector& v1, const Vector& v2);
	friend Vector operator - (const Vector& v1, const Vector& v2);
	friend Vector operator * (const Vector& v1, const Vector& v2);
	friend Vector operator / (const Vector& v1, const Vector& v2);

	Vector& operator += (const Vector& p);
	Vector& operator -= (const Vector& p);
	Vector& operator *= (const Vector& p);
	Vector& operator /= (const Vector& p);

};

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