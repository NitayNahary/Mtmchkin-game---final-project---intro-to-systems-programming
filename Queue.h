#ifndef HW4_QUEUE_H
#define HW4_QUEUE_H

namespace Iterators{
    template<class T> class Iterator;
    template<class T> class ConstIterator;
}

template<class T> class Queue{
    struct Node;
public:
    //we are gonna act like namespace Iterators classes Iterator and ConstIterator are "nested" in queue
    // this will allow us to do global functions for them and help the compiler.
    friend class Iterators::Iterator<T>;
    friend class Iterators::ConstIterator<T>;
    typedef Iterators::Iterator<T> Iterator;
    typedef Iterators::ConstIterator<T> ConstIterator;
    class EmptyQueue{};

    /***
     * empty c'tor for ConstQueue:
     *                  @field m_front - initialized to NULL
     *                  @field m_back - initialized to NULL
     *                  @field m_size - initialized to 0
     *                      @return instance of ConstQueue
     */
    Queue(): m_front(nullptr), m_back(nullptr), m_size(0){}
    /***
    * copy-assignment c'tor for ConstQueue:
    *                 @param src - copied to this
    *                      @return reference of ConstQueue
    */
    Queue& operator=(const Queue& src);
    /***
    * copy c'tor for ConstQueue:
    *                 @param src - copied to this
    *                      @return instance of ConstQueue
    */
    Queue(const Queue& src);
    /***
    * d'tor for ConstQueue:
    *               deep deletes ConstQueue
    */
    ~Queue();

    /*
     * pushBack - pushes value to end of ConstQueue
     *       @param value - pushed back to last
     *       @exception - throws a bad_alloc when can't create new link.
     */
    void pushBack(const T& value);
    /*
     * front @return ref of the first value
     *          @exceptions - empty ConstQueue throws emptyQueue exception.
     */
    void push(const T& value);
    /*
     * front @return ref of the first value
     *          @exceptions - empty ConstQueue throws emptyQueue exception.
     */
    T& front();
    /*
    * front @return ref of the first value
    *          @exceptions - empty ConstQueue throws emptyQueue exception.
    */
    T front() const;
    /*
    * popFront deletes the first value
    *          @exceptions - empty ConstQueue throws emptyQueue exception.
    */
    void popFront();
    /*
     * size() @return queue length
     */
    int size() const;
    /*
     * begin() @return Iterator of start of ConstQueue
     */
    Iterator begin();
    /*
    * end() @return Iterator of end of ConstQueue
    */
    Iterator end();
    /*
    * begin() @return ConstIterator of start of ConstQueue
    */
    ConstIterator begin() const;
    /*
    * end() @return ConstIterator of end of ConstQueue
    */
    ConstIterator end() const;

private:
    Node *m_front; //First in ConstQueue
    Node *m_back; //Last in ConstQueue
    int m_size;  //Size of ConstQueue

    //Implementation of the Nodes of the linkedList ConstQueue
    struct Node
    {
    private:
        /***
        Node C'tor - Constructs a new Node.
                         @param value - initiates T with value
                         @field m_next - initiated to NULL
                         @return
                                An instance of Node
        */
        explicit Node(const T& value): m_value(value), m_next(nullptr){}
    public:
        friend Queue<T>;
        Node(const Node& src) = default;
        Node& operator=(const Node& src) = default;
        ~Node() = default;

        T m_value; //Node value
        Node* m_next; //Node next Node
    };
};
///! there is no way is C++ to create a global function for a nested class of a template so after research we found out that using namespace,
///! friend-class and a little trickery we can create global functions for "nested" Iterators.
/// This is only for helping the compiler find the correct functions
namespace Iterators{
    template<class T> class Iterator
    {
        friend class Queue<T>;
        /***
        * c'tor for Iterator:
        *                 @param m_index - initiates index
        *                      @return instance of ConstQueue::Iterator
        */
        explicit Iterator(Queue<T>* myQueue,typename Queue<T>::Node* index): m_myQueue(myQueue), m_index(index) {}
    public:
        class InvalidOperation{};
        /*
         * overload operator * - returns Iterator's element of type T
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        T& operator*();
        /*
         * overload operator ++ - advance the Iterator
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        Iterator& operator++();
        /*
         * overload operator ++ - advance the Iterator
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        Iterator operator++(int);
        /*
         * bool overload operator == - check if two Iterators are the same
         *          @return - true/false
         */
        template<class U> friend bool operator==(const Iterator<U>& iterator1,const Iterator<U>& iterator2);
        /***
        * default copy c'tor for Iterator:
        *                 @param Iterator- copied to this
        *                      @return instance of ConstQueue::Iterator
        */
        Iterator(const Iterator&) = default;
        /***
        * copy-assignment c'tor for Iterator:
        *                 @param Iterator - copied to this
        *                      @return reference of ConstQueue::Iterator
        */
        Iterator& operator=(const Iterator&) = default;
    private:
        const Queue<T>* m_myQueue; //my Queue
        typename Queue<T>::Node* m_index; //Queue index
    };

