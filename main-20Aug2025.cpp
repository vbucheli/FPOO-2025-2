/**
 * @file main.cpp
 * @brief Un programa que computa el factorial de un número
 * 
 * @details ingresa un nùmero y calcula el factorial de dicho nùmero
 * @author [Victor Bucheli]
 * @mail [victor.bucheli@correounivalle.edu.co]
 * @date 2025-08-20
 * @version 1.0
 *
 * @comentario:
 */

#include <iostream>
using namespace std;

int suma(int a, int b){
    return a+b;
}

double factorialFuncionVer0(int n){
  int factorial=1;
  int iteraciones = n;
  for(int i=0; i<iteraciones; i++){
    factorial = factorial *n;
    n=n-1;
  }
  return factorial;
}

double factorialFuncionVer1(int n){
  int factorial=1;
  for(int i=0; i<n; i++){
    factorial = factorial * n;
    n=n-1;
  }
  return factorial;
}

double factorialFuncionVer2(int n)
{
int i=1;
int factorial=1;
  while (i<=n)
  {
  factorial = factorial * i;
  i+=1; 
  }
return factorial;
}


int main() 
{
  int factorial=0;
  cout << suma(1,1)<< endl;
  cout<<"Ingrese el número del factorial que desea calcular: ";
  cin>>factorial;
  cout<<factorialFuncionVer2(factorial)<<endl;
  return 0;
}
