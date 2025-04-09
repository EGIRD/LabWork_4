#ifndef SIMPLEALLOCATOR_H
#define SIMPLEALLOCATOR_H

#include <limits>
#include <cstddef>
#include <memory>

template<typename T>
class SimpleAllocator{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef size_t size_type;

    SimpleAllocator() = default;

    template<typename U> constexpr SimpleAllocator(const SimpleAllocator<U>&) noexcept{}

    pointer allocate(size_type n){
        if(n > std::allocator_traits<SimpleAllocator>::max_size(*this)){
            throw std::bad_alloc();
        }
        return reinterpret_cast<pointer>(::operator new(sizeof (T) * n));
    }

    template<typename U, typename... Args>
    void construct(U* ptr, Args... args){
        new(ptr) U(std::forward<Args>(args) ...);
    }

    template<typename U>
    void destroy(U* ptr) noexcept{
        ptr->~U();
    }

    void deallocate(pointer ptr, size_type ){
        ::operator delete(ptr);
    }

    friend bool operator ==(const SimpleAllocator&, const SimpleAllocator&){
        return true;
    }

    friend bool operator !=(const SimpleAllocator&, const SimpleAllocator&){
        return false;
    }
};

#endif // SIMPLEALLOCATOR_H
