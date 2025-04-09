#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>

namespace myStd {
template<typename T>
class vector {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;

    class Iterator {
    private:
        pointer ptr;
    public:
        Iterator(pointer p = nullptr) : ptr(p) {}
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
        Iterator& operator--() { --ptr; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --ptr; return tmp; }
        Iterator operator+(size_type n) const { return Iterator(ptr + n); }
        Iterator operator-(size_type n) const { return Iterator(ptr - n); }
        size_type operator-(const Iterator& other) const { return ptr - other.ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    class ConstIterator {
    private:
        const_pointer ptr;
    public:
        ConstIterator(const_pointer p = nullptr) : ptr(p) {}
        const_reference operator*() const { return *ptr; }
        const_pointer operator->() const { return ptr; }
        ConstIterator& operator++() { ++ptr; return *this; }
        ConstIterator operator++(int) { ConstIterator tmp = *this; ++ptr; return tmp; }
        ConstIterator& operator--() { --ptr; return *this; }
        ConstIterator operator--(int) { ConstIterator tmp = *this; --ptr; return tmp; }
        ConstIterator operator+(size_type n) const { return ConstIterator(ptr + n); }
        ConstIterator operator-(size_type n) const { return ConstIterator(ptr - n); }
        size_type operator-(const ConstIterator& other) const { return ptr - other.ptr; }
        bool operator==(const ConstIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const ConstIterator& other) const { return ptr != other.ptr; }
    };

    class ReverseIterator {
    private:
        pointer ptr;
    public:
        ReverseIterator(pointer p = nullptr) : ptr(p) {}
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }
        ReverseIterator& operator++() { --ptr; return *this; }
        ReverseIterator operator++(int) { ReverseIterator tmp = *this; --ptr; return tmp; }
        ReverseIterator& operator--() { ++ptr; return *this; }
        ReverseIterator operator--(int) { ReverseIterator tmp = *this; ++ptr; return tmp; }
        ReverseIterator operator+(size_type n) const { return ReverseIterator(ptr - n); }
        ReverseIterator operator-(size_type n) const { return ReverseIterator(ptr + n); }
        size_type operator-(const ReverseIterator& other) const { return other.ptr - ptr; }
        bool operator==(const ReverseIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const ReverseIterator& other) const { return ptr != other.ptr; }
    };

private:
    size_type _size;
    size_type _capacity;
    pointer _arr;

    void reallocate(size_type newCapacity) {
        if (newCapacity <= _capacity) return;
        pointer newArr = reinterpret_cast<pointer>(::operator new(sizeof(T) * newCapacity));
        for (size_type i = 0; i < _size; ++i) {
            new (newArr + i) T(_arr[i]);
            _arr[i].~T();
        }
        if (_arr) ::operator delete(_arr);
        _arr = newArr;
        _capacity = newCapacity;
    }

public:
    vector() noexcept : _size(0), _capacity(4), _arr(reinterpret_cast<pointer>(::operator new(sizeof(T) * _capacity))) {}

    explicit vector(size_type n) : _size(n), _capacity(n) {
        _arr = reinterpret_cast<pointer>(::operator new(sizeof(T) * _capacity));
        for (size_type i = 0; i < _size; ++i) {
            new (_arr + i) T();
        }
    }

    vector(const vector& other) : _size(other._size), _capacity(other._capacity) {
        _arr = reinterpret_cast<pointer>(::operator new(sizeof(T) * _capacity));
        for (size_type i = 0; i < _size; ++i) {
            new (_arr + i) T(other._arr[i]);
        }
    }

    vector& operator=(const vector& other) {
        if (this != &other) {
            for (size_type i = 0; i < _size; ++i) {
                _arr[i].~T();
            }
            ::operator delete(_arr);
            _size = other._size;
            _capacity = other._capacity;
            _arr = reinterpret_cast<pointer>(::operator new(sizeof(T) * _capacity));
            for (size_type i = 0; i < _size; ++i) {
                new (_arr + i) T(other._arr[i]);
            }
        }
        return *this;
    }

    ~vector() {
        for (size_type i = 0; i < _size; ++i) {
            _arr[i].~T();
        }
        if (_arr) ::operator delete(_arr);
    }

    reference at(size_type n) {
        if (n >= _size) throw 1;
        return _arr[n];
    }

    const_reference at(size_type n) const {
        if (n >= _size) throw 1;
        return _arr[n];
    }

    Iterator begin() noexcept { return Iterator(_arr); }
    Iterator end() noexcept { return Iterator(_arr + _size); }

