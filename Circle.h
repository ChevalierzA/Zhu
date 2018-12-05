#include "stdafx.h"
#include "Ellipse.h"

class Circle : public Ellilpse
{
private:
public:
	Circle();
	Circle(const double& r);
	Circle(const Circle& c);
	Circle operator = (const Circle& c);
	double getRadius() const;
	void setRadius(const double& r);
	void setMinorAxis(const double& r);
	void setMajorAxis(const double& r);
	friend ostream& operator << (ostream& outs, const Circle& e);
	friend istream& operator >> (istream& ins, Circle& e);
};