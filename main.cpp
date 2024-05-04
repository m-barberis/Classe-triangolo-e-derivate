#include <stdio.h>
#include "CTriangle.h"
#include "CIsosceles.h"
#include "CEquilateral.h"
#include<iostream>

int main() {
	Isosceles I;
	I.Dump();
	I.SetSide(5.);
	I.Dump();
	I.SetBase(8.);
	I.Dump();
	cout << "Il triangolo I isoscele ha area: " << I.GetArea() << endl;
	Isosceles H(1., 4.); //Triangolo con dimensioni non valide
	H.Dump();
	Isosceles J(I);
	J.Dump();
	Equilateral E(8.);
	E.Dump();
	cout << "Il triangolo E equilatero ha area: " << E.GetArea() << endl;
	cout << endl;
}