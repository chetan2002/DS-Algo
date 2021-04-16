#include<thread>
#include<iostream>
// using namespace std;

void my_thread_func(){
    // while(1){
        std::cout<<"Hello World"<<std::endl;
    // }
}
thread my_thread;
int main(int argc , char** argv){
    my_thread = thread(my_thread_func);
    std::cout<<"This is test"<<std::endl;
}