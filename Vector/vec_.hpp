template<typename T>
Vector<T>::Vector() : m_size{}, m_cap{}, m_arr{ nullptr }
{}

template<typename T>
Vector<T>::~Vector() {
	delete[] m_arr;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	m_cap = other.m_cap;
	m_size = other.m_size;
	m_arr = new T[m_cap];
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> a) : m_size{ (int)a.size() }, m_cap{ (int)a.size() }{
	int i{};
	m_arr = new T[m_cap];
	for (const auto& a1 : a) {
		m_arr[i++] = a1;
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this == &other) {
		return *this;
	}
	delete[] m_arr;
	m_cap = other.m_cap;
	m_size = other.m_size;
	m_arr = new T[m_cap];
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& oth) {
	Vector<T> r;
	r.m_cap = this->m_cap + oth.m_cap;
	r.m_size = this->m_size + oth.m_size;
	r.m_arr = new T[r.m_cap];
	for (int i = 0; i < this->m_size; ++i)
		r.m_arr[i] = this->m_arr[i];
	int i = 0;
	for (int j = this->m_size; j < r.m_size; ++j) {
		i++;
		r.m_arr[j] = oth.m_arr[i];
	}
	return r;
}
template<typename T>
T& Vector<T>::operator[](int iter) {
	if (iter < m_size) {
		return m_arr[iter];
	}
	else {
		std::cout << "Segmentation fault - run time error\n";
	}
}

template<typename T>
void Vector<T>::push_back(const T& element) {
	if (m_cap == m_size) {
		m_cap = m_cap ? m_cap * 2 : 1;
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_size; ++i) {
			tmp[i] = this->m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
	}
	m_arr[m_size] = element;
	++m_size;
}

template<typename T>
void Vector<T>::push_front(const T& element) {
	if (m_size == m_cap) {
		m_cap = m_cap ? m_cap * 2 : 1;
		T* tmp = new T[m_cap];
		
		for (int i = 0; i < m_size; ++i) {
			tmp[i + 1] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
	}
	else {
		for (int i = m_size - 1; i >= 0; --i) {
			m_arr[i + 1] = m_arr[i];
		}
	}
	m_arr[0] = element;
	++m_size;
}
template<typename T>
void Vector<T>::erase(int size_pos){
	if (size_pos >= 0 && size_pos < m_size)
	{
		for (int i = size_pos; i < m_size-1; ++i)
		{
			m_arr[i] = m_arr[i + 1];
		}
		--m_size;
	}
}
template <typename T>
int Vector<T>::getCapacity() const {
	return m_cap;
}
template <typename T>
int Vector<T>::getSize() const {
	return m_size;
}
// template <typename T>
