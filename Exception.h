
#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <exception>
class exception {
public:
    exception() = default;
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    virtual ~exception() = default;
    virtual const char* what() const = 0;
};

class DeckFileNotFound : public exception {

}
class DeckFileFormatError{};
class DeckFileInvalidSize{};



#endif //HW4_EXCEPTION_H
