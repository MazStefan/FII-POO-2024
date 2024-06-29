#include <iostream>
#include <vector>

template <class t>
void my_swap(t& v1,t& v2) {
    v1 = v2;
    v2 = v1;
}

template <class t>
void sort(std::vector<t> a) {
    int last = a.size()-1, newlast;

    auto f = my_swap<t>;
    f = nullptr;
    bool swapped = 1;
    while (last >= 0){

        swapped = 1;


        for (int i = 0; i <= last; i++) 
        { 
            if (a[i] > a[i + 1]) {
                f(a[i], a[i + 1]);      
                last = i;               
            }
        }
    }
}

template <class t>
void writeV(std::vector<t> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v1 = { 3, 2, 1, 14, 34, 21 };
    
    try {
        int initSize = v1.size();
        sort(v1);
        if (initSize != v1.size())
            throw "sort modifica lungimea vectorului";
        std::vector<int> v2 = { 34, 21, 14, 3, 2, 1 };
        if (v1 == v2)
            throw "sort sorteaza invers";
        v2 = v1;
        sort(v1);
        if (v1 != v2)
            throw "sort nu ofera acelasi raspuns la rulari repetate";
    }
    catch (std::exception& e) {
        std::cout << "Exceptie: " << e.what() << '\n';
        exit(1);
    }
    

}