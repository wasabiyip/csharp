// TestCLR.cpp : main project file.
#include "stdafx.h"


using namespace System;
using namespace System::Collections ;
using namespace System::Collections::Generic ; 

int main(array<System::String ^> ^args)
{
	int ^ i = gcnew int;
	i = 10;
	double ^ j = gcnew double;
	j = 10.5;
	ArrayList ^ container = gcnew ArrayList;
	container->Add(i);
	container->Add(j);


	Console::WriteLine(i);
    Console::WriteLine(L"Hello World");
    return 0;
}
