#include <iostream>
#include <vector>

using namespace std;

class Stack
{
	private:
		vector<int> nodes;
		int size;

	public:
		Stack(int val)
		{
			size = val;
		}  

		void push(int val)
		{
			// assuming no overflow scenario
			if (nodes.size() == 0)
			{
				nodes.push_back(val);
			}
			
			if (nodes.size() <= size)
			{
				nodes.push_back(val);

				if (nodes.at(nodes.size() - 1) > nodes.at(nodes.size() - 2))
				{
					int temp = nodes.at(nodes.size() - 1);
					nodes.at(nodes.size() - 1) = nodes.at(nodes.size() - 2);
					nodes.at(nodes.size() - 2) = temp;
				}
			}
			else
			{
			    cout << "STACK OVERFLOW!" << endl;
			}
		}

		int pop ()
		{
			int val = nodes.at(nodes.size());
			nodes.pop_back();
			return val;
		}

		int findMin()
		{
			if (nodes.size() == 0)
			{
				cout << "STACK UNDERFLOW";
				return -1;
			}
			else
			{
				return nodes.at(nodes.size() - 1);
			}
		}
};

int main ()
{
	Stack myObj(10);

	myObj.push(7);
	myObj.push(1);
	myObj.push(5);
	myObj.push(9);
	myObj.push(44);
	myObj.push(-3);
	myObj.push(7);
	myObj.push(534);
	myObj.push(68654);
	myObj.push(23);

	cout << myObj.findMin() << endl;

	return 0;
}


/*

With Exception Handling

#include <iostream>
#include <vector>

using namespace std;

class Stack 
{
	private:

		vector<int> min;
		int size;

	public:

		Stack (int size)
		{
			this.size = size;
		}

		void push(int val)
		{
			try
			{
				if (min.size() >= size)
				{
					throw out_of_range("Stack overflow");
				}

				if (min.size() == 0)
				{
					min.push_back(val);
				}
				else
				{
					if (val > min[min.size() - 1])
					{
						int temp = min[min.size() - 1];
						min[min.size() - 1] = val;
						min.push_back(temp);
					}
					else
					{
						min.push_back(val);
					}
				}
			}
			catch (Exception e)
			{
				cout << e.what() << endl;
			}			
		}

		int pop ()
		{
			try
			{					
				if (min.size() <= 0)
				{
					throw out_of_range("Stack Underflow");	
				}

				return min.pop_back();

			}
			catch (Exception e)
			{
				cout << e.what() << endl;
			}
		} 
	}
	
	*/
