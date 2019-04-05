#include <iostream>

const int Data_one =10,Data_two =20;/**用于赋值**/

int main()
{
    using std::cout;
    using std::endl;
    /**自以为指向const对象的指针**/
    int test_one = Data_one;
    const int* pt_const = &test_one;
    cout<<"*pt_const = "<<*pt_const<<endl;

    int* pt_test_one = &test_one;
    *pt_test_one = Data_two;
    cout<<"*pt_const = "<<*pt_const<<endl;

    /**const的静态性**/
    const int test_two = Data_one;
    int* pt_test_two = const_cast< int* >(&test_two);
    *pt_test_two = Data_two;
    cout<<"test_two = "<<test_two<<'\t'<<"*pt_test_two = "<<*pt_test_two<<endl;

    /**volatile的可变性**/
    volatile const int test_three = Data_one;
    int* pt_test_three = const_cast< int* >(&test_three);
    *pt_test_three = Data_two;
    cout<<"test_three = "<<test_three<<'\t'<<"*pt_test_three = "<<*pt_test_three<<endl;
}
