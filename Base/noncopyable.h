#ifndef QE_BASE_NONCOPYABLE
#define QE_BASE_NONCOPYABLE
//-----------------------------
namespace QE {

class noncopyable {

public:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} // namespace QE

//-----------------------------
#endif