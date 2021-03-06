#include <algorithm>
#include <iostream>
#include "ordenador.h" //esto también tiene que llamarse igual

using namespace std;

int *A,*B;
int i,m,n,j,N;
bool operacionesExcedidas;
int valorGuardado;

int guardar(int indice) //siguiente guarda el valor en indice
{
    if(indice<0 || indice >=n)
        return -1;
    valorGuardado=B[indice];
	return valorGuardado;
}

int obtener(int indice)
{
	if(indice<0 || indice>=n) //indice no válido
		return -1;
	return B[indice];
}

bool desplazar(int indice)
{
	if(indice<0 || indice>=n-1 || m<0) //indice no válido, número de operaciones excedidas
		{
		if(m<0)
			operacionesExcedidas=true;
		return 0;
		}
	B[indice+1]=B[indice];
	m--;
	return 1;
}

void insertar(int indice)
{
	if(N<0)
		{
		operacionesExcedidas=true;
		return;
		}
	if(indice<0 || indice>=n)
		return;
	N--;
	B[indice]=valorGuardado;
	valorGuardado=-1;
}

int main()
{
	valorGuardado=-1;
	cin>>n;
	N=n;
	A=(int*)malloc(n*sizeof(int));
	B=(int*)malloc(n*sizeof(int));
	for(int x=0;x<n;x++)
		{
		cin>>*(A+x);
		B[x]=A[x];
		for(int y=x-1;y>=0;y--) //si hay dos números iguales no cuenta el m
			if(A[y]>A[x])
				m++;
		}
	if(n<=100) //primeros 40 puntos
		m=n*n;
	//Operación del alumno
	ordenar(n);
	if(operacionesExcedidas)
		{
		cout<<"0\n";
		return 0;
		}
	sort(A,A+n);
	for(int x=0;x<n;x++)
		{
		cout<<A[x]<<" "<<B[x]<<endl;
		if(A[x]!=B[x])
			{
			cout<<"0\n";
			return 0;
			}
		}
	cout<<"1\n";
	return 0;
}
