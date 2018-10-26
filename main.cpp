#include <cstdlib>
#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    int v[] = {2,1,4,2,5,6,8,9,0,2};

    Heap<int> h(v, 10);
    //h.imprime();

    for(int i = 0; i < 10; i++){
        cout << h.remover() << endl;
    }
    puts("");
    h.imprimeFisico();

    //cout << h.remover() << endl;
    //cout << h.remover() << endl;

    return 0;
}