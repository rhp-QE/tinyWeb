#include <cstdio>
#include <iostream>
#include <memory>
#include "Coroutine/Coroutine.h"

using namespace QE::base;
using namespace std;

struct args {
    int n;
};

static void
foo(Scheduler* s,int i) {

    int start = i;
    for(int i = 0; i < 5; i++) {
        ::printf("coroutine %d : %d\n", s->running(), start + i);
        s->yield();
    }
}

static void
test(Scheduler* s) {
    args arg1 = { 0 };
    args arg2 = { 200 };

    ptrdiff_t co1 = s->add([s](){foo(s,0);;});
    ptrdiff_t co2 = s->add([s](){foo(s,200);;});
    printf("main start\n");
    while((*s)[co1] && (*s)[co2]) {
        if((*s)[co1])
            s->resume(co1);
        if((*s)[co2])
            s->resume(co2);
    }
    printf("main end\n");
}
using namespace::std;

struct node{
    node()=default;
    ~node(){
        cout<<"dstory node"<<endl;
    }
};

int
main() {
    shared_ptr<node> sp(new node[2],[](node* ptr){delete [] ptr;});
    {
        sp.reset();
        cout<<"---------"<<endl;
        sp=std::move(shared_ptr<node>(new node[2],[](node* ptr){delete[]ptr;}));
    }



    // Scheduler* s = new Scheduler();
    // test(s);

    return 0;
}