#ifndef FORWARD_LIST
#define FORWARD_LIST

template <class T>
class List
{
public:
	/* DEFAULT CONSTRUCTOR AND DESTRUCTOR */
	List();
	~List();

	/* PARAMETRIZED CONSTRUCTORS */
	explicit List(size_t count, const T& data);
	List(std::initializer_list<T> src);

	/* COPY & MOVE CONSTRUCTORS*/
	List(const List<T>&);
	List(List<T>&& src) noexcept;
	
	/* COPY ASSIGNMENT OPERATORS */
	List<T>& operator=(const List<T>& rhs);
	List<T>& operator=(List<T>&& rhs) noexcept;
	
	/* COMPARISON OPERATORS */
	bool operator==(const List<T>& rhs) const;
	bool operator!=(const List<T>& rhs) const;

	/* FUNCTIONS */
	void push_front(const T& value);
	void push_back(const T& value);
	void removeAt(size_t index);
	void pop_front();
	void pop_back();
	void insertBefore(const int pos, const T& value);
	void resize(size_t sz, const T& val = T());

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	size_t findIndex(const T& value) const;
	bool isEmpty() const;
	size_t getSize() const noexcept;
	void clear() noexcept;
	
public:
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const List<T>& src);

private:
	template <class T>
	struct Node {
		T _data;
		Node<T>* _next;
	};
	size_t _size;
	Node<T>* _head;

private:
	void helperDeleteNodes();
	void helperCopyingNodes(const List<T>& rhs);
};

#include "forward_list.hpp"
#endif // FORWARD_LIST
