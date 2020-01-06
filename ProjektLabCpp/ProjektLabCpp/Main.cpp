#include<iostream>
#include"Napis.h"

using namespace std;


int main()
{
	Napis napis;


	napis.Ustaw("aaaa");
	Napis napis2;
	napis2.Ustaw("bbb");
	cout<<napis.SprawdzNapis(napis2.Zwroc());

}