    ConstIterator cbegin() const noexcept { return ConstIterator(_arr); }
    ConstIterator cend() const noexcept { return ConstIterator(_arr + _size); }

    ReverseIterator rbegin() noexcept { return ReverseIterator(_arr + _size - 1); }
    ReverseIterator rend() noexcept { return ReverseIterator(_arr - 1); }

    reference back() { return _arr[_size - 1]; }
    const_reference back() const { return _arr[_size - 1]; }

    reference front() { return _arr[0]; }
    const_reference front() const { return _arr[0]; }

    pointer data() noexcept { return _arr; }
    const_pointer data() const noexcept { return _arr; }

    size_type size() const noexcept { return _size; }
    size_type max_size() const noexcept { return static_cast<size_type>(-1) / sizeof(T); }
    size_type capacity() const noexcept { return _capacity; }
    bool empty() const noexcept { return _size == 0; }

    void reserve(size_type n) {
        if (n > _capacity) reallocate(n);
    }

    void resize(size_type n) {
        if (n > _capacity) reallocate(n > _capacity * 2 ? n : _capacity * 2);
        if (n > _size) {
            for (size_type i = _size; i < n; ++i) {
                new (_arr + i) T();
            }
        } else if (n < _size) {
            for (size_type i = n; i < _size; ++i) {
                _arr[i].~T();
            }
        }
        _size = n;
    }

    void resize(size_type n, const T& val) {
        if (n > _capacity) reallocate(n > _capacity * 2 ? n : _capacity * 2);
        if (n > _size) {
            for (size_type i = _size; i < n; ++i) {
                new (_arr + i) T(val);
            }
        } else if (n < _size) {
            for (size_type i = n; i < _size; ++i) {
                _arr[i].~T();
            }
        }
        _size = n;
    }

    void assign(size_type n, const T& val) {
        clear();
        resize(n);
        for (size_type i = 0; i < n; ++i) {
            new (_arr + i) T(val);
        }
    }

    void clear() noexcept {
        for (size_type i = 0; i < _size; ++i) {
            _arr[i].~T();
        }
        _size = 0;
    }

    Iterator insert(Iterator position, const T& val) {
        size_type pos = position - begin();
        if (_size == _capacity) reallocate(_capacity ? _capacity * 2 : 1);
        for (size_type i = _size; i > pos; --i) {
            new (_arr + i) T(_arr[i - 1]);
            _arr[i - 1].~T();
        }
        new (_arr + pos) T(val);
        ++_size;
        return begin() + pos;
    }

    Iterator erase(Iterator position) {
        size_type pos = position - begin();
        _arr[pos].~T();
        for (size_type i = pos; i < _size - 1; ++i) {
            new (_arr + i) T(_arr[i + 1]);
            _arr[i + 1].~T();
        }
        --_size;
        return begin() + pos;
    }

    Iterator erase(Iterator first, Iterator last) {
        size_type pos = first - begin();
        size_type count = last - first;
        for (size_type i = pos; i < pos + count; ++i) {
            _arr[i].~T();
        }
        for (size_type i = pos; i < _size - count; ++i) {
            new (_arr + i) T(_arr[i + count]);
            _arr[i + count].~T();
        }
        _size -= count;
        return begin() + pos;
    }

    void push_back(const T& val) {
        if (_size == _capacity) reallocate(_capacity ? _capacity * 2 : 1);
        new (_arr + _size) T(val);
        ++_size;
    }

    void pop_back() {
        if (_size > 0) {
            _arr[_size - 1].~T();
            --_size;
        }
    }

    template<typename... Args>
    Iterator emplace(Iterator position, Args&&... args) {
        size_type pos = position - begin();
        if (_size == _capacity) reallocate(_capacity ? _capacity * 2 : 1);
        for (size_type i = _size; i > pos; --i) {
            new (_arr + i) T(_arr[i - 1]);
            _arr[i - 1].~T();
        }
        new (_arr + pos) T(args...);
        ++_size;
        return begin() + pos;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (_size == _capacity) reallocate(_capacity ? _capacity * 2 : 1);
        new (_arr + _size) T(args...);
        ++_size;
    }

    void swap(vector& other) noexcept {
        pointer tmp_arr = _arr;
        size_type tmp_size = _size;
        size_type tmp_capacity = _capacity;
        _arr = other._arr;
        _size = other._size;
        _capacity = other._capacity;
        other._arr = tmp_arr;
        other._size = tmp_size;
        other._capacity = tmp_capacity;
    }

    reference operator[](size_type n) { return _arr[n]; }
    const_reference operator[](size_type n) const { return _arr[n]; }
};
}

#endif // VECTOR_H
