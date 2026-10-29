#include <cstddef> /// for std::size_t
#include <cassert> // for debug purposes

namespace osc {

/// implementation details.
///@note client code should not touch this
namespace impl {

/// Manages the push/pop of the stack pointer
///@param sz: size in bytes of an unit object
template<std::size_t sz>
class Arena {

public:
    Arena() : size(0) {
#ifndef NDEBUG
    std::size_t _oldStackPos;
#endif
    }

    /// restore stack pointer
    ~Arena() {
    ///@todo restore stack pointer
#ifndef NDEBUG
    ///@todo get current stack pointer
    std::size_t _newStackPos = 0;
    assert((_oldStackPos == _oldStackPos) &&
            "corrupt stack address should be the same as original")
#endif
    }

public:
///@todo yada yada, implement
    // push(const unsigned n) /// increase capacity by n elements
    // pop() /// decrease capacity by n elements
    std::size_t size() const { return size; }
private:
    std::size_t size; // number elements of 'sz' bytes
#ifndef NDEBUG
    std::size_t _oldStackPos;
#endif
};

}

/// Implements a Vector interface
template<typename T>
class Vector {
public:
    Vector() : size(0 ), arena()
        {}

// Element access
    /// at()
    // operator[]
    // front()
    // back()

// Iterators
    // begin()
    // end()

// Capacity
    // empty()
    // size()

// Modifiers
    // push_back()
    // pop_back()

///@note basic functionality implement the rest as needed

private:
    std::size_t size; /// number of T elements
    impl::Arena<sizeof(T)> arena;
};

} // namespace osc
