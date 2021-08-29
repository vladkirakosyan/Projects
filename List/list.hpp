#include "forward_list.h"
template<typename T>
List<T>::List() : head{ nullptr }, m_size{}
{}

template<typename T>
List<T>::~List() {
	while (head != nullptr) {
		Node<T>* cur = head;
		head = cur->pNext;
		delete cur;
	}
}

template<typename T>
List<T>::List(const List& ls) {
	this->m_size = ls.m_size;
	Node* cur_2 = ls.head;
	head = new Node(cur_2->data);
	Node* cur = head;
	while (cur_2->next != nullptr) {
		cur_2 = cur_2->next;
		cur = new Node(cur_2->value);
		cur = cur->next;
	}
}
template<typename T>
inline List<T>::List(List<T>&& rhs)
{
	this->head = rhs.head;
	m_size = rhs.m_size;
	rhs.head = nullptr;
	rhs.m_size = 0;
}

template<typename T>
inline List<T>::List(int size, T value) : m_size{ size }
{
	if (size < 1) {
		return;
	}
	this->head = new Node<T>(value);
	Node<T>* tmp = head;
	while (size > 1) {
		tmp->pNext = new Node<T>(value);
		tmp = tmp->pNext;
		--size;
	}
}

template<typename T>
inline List<T>::List(std::initializer_list<T> a) : m_size{ (int)a.size() }
{

	for (const auto& k : a) {
		std::cout << k << " ";
	}
}

template<typename T>
inline List<T>& List<T>::operator=( List<T>&& rhs) noexcept
{
	if (&rhs == this) {
		return *this;
	}
	m_size = rhs.m_size;
	while (this->head != nullptr) {
		Node<T>* cur = head;
		head = cur->pNext;
		delete cur;
	}
	this->head = rhs.head;
	rhs.head = nullptr;
	rhs.m_size = 0;
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& other) noexcept
{
	if (this == &other) {
		return *this;
	}
	while (this->head != nullptr) {
		Node<T>* cur = head;
		head = cur->pNext;
		delete cur;
	}
	Node* cur = other.head;
	head = new Node(cur->data);
	Node* cur_2 = this->head;
	cur = cur->pNext;
	this->m_size = other.m_size;
	while (cur->pNext != nullptr) {
		cur_2.pNext = new Node<T>(cur->data);
		cur = cur->pNext;
		cur_2 = cur_2.pNext;
	}
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	++m_size;
}

template<typename T>
inline void List<T>::pop_back()
{
	removeAt(m_size - 1);
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	--m_size;
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	++m_size;
}

template<typename T>
inline void List<T>::insert(T value, int index) {
	if (index == 0) {
		push_front(value);
	}
	else {
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		m_size++;
	}
}

template<typename T>
inline void List<T>::removeAt(int index) {
	if (index >= m_size) {
		std::cout << "segmentation fault\n";
		exit(0);
	}
	else if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		--m_size;
	}
}

template<typename T>
inline void List<T>::erase(int index)
{
	Node<T>* cur = head;
	while (index) {
		cur = cur->pNext;
		--index;
	}
	Node<T>* cur_2 = cur->pNext;
	cur->pNext = cur_2->pNext;
	delete cur_2;
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	if (index >= m_size) {
		std::cout << "Segmentation fault\n";
		exit(0);
	}
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
