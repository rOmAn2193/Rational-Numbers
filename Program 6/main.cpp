#include "rationalnums.h"


void main ()
{
	ifstream inf("Data.dat");
    ofstream outf("Output.out");
    RationalNums x,y,z;
	while (!inf.eof())
	{
		
		inf >> x >> y;
		outf << x ;
		outf << ' ';
		outf << y << endl;
		outf << "Here is z = x+y : ";
		z = x+y;
		outf << z << endl;
		outf << "Here is z = x-y : ";
		z = x-y;
		outf << z << endl;
		outf << "Here is z = x*y : ";
		z = x*y;
		outf << z << endl;
		outf << "Here is z = x/y : ";
		z = x/y;
		outf << z << endl;
		outf<<endl;
	}
}


