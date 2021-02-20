//#include<iostream>
//#include<conio.h>
//#include<string>
//using namespace std;
//class intArray
//{
//private:
//	int size;
//	int *ptr;
//public:
//	intArray(int Size)
//	{
//		size = Size;
//		ptr = new int[size];
//	}
//
//	void setvalues(int index, int value)
//	{
//		ptr[index] = value;
//	}
//	void insertAtBegining(int value)
//	{
//		int *newptr = ptr;
//		size = size + 1;
//		int *newarray = new int[size];
//		newarray[0] = value;
//		for (int i = 0; i < size; i++)
//		{
//			newarray[i + 1] = ptr[i];
//		}
//		ptr = newarray;
//		delete[]newptr;
//	}
//	void insertAtEnd(int v)
//	{
//		int *newptr = ptr;
//		size = size + 1;
//		int *newarray = new int[size];
//		for (int i = 0; i < size-1; i++)
//		{
//			newarray[i] = ptr[i];
//		}
//		newarray[size-1] = v;
//		ptr = newarray;
//		delete[]newptr;
//	}
//	void updateData(int pval, int nval)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] == pval)
//			{
//				ptr[i] = nval;
//			}
//		}
//	}
//	void remove(int value)
//	{
//		int*newptr = ptr;
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] == value)
//			{
//				while (i < size)
//				{
//					ptr[i] = ptr[i + 1];
//					i++;
//				}
//				
//			}
//		}
//		size = size - 1;
//		int*newArray = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			newArray[i] = ptr[i];
//		}
//		ptr = newArray;
//		delete[]newptr;
//	}
//	void display()
//	{
//		cout << "The numbers in th array are\n";
//		for (int i = 0; i < size; i++)
//		{
//			cout << ptr[i] << "\t";
//		}
//		cout << endl;
//	}
//	void searchvalue(int val)
//	{
//		bool status = false;
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] == val)
//			{
//				cout << "Your data is present at " << i + 1 << " index\n";
//				status = true;
//			}
//		}
//		if (status == false)
//		{
//			cout << "Data not found\n";
//		}
//	}
//	int getsize()
//	{
//		return size;
//	}
//	bool Back(int s)
//	{
//		bool n;
//		if (s > 0)
//		{
//			n = true;
//			return n;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool Front(int s)
//	{
//		bool n;
//		if (s > size)
//		{
//			n = false;
//			return n;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	void Index_at(int s)
//	{
//		bool n;
//		n = Back(s) && Front(s);
//		if (n = true)
//		{
//			cout << "Element at Index " << s << " is " << ptr[s] << endl;
//		}
//	}
//
//};
//void main()
//{
//	int val=0,siZe;
//	cout << "Enter the size of array\n";
//	cin >> siZe;
//	intArray a1(siZe);
//	cout << "Enter the values in array\n";
//	for (int i = 0; i < a1.getsize(); i++)
//	{
//		cout << "Enter value at " << i+1<< " index\n";
//		cin >> val;
//		a1.setvalues(i, val);
//	}
//	a1.display();
//	cout << "Enter the value you want to add at the begining of array\n";
//	cin >> val;
//	a1.insertAtBegining(val);
//	cout << "Array after inserting data at the begining\n";
//	a1.display();
//	cout << "Enter the value you want to add at the end of array\n";
//	cin >> val;
//	a1.insertAtEnd(val);
//	cout << "Array after inserting data at the end\n";
//	a1.display();
//	cout << "Enter the value you want to update in array\n";
//	cin >> val;
//	cout << "Enter the updated value\n";
//	cin >> siZe;
//	a1.updateData(val,siZe);
//	cout << "Arrayafter updating data\n";
//	a1.display();
//	cout << "Enter the value you want to search\n";
//	cin >> val;
//	a1.searchvalue(val);
//	cout << "Enter the value you want to remove\n";
//	cin >> val;
//	a1.remove(val);
//	a1.display();
//	
//	_getch();
//}