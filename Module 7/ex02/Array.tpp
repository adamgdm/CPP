
template <typename T>
Array<T>::Array() 
{
    this->arr = NULL;
    this->size_arr = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->arr = new T[n];
    this->size_arr = n;
}

template <typename T>
Array<T>::Array(Array const &other)
{
    unsigned int i;

    i = 0;
    this->arr = new T[other.size()];
    this->size_arr = other.size_arr;
    while (i < other.size_arr)
    {
        this->arr[i] = other.arr[i];
        i++;
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] (this->arr);
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    unsigned int i;

    i = 0;
    if (this != &other)
    { 
        delete [] this->arr;
        this->arr = new T[other.size()];
        this->size_arr = other.size_arr;
        while (i < other.size_arr)
        {
            this->arr[i] = other.arr[i];
            i++;
        }
    }
    return (*this);
}

template <typename T>
int &Array<T>::operator[](unsigned int i)
{
    if (i < 0 || i >= this->size_arr)
        throw std::exception();
    return (this->arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->size_arr);
}
