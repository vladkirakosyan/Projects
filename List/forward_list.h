#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template<typename T>
class List {

public:
	List();							      // default constructor
	~List();							  // destructor
	List(const List& ls);			      // copy ctor
	List(List<T>&& rhs);				  // move ctor
	List(int size, T value);			  // ctor with parameters
	List(std::initializer_list<T> a);	  // initializer_list
	List<T>& operator=(const List<T>& other) noexcept;   // operator =
	List<T>& operator=(List<T>&& rhs) noexcept; // move operator =

public:
	void push_back(T data);
	void pop_back();
	void pop_front();
	void push_front(T data); 
	void insert(T value, int index);
	void removeAt(int index);
	void erase(int index);
	int GetSize() { return m_size; }
	T& operator[](const int index);

private:
	template<class T>
	struct Node {
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) : data{ data }, pNext{ pNext }
		{}
	};

private:
	int m_size;
	Node<T>* head;
};

#include "list.hpp"

#endif // FORWARD_LIST_H