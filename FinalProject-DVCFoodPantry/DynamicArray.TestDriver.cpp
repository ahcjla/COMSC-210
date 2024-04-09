// Programmer Name: Alex Kogan
// Programmer ID: 1865080
// Programmer 2 Name: Rachael Karim
// Programmer 2 ID: 0136068
// Programmer 3 Name: Aiman Al Sharai
// Programmer 3 ID: 1839435
// Programmer 4 Name: Aurelia Kisanaga
// Programmer 4 ID: 1960007
// Programmer 5 Name: Steven Dominic Sahar
// Programmer 5 ID: 1855840
#include <iostream>
#include <string>
using namespace std;


#include "DynamicArray.h"
#include "DynamicArray.h" // test for if-else correctness

#include <cassert>



void testIntStaticArray( ); // test driver for DynamicArray<int, int>
void testDoubleDynamicArray( ); // test driver for DynamicArray<double, int>
void testStrDynamicArray( ); // test driver for DynamicArray<string, int>
void testCharDynamicArray( ); // test driver for DynamicArray<char, int>


int DynamicArrayTestMain( )
{
  // run tests for DynamicArray<int, int>
  testIntStaticArray( );

  // run tests for DynamicArray<string, int>
  testStrDynamicArray();

  // run tests for DynamicArray<float, int>
  testDoubleDynamicArray();

  // run tests for DynamicArray<char, int>
  testCharDynamicArray();

  return 0;
}



