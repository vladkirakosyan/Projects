#include "frankenstein_list.h"

/* DEF. CONSTRUCTOR AND DESTRUCTOR */
template <typename T>
selfOrganizingList::Flist<T>::Flist()
	: _head{ nullptr }, _tail{ nullptr }, m_asc{ nullptr }, m_desc{ nullptr }
{}

template<typename T>
selfOrganizingList::Flist<T>::~Flist()
{
	helperDelete();
}
template<typename T>
selfOrganizingList::Flist<T>::Flist(size_t count,const T& val)
{
	if (count == 0) { 
		_head = _tail = m_asc = m_desc = nullptr; 
	}
	else {
		this->_head = new Node<T>(val);
		_head->_prev = nullptr;
		Node<T>* cur = _head;
		Node<T>* prev = cur;

		while (count--)
		{
			cur->_next = new Node<T>(val);
			cur = cur->_next;
			cur->_prev = prev;
			prev = cur;
		}
		cur->_next = nullptr;
		_tail = cur;
		m_asc = _head;
		m_desc = _tail;
	}
}

/* COPY & MOVE CONSTRUCTORS*/
template<typename T>
selfOrganizingList::Flist<T>::Flist(const Flist<T>& src)
{
	if (src._head == nullptr) {
		_head = _tail = m_asc = m_desc = nullptr;
	}
	else {
		helperCopyingNodes(src);
		pushSortedWay();
	}
}

template <typename T>
selfOrganizingList::Flist<T>::Flist(Flist<T>&& src) noexcept
	: _head{ src.head }, _tail{ src._tail }, m_asc{ src.m_asc }, m_desc{ src.m_desc }
{
	src._head = src._tail = src.m_asc = src.m_desc = nullptr;
}

/* FUNCTIONS SUPPORTED BY FORWARD_LIST */
template <typename T>
size_t selfOrganizingList::Flist<T>::size() const noexcept
{
	size_t m_size = 0;
	Node<T>* cur = _head;
	while (cur)
	{
		++m_size;
		cur = cur->_next;
	}
	return m_size;
}

template<typename T>
void selfOrganizingList::Flist<T>::clear() noexcept
{
	helperDelete();
}

template <typename T>
T selfOrganizingList::Flist<T>::maxElem() const
{
	return m_desc->_data;
}

template <typename T>
T selfOrganizingList::Flist<T>::minElem() const
{
	return m_asc->_data;
}

template <typename T>
bool selfOrganizingList::Flist<T>::isEmpty() const
{
	if (_head) return false;
	return true;
}

template <typename T>
T selfOrganizingList::Flist<T>::front() const
{
	return _head->_data;
}

template <typename T>
T selfOrganizingList::Flist<T>::back() const
{
	return _tail->_data;
}

template <typename T>
void selfOrganizingList::Flist<T>::push_front(const T& data)
{
	if (_head == nullptr) {
		_head = new Node<T>(data);
		_tail = m_asc = m_desc = _head;
	}
	else {
		Node<T>* newNode = new Node<T>(data);
		_head->_prev = newNode;
		newNode->_next = _head;
		_head = newNode;
		if (size() == 1) _tail = _head;
		pushSortedWay(_head);
	}
}

template <typename T>
void selfOrganizingList::Flist<T>::push_back(const T& data)
{
	if (_head == nullptr) {
		_head = new Node<T>(data);
		_tail = m_asc = m_desc = _head;
	}
	else {
		Node<T>* lastNode = new Node<T>(data);
		_tail->_next = lastNode;
		lastNode->_prev = _tail;
		_tail = _tail->_next;
		if (size() == 1) _head = _tail;
		pushSortedWay(_tail);
	}
}
template <typename T>
void selfOrganizingList::Flist<T>::pop_front()
{
	if (!_head) {
		throw std::invalid_argument("List is empty!");
	}
	else if (_head == _tail) {
		delete _head;
		_head = _tail = m_asc = m_desc = nullptr;
	}
	else {
		popSortedWay(_head);
		Node<T>* cur = _head;
		_head = _head->_next;
		_head->_prev = nullptr;
		delete cur;
	}
}

template <typename T>
void selfOrganizingList::Flist<T>::pop_back()
{
	if (_head == nullptr) {
		throw std::invalid_argument("List is empty!");
	}
	else if (_head == _tail){
		delete _head;
		_head = _tail = m_asc = m_desc = nullptr;
	}
	else {
		popSortedWay(_tail);
		Node<T>* pr = _tail;
		_tail = _tail->_prev;
		_tail->_next = nullptr;
		delete pr;
	}
}

/* HELPER FUNCTIONS TO AVOID CODE DUPLICATION */
template <typename T>
void selfOrganizingList::Flist<T>::helperCopyingNodes(const Flist<T>& src)
{
	Node<T>* cur_2 = src._head;
	this->_head = new Node<T>(cur_2->_data);
	Node<T>* cur = _head;
	Node<T>* prev = _head;
	while (cur_2 != nullptr) {
		cur_2 = cur_2->_next;
		cur->_next = new Node<T>(cur_2->_data);
		cur = cur->_next;
		cur->_prev = prev;
		prev = cur;
	}
	cur->_next = nullptr;
	_tail = cur;
}

template<typename T>
void selfOrganizingList::Flist<T>::helperDelete()
{
	Node<T>* cur = _head;
	while (_head != nullptr) {
		_head = cur->_next;
		delete cur;
		cur = _head;
	}
	_head = _tail = m_asc = m_desc = nullptr;
}

template<typename T>
void selfOrganizingList::Flist<T>::pushSortedWay(Node<T>* n)
{
	/* n->_data(T) must support >= comparison operator */
	if (m_asc->_data >= n->_data) {
		m_asc->_desc = n;
		n->_asc = m_asc;
		m_asc = n;
	}
	else {
		Node<T>* cur = m_asc;
		while (cur->_asc != nullptr) {
			if (cur->_asc->_data >= n->_data) {
				cur->_asc->_desc = n;
				n->_asc = cur->_asc;
				n->_desc = cur;
				cur->_asc = n;
			}
			cur = cur->_asc;
		}
		n->_desc = cur;
		cur->_asc = n;
		m_desc = n;
	}
}

template<typename T>
void selfOrganizingList::Flist<T>::popSortedWay(Node<T>* n)
{
	if (n == m_desc) // insulating greatest element
	{
		Node<T>* tmp = m_desc->_desc;
		tmp->_asc = nullptr;
		n->_desc = nullptr;
		m_desc = tmp;
	}
	else if (n == m_asc) // insulating smallest element
	{
		Node<T>* tmp = m_asc->_asc;
		tmp->_desc = nullptr;
		n->_asc = nullptr;
		m_asc = tmp;
	}
	else { // middle element
		Node<T>* prev = n->_desc;
		Node<T>* next = n->_asc;
		prev->_asc = n->_asc;
		next->_desc = n->_desc;
		n->_asc = n->_desc = nullptr;
	}
}
