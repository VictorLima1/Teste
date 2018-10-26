#ifndef HEAP_HPP
#define HEAP_HPP

#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class Heap{
private:
    T v[100];
    int n;

    int fe(int i){
        return 2*i+1;
    }

    int fd(int i){
        return 2*i+2;
    }

    int pai(int i){
        return (i-1)/2;
    }

    void peneira(int i){
        if(fe(i) >= n)
            return;
        int mf = fe(i);
      
        if(fd(i) < n && v[fd(i)] > v[mf]){
            mf = fd(i);
        }

        if(v[i] < v[mf]){
            T temp = v[i];
            v[i] = v[mf];
            v[mf] = temp;
            peneira(mf);
        }

    }

public:

    Heap(T* v, int n){
        if(n>=100)
            exit(0);

        copy(v,v+n, this->v);
        this->n = n;

        for(int i=pai(n-1); i>= 0; i--){
            peneira(i);
        }

    }

    void imprime(){
        for(int i=0; i < n; i++){
            cout << v[i] << "\t";
        }
        cout << endl;
    }

    void imprimeFisico(){
        for(int i = 0; i < 10; i++){
            cout << v[i] << "\t";
        }
        cout << endl;
    }

    T remover(){
        T r = v[0];
        v[0] = v[n-1];
        v[n-1] = r;
        n--;
        for(int i = pai(n-1); i >= 0; i--){
            peneira(i);
        }

        return r;
    }

};

#endif