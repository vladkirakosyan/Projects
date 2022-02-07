#pragma once
#ifndef FRANKENSTEIN_LIST
#define FRANKENSTEIN_LIST

namespace selfOrganizingList
{
	template <typename T>
	class Flist
	{
	public:
		/* DEFAULT CONSTRUCTOR AND DESTRUCTOR */
		Flist();
		~Flist();

		/* PARAMETRIZED CONSTRUCTORS */
		Flist(size_t count,const T& val);

		/* COPY & MOVE CONSTRUCTORS*/
		Flist(const Flist&);
		Flist(Flist&&) noexcept;

		/* COPY ASSIGNMENT OPERATORS */
		Flist& operator=(const Flist&);
		Flist& operator=(Flist&&) noexcept;

		T front() const;
		T back() const;
		T maxElem() const;
		T minElem() const;
		size_t size() const noexcept;
		void push_back(const T& data);
		void pop_back();
		void push_front(const T& data);
		void pop_front();
		size_t find(T data);
		void insert(size_t pos, const T& val);
		bool isEmpty() const;
		void clear() noexcept;
	
	private:
		template <typename T>
		struct Node {
			T _data;
			Node* _next;
			Node* _prev;
			Node* _asc;
			Node* _desc;
			Node(T val = T(), Node* next = nullptr, Node* prev = nullptr,
				Node* asc = nullptr, Node* desc = nullptr)
				: _data{ val }, _next{ next }, _prev{ prev }, _asc{ asc }, _desc{ desc }
			{}
			Node(Node&& src) : _data{ src._data }, _prev{ src._prev }, _next { src._next },
				_asc { src._asc }, _desc { src._desc }
			{}
			
		};
		Node<T>* _head; // always points to first element
		Node<T>* _tail; // points to last element

		Node<T>* m_asc; // points to smallest element
		Node<T>* m_desc; // points to greatest element
	private:
		void helperCopyingNodes(const Flist<T>& src);
		void helperDelete();
		void pushSortedWay(Node<T>* n);
		void popSortedWay(Node<T>* n);
	};
}

#include "frankenstein_list.hpp"
#endif // FRANKENSTEIN_LIST
