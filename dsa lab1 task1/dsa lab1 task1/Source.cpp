           //    BSEF19M011            FAHEEM KHALID
           //            TASK 2 AND 3
#include<iostream>
using namespace std;
class Complex
{
private:
	double real;
	double imagenary;
public:
	Complex()
	{
		real = 0;
		imagenary = 0;
	}
	Complex(double r)
	{
		real = r;
		imagenary = 0;
	}
	Complex(double r,double i)
	{
		real = r;
		imagenary = i;
	}
	Complex(const Complex& c)
	{
		real = c.real;
		imagenary = c.imagenary;
	}
	Complex add(Complex c)
	{
		cout << "Performing add operation" << endl;
		Complex temp;
		temp.real = real + c.real;
		temp.imagenary = imagenary + c.imagenary;
		return temp;
	}
	Complex subtract(Complex c)
	{
		cout << "Performing subtract operation" << endl;
		Complex temp;
		temp.real = real - c.real;
		temp.imagenary = imagenary - c.imagenary;
		return temp;
	}
	Complex multiply(Complex c)
	{
		cout << "Performing multiply operation" << endl;
		Complex temp;
		temp.real = real * c.real;
		temp.imagenary = imagenary * c.imagenary;
		return temp;
	}
	Complex divide(Complex c)
	{
		cout << "Performing division operation" << endl;
		Complex temp;
		temp.real = c.real / real;
		temp.imagenary = c.imagenary / imagenary;
		return temp;
	}
	Complex conjugate()
	{
		cout << "Performing conjucate operation" << endl;
		real = real;
		imagenary = -imagenary;
		return *this;
	}
	void print()
	{
		if (imagenary > 0)
		{
			cout << real << "+" << imagenary << "i" << endl;
		}
		else
		{
			cout << real << imagenary << "i" << endl;
		}
	}
	void setReal(double rr)
	{
		real = rr;
	}
	void setImag(double ii)
	{
		imagenary = ii;
	}
	double getReal()
	{
		return real;
	}
	double getImag()
	{
		return imagenary;
	}
	friend Complex operator -(Complex ,Complex);
	friend Complex operator +(Complex, Complex);
};
Complex operator -(Complex c1,Complex c2)
{
	cout << "after performing operator overloading of - " << endl;
	return Complex(c1.real - c2.real, c1.imagenary - c2.imagenary);
}
Complex operator +(Complex c1, Complex c2)
{
	cout << "after performing operator overloading of + " << endl;
	return Complex(c1.real + c2.real, c1.imagenary + c2.imagenary);
}


int main()
{
	Complex c1(22,33.5);
	cout << "1st complex number = " << endl;
	c1.print();
	cout << endl;
	Complex c2(3,4.5);
	cout << "2nd complex number = " << endl;
	c2.print();
	cout << endl;
	Complex c3;
	c3= c1.add(c2);
	 c3.print();
	 cout << endl;
	c3= c1.subtract(c2);
	 c3.print();
	 cout << endl;
	 c3 = c1.multiply(c2);
	 c3.print();
	 cout << endl;
	 c3 = c1.divide(c2);
	 c3.print();
	 cout << endl;
	
	 c3 = c1 + c2;
	 c3.print();
	 cout << endl;
	 c3 = c1 - c2;
	 c3.print();
	 cout << endl;
	 cout << "After performing conjugate on 2nd complex number" << endl;
	 c2.conjugate();
	 c2.print();


}