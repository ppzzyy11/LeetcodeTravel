#include<algorithm>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;

bool Mycompare(const int &a,const int &b)//should a be after b? It is opposite to sort()'s customed algorithm.
{
    return a>b;
}
//by default heap in cpp is a Max heap.
int main()
{
    vector<int> nums;
    srand(time(NULL));
    const int len = 50;
    const int MAX = 1000;
    for(int i=0;i<len;i++)
    {
        int num=rand()%MAX;
        nums.push_back(num);
        cout<<num<<" ";
    }
    //v.push_back(6);
    //std::cout << "before push_heap: ";
    //for (auto i : v) std::cout << i << ' ';
    //std::cout << '\n';
    //std::push_heap(v.begin(), v.end());

    cout<<endl;
    make_heap(nums.begin(),nums.end(),Mycompare);
    for(int i=0;i<len;i++)
    {
        cout<<nums.front()<<" ";
        pop_heap(nums.begin(),nums.end(),Mycompare);
        nums.pop_back();
    }

    return 0;
}
