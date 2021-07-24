#include<bits/stdc++.h>
using namespace std;

class vectorclass{
	
	public:
	int capacity;
	int current;
	int * arr;
	
	vectorclass()
	{
		capacity =1;
		current =0;
		arr = new int[1];
	}
	
	void push(int data)
	{
		if(current == capacity)
		{
			int * temp = new int[2*capacity];
			for(int i=0;i<capacity;i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity = capacity*2;
			arr = temp;
		}
		
		arr[current] = data;
		current++;
	}
	void pop()
	{
		current--;
	}
	int size()
	{
		return current;
	}
	int getcapacity()
	{
		return capacity;
	}
	void print_data()
	{
		for(int i=0;i<current;i++)
		cout<<arr[i]<<" ";
	}
	//operator overloading 
	int operator[](int i){
		return arr[i];
	}
	
};

int main()
{
	vectorclass obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	//obj.pop();
	cout<<obj[2]<<endl;
	obj.print_data();
}