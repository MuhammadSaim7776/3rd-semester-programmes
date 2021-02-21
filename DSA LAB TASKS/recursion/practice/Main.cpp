#include<iostream>
#include<conio.h>
using namespace std;
void print(int n)
{
	if (n == 0)
	{
		cout << n;
	}
	else
	{
		cout << n;
		print(n - 1);
		
	}
	
}
int arraysum(int*arr, int n)
{
	if (n == 1)
	{
		return arr[0];
	}
	else
	{
		return arraysum(arr, n - 1) + arr[n - 1];
	}
}
int fict(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*fict(n - 1);
	}
}
void table(int n, int no)
{
	if (no == 1)
	{
		cout << n*no << endl;
	}
	else
	{
		table(n, no - 1);
		cout << n*no << endl;
	}
}
//int twoDsum(int *arr, int n, int m)
//{
//	if (n == 0 && m == 0)
//	{
//		return arr[0][0];
//	}
//}
int maxelement(int*a, int nb)
{
	int n = 0;
	if (nb == 1)
	{
		return a[0];
	}
	else
	{
		n = maxelement(a, nb - 1);
		if (n > a[nb - 1])
		{
			return n;
		}
		else
		{
			return  a[nb - 1];
		}
	}
}
void swap(int*b, int i, int j)
{
	int m = b[i];
	b[i] = b[j];
	b[j] = m;
}
void reverse(int*arr, int i, int j)
{
	if (i > j || i == j)
	{
		return;
	}
	else
	{
		swap(arr, i, j);
		reverse(arr, i + 1, j - 1);
	}
}
int product(int n, int m)
{
	if (m == 1)
	{
		return n;
	}
	else
	{
		return n + product(n, m - 1);
	}
}
void main()
{
	
	/*int arr[5] = { 10, 20, 30, 40, 50 };
	reverse(arr,0,4);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}*/
	cout << product(3, 9);
	_getch();
}