
#include"EngineCore/Core.h"
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char** argv) 
{
	//HellEngine::RunEngine(argc, argv);

	HArray<int> A;
	//A.add(3);
	//A.add(10);
	//A.add(2);
	//cout <<"Element of position 2:" << *A[2] << endl;
	//cout <<"Total elements of Array:"<< A.size() << endl;
	HQueue<int> Q;
	Q.Push(69);
	Q.Push(4);
	Q.Push(6);
	cout << "Total elements of Queue:" << Q.size() << endl;
	int element;
	Q.Pop(element);
	cout << "Element popped from Queue:" << element << endl;
	cout << "New Total elements of Queue:" << Q.size() << endl;
	HStack<int> S;
	S.Push(3);
	S.Push(22);
	S.Push(1);
	cout << "Total elements of Stack:" << S.size() << endl;
	int element1;
	S.Pop(element1);
	cout << "New Total elements of Stack:" << S.size() << endl;
	HMap<int, string> M;
	string* s =new string("Hola mundo");
	M.Add(2, s);
	cout << "Total elements of Map:" << M.size() << endl;

}
