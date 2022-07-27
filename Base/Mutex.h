//
// Created by 27673 on 2022/7/17.
//

#ifndef TINYWEB_MUTEX_H
#define TINYWEB_MUTEX_H

#include "../exhead.h"

//-----如果  使用了 clang 则使线程安全注解
#if defined(__clang__) && (!defined(SWIG))
#define THREAD_ANNOTATION_ATTRIBUTE__(x)   __attribute__((x))
#else
#define THREAD_ANNOTATION_ATTRIBUTE__(x)   // no-op
#endif

#define CAPABILITY(x) \
  THREAD_ANNOTATION_ATTRIBUTE__(capability(x))

#define GUARDED_BY(x) \
  THREAD_ANNOTATION_ATTRIBUTE__(guarded_by(x))

#define PT_GUARDED_BY(x) \
  THREAD_ANNOTATION_ATTRIBUTE__(pt_guarded_by(x))

namespace QE {
    class CAPABILITY("mutex") Mutex : noncopyable {
    private:

    };
}


#endif //TINYWEB_MUTEX_H
