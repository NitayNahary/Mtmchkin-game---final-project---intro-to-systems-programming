//
// Created by shach on 6/8/2022.
//

#ifndef HW4_SMARTPTR_H
#define HW4_SMARTPTR_H

template <class T>
class SmartPtr {
    T* m_ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = nullptr) { m_ptr = p; }

    SmartPtr& operator=(T* src){
        m_ptr = src;
        return *this;
    }
    // Destructor
    ~SmartPtr() { delete (m_ptr); }

    // Overloading dereferencing operator
    T& operator*() { return *m_ptr; }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return m_ptr; }
};

#endif //HW4_SMARTPTR_H
