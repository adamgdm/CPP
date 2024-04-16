template <typename T> int easyfind(T &container, int integer)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), integer);
    if (iter == container.end())    
        throw std::exception();
    return (*iter);
}
