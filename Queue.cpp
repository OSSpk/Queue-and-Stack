#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>

class Queue
{
private:
	T* arr;
	int front;
	int rear;
	int maxSize;
	int currSize;

public:

	//Constructor with Default Parameters
	Queue (int s = 10)
	{
		if(s<=0)
			s = 10;
		arr = new T [s];
		maxSize = s;
		currSize = 0;
		front = 0;
		rear = -1;
	}


	//Destructor
	~Queue ()
	{
		if(arr)
			delete arr;
	}


	//To check whether the queue is empty
	bool IsEmpty()
	{
		return (currSize == 0);
	}


	//To check whether the queue is full
	bool IsFull()
	{
		return (currSize == maxSize);
	}


	//Copy Constructor
	Queue (Queue& obj)
	{
		arr = new T [obj.maxSize];

		for (int i = 0; i < obj.maxSize; ++i)
		{
			arr[i] = obj.arr[i];
		}

		currSize = obj.currSize;
		maxSize  = obj.maxSize;
		front = obj.front;
		rear  = obj.rear;
	}


	//Overloaded Assignment Operator
	Queue& operator = (Queue& rhs)
	{
		if(this != &rhs)
		{
			if(arr)
				delete arr;

			arr = new T [rhs.maxSize];

			for (int i = 0; i < rhs.maxSize; ++i)
			{
				arr[i] = rhs.arr[i];
			}

			currSize = rhs.currSize;
			maxSize  = rhs.maxSize;
			front = rhs.front;
			rear  = rhs.rear;
		}

		return *this;
	}


	//To add an element at the rear of the queue
	bool Enqueue( T& data)
	{
		if(!IsFull())
		{
			if(rear == maxSize - 1)//To aid wraparound
				rear = -1;

			arr[++rear] = data;
			currSize++;

			return true;
		}

		return false;
	}


	//To remove an element from the front of the Queue
	bool  Dequeue ( T& data )
	{
		if(!IsEmpty())
		{
			if(front == maxSize)//To aid wraparound
			{
				front = 0;
			}

			data = arr[front++];
			currSize--;

			return true;
		}

		return false;
	}


	void displayFunctions()
	{
		cout << "\n\nThe class Queue has the following functions : ";
		cout << "\n1)Enqueue \n2)Dequeue \n3)IsEmpty \n4)IsFull ";
	    cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
	}

	void displayQueue()
	{
		T temp;
		cout << "\n\nThe queue is : ";


		while( !IsEmpty())
		{
			Dequeue(temp);
			cout << endl << temp;
		}
	}
};

//-------------Class Ended--------------------------------

void driver()
{
	int size;
	cout << "Enter the maxsize of the queue : ";
	cin >> size;
	Queue<int> que1(size);

	int userInput = 0;
	int data;

	while (userInput != -1)
	{
		que1.displayFunctions();
		cin >> userInput;

		if (userInput == 1)
		{
			cout << "\nEnter the data to insert into the queue : ";
			cin  >> data;

			if ( que1.Enqueue(data) )
				cout << "\nEnqueue Successful.";
			else
				cout << "\nEnqueue Unsuccessful.";
		}

		else if (userInput == 2)
		{
			if( que1.Dequeue(data) )
				cout << "\nThe Dequeued data item is : " << data;
			else
				cout << "\nDequeue Unsuccessful.";
		}

		else if (userInput == 3)
		{
			if (que1.IsEmpty())
				cout << "\nThe queue is empty.";
			else
				cout << "\nThe queue isn't empty.";
		}

		else if (userInput == 4)
		{
			if (que1.IsFull())
				cout << "\nThe queue is full.";
			else
				cout << "\nThe queue isn't full.";
		}
	}


	cout << "\nTesting the copy constructor :";
	Queue<int> que2 = que1;

	cout << "\nqueue 2 is a copy of queue 1 constructed through Copy Constructor.";
	if(! que1.IsEmpty() )
		que1.displayQueue();
	else
		cout << "\nqueue 1 is empty.";

	if(! que2.IsEmpty() )
		que2.displayQueue();
	else
		cout << "\nqueue 2 is empty.";

	cout << "\n\nSimilarly the overloaded assignment operator can be tested. " << endl;
}




int main ()
{
	driver();
	return 0;
}
