# Generating random numbers

The `rand()` function generates pseudo-random numbers, and `srand()` is used to seed the random number generator (under `<ctime>` header). 

This will provide a number between `0` ~ `RAND_MAX` where `RAND_MAX` provides maximum that can be returned by the `rand()` function.

```cpp
int ran_num = std::rand();
```

The `srand()` function is used to set the seed for the `rand()` function, which affects the sequence of random numbers generated. By seeding with a changing value, such as the current time, you can ensure that the sequence of random numbers differs each time you run your program.

```cpp
std::srand(std::time(0));
//setting the seed for std::rand
```

**Generating random numbers in a range:**

```cpp
int rand_num = (std::rand() % 10) + 1; 
//will generate in [1 to 10]
```