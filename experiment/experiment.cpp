//
// Created by admin on 05/07/2020.
//

#include<thread>
#include<cstdio>



void foo(int n) {
    for(int i=0;i<n;i++) {
        printf("%d\n",i);
        for(int j=0;j<5e8;j++);
    }
}

int main() {
    std::thread t(foo,3);
    t.join();
}