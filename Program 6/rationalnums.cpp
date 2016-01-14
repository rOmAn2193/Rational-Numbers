#include "rationalnums.h"

RationalNums::RationalNums()
{
    n = 0;
	d = 1;
}

RationalNums::RationalNums(int num, int den)
{
    n = num;
    d = den;
}

void RationalNums::printem(ofstream &outf)
{
	outf << n << "/" << d << endl;
}

int RationalNums::getn()
{
	return n;
}

int RationalNums::getd()
{
	return d;
}

void RationalNums::setn(int num)
{
	n = num;
}

void RationalNums::setd(int den)
{
	d = den;
}


RationalNums operator+(RationalNums x, RationalNums y)
{
	RationalNums ans;
	ans.d = x.d*y.d;
	ans.n = (x.n*y.d + y.n*x.d);
	return ans;
}
RationalNums operator-(RationalNums x, RationalNums y)
{
    RationalNums ans;
    ans.d = x.getd()*y.getd();
    ans.n = (x.getn()*y.getd() - x.getd()*y.getn());
    return ans;
}
RationalNums operator*(RationalNums x, RationalNums y)
{
    RationalNums ans;
    ans.d = x.d*y.d;
    ans.n = x.n*y.n;
    return ans;
}
RationalNums operator/(RationalNums x, RationalNums y)
{
    RationalNums ans;
    ans.d = x.d*y.n;
    ans.n = x.n*y.d;
    return ans;
}

ofstream& operator <<(ofstream &outf, RationalNums& x)
{
	x.reducem();
	if(x.d==0)
	{
		outf << "undefined";
	}
	else if (x.n==0)
	{
		outf << 0;
	}
	else 
	outf << x.n << "/" << x.d;
	return outf;
}

ifstream& operator >>(ifstream &inf, RationalNums& x)
{
	char ch;
	inf>> x.n >> ch >> x.d ;
	return inf;
}

void RationalNums::reducem()
{
	int i,small;
    small = min(abs(n),abs(d));
	for (i=small;i>=2;i-=1)
		if ((n% i==0) && (d% i==0))
		{
			n/=i;
			d/=i;
		}
	if (d<0)
	{
		n*=-1;
		d*=-1;
	}
	if (n==0)
	{
		d=1;
	}
}

int RationalNums::min(int num, int den)
{
	if (num<den)
		return num;
	else
		return den;
}