    template<class T>
    T &Iterator<T>::operator*() {
        if(!m_index){
            throw InvalidOperation();
        }
        return m_index->m_value;
    }
    template<class T>
    Iterator<T> &Iterator<T>::operator++() {
        if(!m_index){
            throw InvalidOperation();
        }
        m_index = m_index->m_next;
        return *this;
    }
    template<class T>
    Iterator<T> Iterator<T>::operator++(int) {
        Iterator result = *this;
        ++*this;
        return result;
    }
    template<class T>
    bool operator==(const Iterator<T>& iterator1, const Iterator<T>& iterator2) {
        return (iterator1.m_index==iterator2.m_index && iterator1.m_myQueue == iterator2.m_myQueue);
    }
    /*
    * bool overload operator != - check if two Iterators are not the same
    *           @return - true/false
    */
    template<class T>
    bool operator!=(const Iterator<T>& iterator1, const Iterator<T>& iterator2) {
        return !(iterator1==iterator2);
    }

    template<class T> class ConstIterator
    {
        friend class Queue<T>;
        /***
        * c'tor for ConstIterator:
        *                 @param m_index - initiates index
        *                      @return instance of ConstQueue::ConstIterator
        */
        explicit ConstIterator(const Queue<T>* myQueue,const typename Queue<T>::Node* thisIndex): m_myQueue(myQueue), m_index(thisIndex) {}
    public:
        class InvalidOperation{};
        /*
         * overload operator * - returns ConstIterator's element of type T
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        T operator*() const;
        /*
         * overload operator ++ - advance the ConstIterator
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        ConstIterator& operator++();
        /*
         * overload operator ++ - advance the ConstIterator
         *          @exceptions - throws InvalidOperation if iterates to illegal place
         */
        ConstIterator operator++(int);
        /*
         * bool overload operator == - check if two ConstIterators are the same
         *          @return - true/false
         */
        template<class U> friend bool operator==(const ConstIterator<U>& iterator1,const ConstIterator<U>& iterator2);
        /***
        * default copy c'tor for ConstIterator:
        *                 @param ConstIterator- copied to this
        *                      @return instance of ConstQueue::ConstIterator
        */
        ConstIterator(const ConstIterator&) = default;
        /***
        * copy-assignment c'tor for ConstIterator:
        *                 @param ConstIterator - copied to this
        *                      @return reference of ConstQueue::ConstIterator
        */
        ConstIterator& operator=(const ConstIterator&) = default;
    private:
        const Queue<T>* m_myQueue;
        const typename Queue<T>::Node* m_index;//ConstQueue index
    };

