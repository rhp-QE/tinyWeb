//
// Created by 27673 on 2022/7/27.
//

#ifndef TINYWEB_COROUTINE_H
#define TINYWEB_COROUTINE_H

#include <functional>
#include <memory>
#include <ucontext.h>
#include <vector>


namespace QE {
namespace base {
class Coroutine;

class Scheduler;

//协程函数
typedef std::function<void(void)> CoroutineFunc;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;

class Coroutine {
public:
  typedef enum status { //协程的状态
    COROUTINE_DEAD,
    COROUTINE_READY,
    COROUTINE_RUNNING,
    COROUTINE_SUSPEND
  } status;

private:
  CoroutineFunc func_;       //协程函数
  Scheduler *scheduler_;     //协程调度器
  ucontext_t ucontext_;      //保存的上下文
  ptrdiff_t cap_;            //已分配的内存大小
  ptrdiff_t size_;           //协程栈大小
  Coroutine::status status_; //状态
  shared_ptr<char> stack_;   //栈  （存再堆中）
public:
  Coroutine(Scheduler *s, CoroutineFunc func);

  status getStatus() const { return this->status_; }

  void setStatus(Coroutine::status stat) { this->status_ = stat; }

  ucontext_t &getContext() { return ucontext_; }

  void saveStack(char *top);

  void inline runFunc(Scheduler *s);

  inline ptrdiff_t size() { return size_; }

  inline char *stack() { return stack_.get(); }

  inline bool dead() { return status_ == status::COROUTINE_DEAD; }
};

//--------------------------------------------

class Scheduler {
public:
  static const int STACK_SIZE = (1024 * 1024);
  static const int DEFAULT_COROUTINE = 16;

  Scheduler();

  virtual ~Scheduler();

  Scheduler &open();

  void close();

  ptrdiff_t add(CoroutineFunc func);

  void resume(int id);

  inline Coroutine::status status(int id) const;

  int running();

  void yield();

  inline Coroutine *operator[](size_t key) { return co_[key].get(); };

private:
  static void mainfunc(uint32_t low32, uint32_t hi32);

  //私有变量
  char stack_[STACK_SIZE];
  ucontext_t main_;
  int coroutine_num_;
  int cap_;
  int running_;

  //协程列表
  vector<unique_ptr<Coroutine>> co_;
};
} // namespace base
} // namespace QE

#endif // TINYWEB_COROUTINE_H
