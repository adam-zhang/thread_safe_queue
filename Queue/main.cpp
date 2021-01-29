#include <iostream>
#include "Queue.h"
#include "Singleton.h"
#include <thread>
#include <functional>

using namespace std;

void consumer(Queue<int>& queue)
{
	for(auto i = 0; i != 1000; ++i)
	{
		cout << "Consumer\n";
		auto value = queue.pop();
		cout << "the value:" << value << " is poped" << endl; 
	}
}

void producer( Queue<int>& queue)
{
	for(int i = 0; i != 1000; ++i)
	{
		queue.push(i);
		cout << "the value:" << i << " is pushed." << endl;
	}
}

int main(int argc, char** argv)
{
	Queue<int> queue;
	thread t1(producer, std::ref(queue));
	thread t2(consumer, std::ref(queue));
	t1.join();
	t2.join();
	return 0;
}
