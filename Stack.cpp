#include <iostream>
#include <cstdlib>
using namespace std;


//Templatized Stack Class
template <typename T>

class Stack
{

private:

	T*  stk;

	int stkPtr;
	int maxSize;

public:

	//Constructor with Default Parameters
	Stack (int s = 10)
	{
		if(s<=0)
			s = 10;

		stk = new T [s];
		maxSize = s;
		stkPtr = -1;
	}


	//Destructor
	~Stack ()
	{
		if(stk)
			delete stk;
	}


	//Top Function to view the data on the top of the Stack
	bool Top (T& data)
	{
		if(!IsEmpty())
		{
			data =  stk [stkPtr];
			return true;
		}

		return false;
	}


	//Function to check if Stack is empty
	bool IsEmpty ()
	{
		return (stkPtr == -1);
	}


	//Function to check if Stack is full
	bool IsFull ()
	{
		return (stkPtr == maxSize -1);
	}


	//Function to push data into the top of the Stack
	bool Push (T& data)
	{
		if(!IsFull())
		{
			stk [++stkPtr] = data;
			return true;
		}

		return false;
	}


	//Function to pop data from the top of the Stack
	bool Pop(T& data)
	{
		if(!IsEmpty())
		{
			data = stk [stkPtr--];
			return true;
		}

		return false;
	}


	//Copy Constructor
	Stack(Stack& obj)
	{
		stk = new T [obj.maxSize];

		for (int i = 0; i < obj.maxSize; ++i)
		{
			stk[i] = obj.stk[i];
		}

		maxSize = obj.maxSize;
		stkPtr = obj.stkPtr;
	}


	//Overloaded Assignment Operator
	Stack& operator = (Stack& rhs)
	{
		if(this != &rhs)
		{
			if(stk)
					delete stk;

			stk = new T [rhs.maxSize];

			for (int i = 0; i < rhs.maxSize; ++i)
			{
				stk[i] = rhs.stk[i];
			}

			maxSize = rhs.maxSize;
			stkPtr = rhs.stkPtr;
		}

		return *this;
	}


	void displayFunctions()
	{
		cout << "\n\nThis class Stack has the following functionality : ";
		cout << "\n1)Push \n2)Pop \n3)Top \n4)IsEmpty \n5)IsFull ";
		cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
	}


	void displayStack()
	{
		T temp;
		cout << "\n\nThe stack is : ";


		while( !IsEmpty())
		{
			Pop(temp);
			cout << endl << temp;
		}
	}
};
//--------------Ended Stack Class---------------------

void driver()
{
	int size;
	cout << "Enter the maxsize of the stack : ";
	cin >> size;
	Stack<int> stack1(size);

	int userInput = 0;
	int data;

	while (userInput != -1)
	{
		stack1.displayFunctions();
		cin >> userInput;

		if (userInput == 1)
		{
			cout << "\nEnter the data to push into the stack : ";
			cin  >> data;

			if ( stack1.Push(data) )
				cout << "\nPush Successful.";
			else
				cout << "\nPush Unsuccessful.";
		}

		else if (userInput == 2)
		{
			if( stack1.Pop(data) )
				cout << "\nThe popped data item is : " << data;
			else
				cout << "\nPop Unsuccessful.";
		}

		else if (userInput == 3)
		{
			if (stack1.Top(data))
				cout <<"\nThe element at the top of the stack is : " << data;
			else
				cout << "\nTop Unsuccessful.";
		}

		else if (userInput == 4)
		{
			if (stack1.IsEmpty())
				cout << "\nThe stack is empty.";
			else
				cout << "\nThe stack isn't empty.";
		}

		else if (userInput == 5)
		{
			if (stack1.IsFull())
				cout << "\nThe stack is full.";
			else
				cout << "\nThe stack isn't full.";
		}
	}



	cout << "\nTesting the copy constructor :";
	Stack<int> stack2 = stack1;

	cout << "\nStack 2 is a copy of Stack 1 constructed through Copy Constructor.";
	if(! stack1.IsEmpty() )
		stack1.displayStack();
	else
		cout << "\nStack 1 is empty.";

	if(! stack2.IsEmpty() )
		stack2.displayStack();
	else
		cout << "\nStack 2 is empty.";

	cout << "\n\nSimilarly the overloaded assignment operator can be tested. " << endl;
}



int main ()
{
	driver ();
	return 0;
}
