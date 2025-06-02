#include<iostream>

//Every variable that we make are stored in memory in a particular space/cell that each space has some hexadecimal value address.
//Address can be printed using (Address of operator)&(amperand) operator.
//Pointer is a special variable that stores the address of other vaiables
//Syntax we use * operator to tell that it's a pointer
//As pointer is a variable its initialization is same as normal variable just add * to datatype telling that this is a pointer
//We also have to tell data type of pointer as its a variable so the data type of the address which we gonna store will be the datatype of the 
//pointer

int main()
{
    int a = 12346;
    int* ptr = &a;

    std::cout << &a << " ";     //as only a will give its container value but we need address so will use &(address of operator).
    std::cout << ptr<< " ";
    std::cout << &ptr << "\n";

    //Pointer to Pointer
    //int* -> datatype of storing variable i.e. ptr so ptr2 will be pointer of int* i.e. int**
    int** ptr2 = &ptr;
    std::cout << ptr2 << " ";

    //Dereference operator -> *(asterisk) known as value at address(to get the value at a particular address)
    std::cout << *ptr << "\n";      //value at address of ptr = &a i.e at value at address of a
    std::cout << *&ptr << "\n";      //value at address of &ptr i.e  address of a

    //Null pointer
    int* ptr3; 
    std::cout << ptr3 << " ";       //Its giving as a grabage value so counterattack this we have null pointer
    ptr3 = NULL;    //Which point to null -> 0x0
    std::cout << ptr3 << " ";
    //we can't dereference null pointer it gives an error i.e, segmentation fault(trying to access a memory which is not accesssibe)
    // std::cout << *ptr3; -> program terminates


    //Array pointer are constant pointers
    int arr[] = {1, 2, 3};  //array are also pointer which points to 0 index address
    // arr = &a; -> gives error lvalue(left value) must be modifiable

    //Pointer airthmetic -> if we increment pointer by 1 the pointer data type size will be added to address
    int *ptr4 = &a;
    std::cout << ptr4 <<" ";
    ptr4++;     //increment by 1 means int -> 4 byte will be added to address
    std::cout << ptr4 << " ";
    //same addition and subtraction will be performed
    //This conecpt is used to use array different values and indexes/
    std::cout << "\n";

    for(int i=0;i<3;i++)
    {
        std::cout<< *(arr+i) << " ";
    }

    //Addition of two pointers in not allowed but subtraction is allowed
    //Subtraction between two pointers gives the no of data types can be stored between them
    int *ptr5 = ptr4+2;
    std::cout << "\n" << ptr5 - ptr4 ;

    return 0;
}