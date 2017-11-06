// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
//It is expected that capacity and size should be the same. After running, it was seen that the Capacity increases in powers of 2 as the size reaches it. This is likely because as the vector increases in size, it allocates more memory so that consecutive memory does not have to be allocated each time the vector is increased in size;