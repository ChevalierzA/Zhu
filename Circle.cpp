#pragma once
#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Ellilpse()
{
}
Circle::Circle(const double& r)
{
	this->setRadius(r);
}

Circle::Circle(const Circle& c)
{
	this->setRadius(c.getRadius());
}

Circle Circle::operator = (const Circle& c)
{
	this->setRadius(c.getRadius());
	return *this;
}

double Circle::getRadius() const
{
	double r = this->Ellilpse::getMinorAxis();
	return r;
}

void Circle::setMajorAxis(const double& r)
{
	this->setRadius(r);
}

void Circle::setMinorAxis(const double& r)
{
	this->setRadius(r);
}

void Circle::setRadius(const double& r) 
{
	this->Ellilpse::setMajorAxis(r);
	this->Ellilpse::setMinorAxis(r);
}

ostream& operator << (ostream& outs, const Circle& e)
{
	outs << "The radius = " << e.getRadius() << endl;
	outs << "And Area of Circle = " << e.getArea() << " , Circumference of Circle = " << e.getCircumference() << endl;
	return outs;
}

istream& operator >> (istream& ins, Circle& e)
{
	double r;
	cout << "Enter the radius: " ;
	ins >> r;
	e.setRadius(r);
	return ins;
}
