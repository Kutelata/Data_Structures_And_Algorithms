template <typename T>
class Vector
{
public:
	int size;
	int capacity;
	T *array;

	void Expand(int newCapacity)
	{
		if (newCapacity <= size)
			return;
		T *old = array;
		array = new T[newCapacity];
		for (int i = 0; i < size; i++)
			array[i] = old[i];
		delete[] old;
		capacity = newCapacity;
	}

	Vector(int initCapacity = 100)
	{
		size = 0;
		capacity = initCapacity;
		array = new T[capacity];
	}

	~Vector()
	{
		delete[] array;
	}

	Vector &operator=(Vector &assign)
	{
		if (this != &rhs) 
		{
			delete[] array;			 
			size = assign.size;		 
			capacity = assign.capacity; 
			array = new T[capacity]; 
			for (int i = 0; i < size; i++)
				array[i] = assign.array[i];
		}
		return *this; 
	}

	int Size()
	{
		return size;
	}

	bool Empty()
	{
		return (size == 0);
	}

	T &operator[](int position)
	{
		return array[position];
	}

	void PushBack(T newElement)
	{
		if (size == capacity)
			expand(2 * size);
		array[size] = newElement;
		size++;
	}

	void PopBack()
	{
		size--;
	}

	void Insert(int position, T newElement)
	{
		if (size == capacity)
			Expand(2 * size);
		for (int i = size; i > pos; i--)
			array[i] = array[i - 1];
		array[position] = newElement;
		size++;
	}

	void Erase(int position)
	{
		for (int i = position; i < size - 1; i++)
			array[i] = array[i + 1];
		size--;
	}

	void Clear()
	{
		size = 0;
	}
};