void testIntStaticArray( )
{
  DynamicArray<int> arrayObj(88);

  // Array<int, int>
  cout << "\nTesting DynamicArray<int>\n";

  // Array::capacity
  cout << "Testing DynamicArray<int>::capacity\n";
  cout << "EXPECTED: 88\n";
  cout << "ACTUAL: " << arrayObj.capacity() << endl;
  assert(88 == arrayObj.capacity());

  // DynamicArray::operator[ ] getter
  cout << "\nTesting DynamicArray<int>::operator[ ] getter \n";
  const DynamicArray<int> arrayObjB(arrayObj); // const array to test the getter version of the operator[ ]
  for (int index = 0; index < arrayObjB.capacity(); index++)
  {
    assert(arrayObj[index] == arrayObjB[index]);
  }

  // DynamicArray::operator[ ] setter
  cout << "\nTesting the DynamicArray<int>::operator[ ] setter \n";
  arrayObj[1] = 1234;
  arrayObj[3] = 789;
  arrayObj[90] = 90; // Out-of-Range expands array's capacity by 2x
  cout << "\nTesting DynamicArray<int>::operator[ ] setter\n";
  cout << "EXPECTED: 1234 for arrayFlo[1]\n";
  cout << "ACTUAL: " << arrayObj[1] << endl;
  assert(1234 == arrayObj[1]);
  cout << "EXPECTED: 789 for arrayFlo[3]\n";
  cout << "ACTUAL: " << arrayObj[3] << endl;
  assert(789 == arrayObj[3]);
  cout << "\nTesting DynamicArray<int>::operator[ ] setter\n";
  cout << "EXPECTED: 90 for arrayFlo[90]\n";
  cout << "ACTUAL: " << arrayObj[90] << endl;
  assert(90 == arrayObj[90]);
  arrayObj[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << arrayObj[-1000] << endl;
  cout << "Testing DynamicArray<int>::capacity (extended)\n";
  cout << "EXPECTED: 180\n";
  cout << "ACTUAL: " << arrayObj.capacity() << endl;
  assert(180 == arrayObj.capacity());
  assert(1234 == arrayObj[1]);
  assert(789 == arrayObj[3]);
  assert(123123 != arrayObj[arrayObj.capacity() - 1]); // Boundary-Range check
  assert(123123 != arrayObj[0]); // Lower-Range check

  // object copy test
  cout << "\nObject copy test\n";
  DynamicArray<int> d = arrayObj; // making a copy
  assert(arrayObj.capacity() == d.capacity());
  for (int index = 0; index < arrayObj.capacity(); index++)
  {
    assert(arrayObj[index] == d[index]); // uses the setter version for both arrayFlo and d
  }

  // change the content in the original array to verify it's not a shallow copy
  for (int index = 0; index < arrayObj.capacity(); index++)
  {
    arrayObj[index]++;
    assert(arrayObj[index] != d[index]);
  }

  // object assignment test
  cout << "\nObject assignment test\n";
  DynamicArray<int> o;
  cout << o.capacity( ) << endl;
  o = arrayObjB;
  cout << o.capacity( ) << endl;
  cout << arrayObjB.capacity( ) << endl;
  assert(arrayObj.capacity( ) == o.capacity( ));

  for (int i = 0; i < arrayObj.capacity(); i++)
    assert(arrayObj[i] == o[i]);
  // change the content in the original array to verify it's not a shallow copy
  for (int i = 0; i < arrayObj.capacity(); i++)
  {
    arrayObj[i]++;
    assert(arrayObj[i] != o[i]);
  }
  
  cout << "END OF TEST FOR DynamicArray<int>\n";
}

void testDoubleDynamicArray( )
{
  DynamicArray<double> arrayflo(100);

  // StaticArray<float, int>
  cout << "\nTesting DynamicArray<double>\n";

  // Array::capacity
  cout << "Testing DynamicArray<double>::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << arrayflo.capacity() << endl;
  assert(100 == arrayflo.capacity());

  // Array::operator[ ] getter
  cout << "\nTesting DynamicArray<double>::operator[ ] getter \n";
  const DynamicArray<double> arrayfloB = arrayflo; // const array to test the getter version of the operator[ ]
  for (int index = 0; index < arrayfloB.capacity(); index++)
  {
    assert(arrayflo[index] == arrayfloB[index]);
  }

  // DynamicArray<double>::operator[ ] setter
  cout << "\nTesting the DynamicArray<double>::operator[ ] setter \n";
  arrayflo[1] = 1234.3;
  arrayflo[3] = 789.8;
  arrayflo[120] = 120.22; // Out-of-Range expands array's capacity by 2x
  cout << "\nTesting DynamicArray<double>::operator[ ] setter\n";
  cout << "EXPECTED: 1234.3 for arrayFlo[1]\n";
  cout << "ACTUAL: " << arrayflo[1] << endl;
  assert(1234.3 == arrayflo[1]);
  cout << "EXPECTED: 789.8 for arrayFlo[3]\n";
  cout << "ACTUAL: " << arrayflo[3] << endl;
  assert(789.8 == arrayflo[3]);
  cout << "EXPECTED: 120.22 for arrayFlo[120]\n";
  cout << "ACTUAL: " << arrayflo[120] << endl;
  assert(789.8 == arrayflo[3]);
  arrayflo[-1000] = 123123.76;
  cout << "EXPECTED: 123123.76 for a[-1000]\n";
  cout << "ACTUAL: " << arrayflo[-1000] << endl;

  assert(1234.3 == arrayflo[1]);
  assert(789.8 == arrayflo[3]);
  assert(123123.76 != arrayflo[arrayflo.capacity() - 1]); // Boundary-Range check
  assert(123123.76 != arrayflo[0]); // Lower-Range check
  
  // object copy test
  cout << "\nObject copy test\n";
  DynamicArray<double> d = arrayflo; // making a copy
  assert(arrayflo.capacity() == d.capacity());
  for (int index = 0; index < arrayflo.capacity(); index++)
  {
    assert(arrayflo[index] == d[index]); // uses the setter version for both arrayFlo and d
  }

  // change the content in the original array to verify it's not a shallow copy
  for (int index = 0; index < arrayflo.capacity(); index++)
  {
    arrayflo[index]++;
    assert(arrayflo[index] != d[index]);
  }

  // object assignment test
  cout << "\nObject assignment test\n";
  DynamicArray<double> o;
  cout << o.capacity( ) << endl;
  o = arrayflo;
  cout << o.capacity( ) << endl;
  cout << arrayflo.capacity( ) << endl;
  assert(arrayflo.capacity( ) == o.capacity( ));

  for (int i = 0; i < arrayflo.capacity(); i++)
    assert(arrayflo[i] == o[i]);
  // change the content in the original array to verify it's not a shallow copy
  for (int i = 0; i < arrayflo.capacity(); i++)
  {
    arrayflo[i]++;
    assert(arrayflo[i] != o[i]);
  }
  cout << "END OF TEST FOR DynamicArray<double>\n";
}

void testStrDynamicArray( )
{
  DynamicArray<string> strArray;

  // DynamicArray<string>
  cout << "\nTesting for DynamicArray<string>\n";

  // , int<string>::capacity( )
  cout << "Testing DynamicArray<string>::capacity( )\n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << strArray.capacity( ) << endl;
  assert(2 == strArray.capacity( ));

  // DynamicArray<string, int>::operator[ ] getter
  cout << "Testing for , DynamicArray<string>::operator[ ] getter\n";
  const DynamicArray<string> strArrayB = strArray; // const array to test the getter version of the operator[ ]
  for (int index = 0; index < strArrayB.capacity( ); index++)
  {
    assert(strArrayB[index] == strArray[index]);
  }

  // DynamicArray<string>::operator[ ] setter
  cout << "Testing DynamicArray<string>::operator[ ] setter\n";
  strArray[0] = "Aiman Al Sharai"; // value insertion test
  strArray[1] = "1839435"; // value insertion test
  strArray[30] = "Expanding"; // Out-of-Range expands array's capacity by 2x

  cout << "Testing StaticArray<string, int>::operator[ ] setter\n";
  cout << "EXPECTED: Aiman Al Sharai for strArray[0]\n";
  cout << "ACTUAL: " << strArray[0] << endl;
  assert("Aiman Al Sharai" == strArray[0]);
  cout << "EXPECTED: 1839435 for strArray[1]\n";
  cout << "ACTUAL: " << strArray[1] << endl;
  assert("1839435" == strArray[1]);
  cout << "EXPECTED: Expanding for strArray[30]\n";
  cout << "ACTUAL: " << strArray[30] << endl;
  assert("Expanding" == strArray[30]);
  strArray[-78945] = "Out of range"; // Out-of-Range test
  cout << "EXPECTED: Out of range\n";
  cout << "ACTUAL: " << strArray[-78945] << endl;
  assert("Out of range" == strArray[-78945]);

  assert("Aiman Al Sharai" == strArray[0]);
  assert("1839435" == strArray[1]);
  assert("Out of range" != strArray[strArray.capacity() - 1]); // Upper Boundary-Range check
  assert("Out of range" != strArray[0]); // Lower Boundary-Range check
  cout << "END OF TEST FOR DynamicArray<string>\n";
}

void testCharDynamicArray( )
{
  DynamicArray<char> charArray(100);

  // DynamicArray<char>
  cout << "\nTesting for DynamicArray<char>\n";

  // DynamicArray<char>::capacity( )
  cout << "Testing DynamicArray<char>::capacity( )\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << charArray.capacity( ) << endl;
  assert(100 == charArray.capacity( ));

  // DynamicArray<char::operator[ ] getter
  cout << "Testing for DynamicArray<char>::operator[ ] getter\n";
  const DynamicArray<char> charArrayB = charArray; // const array to test the getter version of the operator[ ]
  for (int index = 0; index < charArrayB.capacity( ); index++)
  {
    assert(charArrayB[index] == charArray[index]);
  }

  // DynamicArray<char>::operator[ ] setter
  cout << "Testing DynamicArray<char>::operator[ ] setter\n";
  charArray[1] = 'A'; // value insertion test
  charArray[3] = '1'; // value insertion test
  charArray[200] = 'E'; // Out-of-Range expands array's capacity by 2x

  cout << "Testing StaticArray<char, int>::operator[ ] setter\n";
  cout << "EXPECTED: A for charArray[1]\n";
  cout << "ACTUAL: " << charArray[1] << endl;
  assert('A' == charArray[1]);
  cout << "EXPECTED: 1 for charArray[3]\n";
  cout << "ACTUAL: " << charArray[3] << endl;
  assert('1' == charArray[3]);
  cout << "EXPECTED: E for charArray[200]\n";
  cout << "ACTUAL: " << charArray[200] << endl;
  assert('E' == charArray[200]);
  charArray[-78945] = 'N'; // Out-of-Range test
  cout << "EXPECTED: N for charArray[-78945]\n";
  cout << "ACTUAL: " << charArray[-78945] << endl;
  assert('N' == charArray[-78945]);

  assert('A' == charArray[1]);
  assert('1' == charArray[3]);
  assert('N' != charArray[charArray.capacity() - 1]); // Upper Boundary-Range check
  assert('N' != charArray[0]); // Lower Boundary-Range check
  cout << "END OF TEST FOR DynamicArray<char>\n";
}


