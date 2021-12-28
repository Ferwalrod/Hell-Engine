#pragma once

template<class T>
class HArray {
private:
	int tam = 10;
	int Num = 0;
	T* data[];
	void resize() {
		tam += 5;
		T newData[tam];
		for (int i = 0; i < Num; i++) {
			newData[i] = data[i];
		}
		delete [] data;
		data = newData;
	}
public:

	HArray() :tam(10), Num(0) { data[10]; }
	HArray(int _tam) :tam(_tam), Num(0) { data[tam]; }

	const T*&  operator[](int i) const {
		return  data[i];
	}
	T*& operator[](int i) {
		return data[i];
	}
	int size() const {
		return Num;
	}
	void add(T& obj) {
		if (Num == tam) {
			resize();
		}
		data[Num] = &obj;
		Num++;
	}
	void remove() {
		Num--;
	}
};

template<class T>
class HStack {
	template<class T>
	class HStackNode {
	public:
		T Data;
		HStackNode<T>* Next;
		HStackNode(T _data):Data(_data),Next(nullptr){}
    };
private:
	HStackNode<T>* Top;
	int tam;
public:
	HStack():Top(nullptr),tam(0) {};
	template<class T>
	void Push(T& _data) {
		HStackNode<T>* Node = new HStackNode<T>(_data);
		Node->Next = Top;
		tam++;
		Top = Node;
	}
	template<class T>
	void Pop(T& data_) {
		HStackNode<T>* aux = Top->Next;
		if (aux == nullptr) {
			data_ = Top->Data;
			Top = nullptr;
			tam--;
		}
		else {
		data_ = Top->Data;
		Top = aux;
		delete aux;
		tam--;
	    }
	}
	int size() const 
	{
		return tam;
	}
	template<class T>
	T& Peek() {
		return Top->Data;
	}
	template<class T>
	const T& Peek() const {
		return Top->Data;
	}


};
template<class T>
class HQueue {
	template<class T>
	class HQueueNode {
	public:
		T Data;
		HQueueNode<T>* Next;
		HQueueNode(T _data) :Data(_data), Next(nullptr) {}
	};
private:
	HQueueNode<T>* First;
	HQueueNode<T>* Last;
	int tam;
public:
	HQueue():First(nullptr),Last(nullptr){}
	int size() const {
		return tam;
	}
	template<class T>
	void Push(T& _data) {
		if (First == nullptr && Last == nullptr) {
			HQueueNode<T>* Node = new HQueueNode<T>(_data);
			First = Node;
			Last = Node;
			tam++;
		}
		else {
			HQueueNode<T>* Node = new HQueueNode<T>(_data);
			Node->Next = Last;
			Last = Node;
			tam++;
		}
	}
	//TODO
	//void Pop(T& data_) {
	//	data_ = First->Data;
	//	tam--;
	//}
	

};

template<class T>
class HList {

};
template<class T>
class HDoubleList {

};
template<class K, class V>
class HMap {

};
