# When ‘new’ fails

When we try to allocate more than available memory then `new` fails:

```cpp
int *data = new int [10000000000000000];
```

Here we ran out of heap memory. 

However the case is almost impossible in normal conditions though, we can add safety measures to avoid this failure.

M1: **Exception mechanism via trying and catching.**

```cpp
try{
		//potentially going to fail
		int *data = new int [1000000000000];
}catch(std::exception& ex){
    std::cout << "Lol crashed: " << ex.what() << std::endl;
}
```

M2: **`std::nothrow`** 

if the allocation fails, `std::nothrow` adds a `nullptr` instead which can be detected before using the pointer.

```cpp
//if new fails, we will receive nullptr in data;
int *data = new(std::nothrow) int[1000000000000];

if(data!=nullptr){
      std::cout << "pointer addressed successfully" << std::endl;
  }else{
      std::cout << "can't allocate memory" << std::endl;
}
```