#ifndef QE_BASE_COPYABLE
#define QE_BASE_COPYABLE
//-------------------------------------

namespace QE {

class copyable {

public:
    copyable(const copyable&) = default;
    copyable& operator=(const copyable&) = default;

protected:
    copyable() = default;
    ~copyable() = default;
};

}
//-------------------------------------
#endif