    template<class T>
    T ConstIterator<T>::operator*() const {
        if(!m_index){
            throw InvalidOperation();
        }
        return m_index->m_value;
    }
    template<class T>
    ConstIterator<T> &ConstIterator<T>::operator++() {
        if(!m_index){
            throw InvalidOperation();
        }
        m_index = m_index->m_next;
        return *this;
    }
    template<class T>
    ConstIterator<T> ConstIterator<T>::operator++(int) {
        ConstIterator result = *this;
        ++*this;
        return result;
    }
    template<class T>
    bool operator==(const ConstIterator<T> &iterator1, const ConstIterator<T> &iterator2) {
        return (iterator1.m_index == iterator2.m_index && iterator1.m_myQueue == iterator2.m_myQueue);
    }
    template<class T>
    bool operator!=(const ConstIterator<T>& iterator1, const ConstIterator<T>& iterator2) {
        return !(iterator1==iterator2);
    }
}

// --------------------------------------------------- non - Member Queue Functions---------------------------------------------------------
/***
 * filter fun
 *          @param queue - the given queue to filter elements from
 *          @param condition - the filter function desired to filter queue
 *              @return new ConstQueue with elements from received queue that pass the condition given
 */
template<class T, typename Condition>
Queue<T> filter(const Queue<T> queue, const Condition condition)
{
    Queue<T> result;
    for (const T& elem : queue) {
        if(condition(elem)){
            result.pushBack(elem);
        }
    }
    return result;
}
/***
 * transform fun changes given queue elements with received transformation function
 *          @param queue - the given queue to change its elements
 *          @param transformation - the transformation function desired to transform queue elements
 */
template<class T,typename Transformation>
void transform(Queue<T>& queue,const Transformation transformation)
{
    for (T& elem : queue) {
        transformation(elem);
    }
}

// --------------------------------------------------- Queue Builder Functions---------------------------------------------------------------

template<class T>
Queue<T>::Queue(const Queue& src): m_front(nullptr), m_back(nullptr), m_size(0)
{
    *this = src;
}
template<class T>
Queue<T>& Queue<T>::operator=(const Queue& src)
{
    if(m_front == src.m_front) {
        return *this;
    }
    Queue temp;
    for(const T& elem : src){
        temp.pushBack(elem);
    }
    Node* temp_front = m_front;
    m_front = temp.m_front;
    m_back = temp.m_back;
    m_size = temp.m_size;
    temp.m_front = temp_front;
    return *this;
}
template<class T>
Queue<T>::~Queue()
{
    Node* current;
    while(m_front != nullptr)
    {
        current = m_front;
        m_front = m_front->m_next;
        delete current;
    }
    m_back = nullptr;
}
// ------------------------------------------------------ Queue Functions---------------------------------------------------------------------

template<class T>
T& Queue<T>::front()
{
    if(!m_front){
        throw EmptyQueue();
    }
    return m_front->m_value;
}
template<class T>
T Queue<T>::front() const{
    if(!m_front){
        throw EmptyQueue();
    }
    return m_front->m_value;
}
template<class T>
void Queue<T>::pushBack(const T& value)
{
    Node* temp = new Node(value);
    if(m_size == 0) { //first in should be entered from the front
        m_front = temp;
        m_back = m_front;

    }else{ //all else will be connected from the end
        m_back->m_next = temp;
        m_back = temp;
    }
    m_size++;
}
template<class T>
void Queue<T>::push(const T &value) {
    Node* temp = new Node(value);
    if(m_size == 0) { //first in should be entered from the front
        m_front = temp;
        m_back = m_front;
    }else{ //all else will be connected from the end
        temp->m_next = m_front;
        m_front = temp;
    }
    m_size++;
}
template<class T>
void Queue<T>::popFront()
{
    if(m_size < 1){
        throw EmptyQueue();
    }
    Node* temp = m_front;
    m_front = m_front->m_next;
    delete temp;
    m_size--;
}
template<class T>
int Queue<T>::size() const
{
    return m_size;
}

// --------------------------------------------------- Queue Iteration Functions---------------------------------------------------------

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(this,m_front);
}
template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this,nullptr);
}
template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(this, m_front);
}
template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this, nullptr);
}



#endif //HW4_QUEUE_H