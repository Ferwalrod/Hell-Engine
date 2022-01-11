#pragma once
#include <iostream>
using namespace std;

template<class T>
class HArray {
private:
	const int tam = 50;
	int Num = 0;
	T* data[];
	void resize() {
		//tam += 5;
		//T newData[tam];
		//for (int i = 0; i < Num; i++) {
		//	newData[i] = data[i];
		//}
		//delete [] data;
		//data = newData;
	}
public:

	HArray() :tam(50), Num(0) { data[50]; }
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
	void add(T obj) {
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
private:
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
	void Push(T _data) {
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
private:
	template<class T>
	class HQueueNode {
	public:
		T Data;
		HQueueNode<T>* Next;
		HQueueNode<T>* Prev;
		HQueueNode(T _data) :Data(_data), Next(nullptr),Prev(nullptr) {}
	};
private:
	HQueueNode<T>* First;
	HQueueNode<T>* Last;
	int tam;
public:
	HQueue():First(nullptr),Last(nullptr),tam(0){}
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
			Node->Prev = Last;
			Last->Next = Node;
			Last = Node;
			tam++;
		}
	}
	template<class T>
	void Push(T _data) {
		if (First == nullptr && Last == nullptr) {
			HQueueNode<T>* Node = new HQueueNode<T>(_data);
			First = Node;
			Last = Node;
			tam++;
		}
		else {
			HQueueNode<T>* Node = new HQueueNode<T>(_data);
			Node->Prev = Last;
			Last->Next = Node;
			Last = Node;
			tam++;
		}
	}
	template<class T>
	void Pop(T& data_) {
		if (tam == 0) return;
		data_ = First->Data;
		HQueueNode<T>* Aux = First;
		First = Aux->Next;
		delete Aux;
		tam--;
	}
	template<class T>
	T& PeekFirst() {
		return First->Data;
	}
	template<class T>
	const T& PeekFirst() const {
		return First->Data;
	}
	template<class T>
	T& PeekLast() {
		return Last->Data;
	}
	template<class T>
	const T& PeekLast() const {
		return Last->Data;
	}

};

template<class K, class V>
class HMap {
public:
	template<class K,class V>
	class HPair {
	public:
		K* Key;
		V* Value;
		HPair(K _key,V _value):Key(&_key),Value(&_value){}
		HPair(K* _key, V* _value) :Key(_key), Value(_value) {}
	};
private:
	hash<K> hashKey;
	int tam;
	int Num;
	HArray<HPair<K, V>> content;
public:
	HMap():content(HArray<HPair<K,V>>(20)),tam(20),Num(0){}
	HMap(int _tam):content(HArray<HPair<K, V>>(_tam)), tam(_tam),Num(0) {}
	template<class K,class V>
	void Add(HPair<K, V>& _pair) {
		content[hashKey(_pair.Key) % tam] = _pair;
		Num++;
	}
	template<class K, class V>
	void Add(K& _Key, V& _Value) {
		HPair<K, V> Pair = HPair<K, V>(_Key, _Value);
		content[hashKey(Pair.Key) % tam] = Pair;
		Num++;
	}
	template<class K, class V>
	void Add(K _Key, V _Value) {
		HPair<K, V> Pair = HPair<K, V>(_Key, _Value);
		content[hashKey(Pair.Key) % tam] = Pair;
		Num++;
	}
	int size() const {
		return Num;
	}
	template<class K, class V>
	void GetKeys(HArray<K>& keys_) {
		for (int i = 0; i < content.size(); i++) {
			keys_.add(content[i]->Key);
		}
	}
	template<class K, class V>
	void  GetKeys(const HArray<K>& keys_) const {
		for (int i = 0; i < content.size(); i++) {
			keys_.add(content[i]->Key);
		}
	}
	template<class K, class V>
	void GetValues(HArray<V>& values_) {
		for (int i = 0; i < content.size(); i++) {
			values_.add(content[i]->Value);
		}
	}
	template<class K, class V>
	void GetValues(const HArray<V>& values_) const {
		for (int i = 0; i < content.size(); i++) {
			values_.add(content[i]->Value);
		}
	
	}
	V*& operator[](K i) {
		content[hashKey(i) % tam]->Value;
	}

};

template<class T>
class HList {

};
template<class T>
class HDoubleList {

};
