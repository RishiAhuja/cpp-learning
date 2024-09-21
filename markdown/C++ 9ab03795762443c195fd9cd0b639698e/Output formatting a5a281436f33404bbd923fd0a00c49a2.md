# Output formatting

1. **`std::flush` :**
    
    Normally, when you use `std::cout` to print something, the output is first stored in a buffer before being sent to the console. This buffering helps improve performance, as writing directly to the console for every single character can be slow.
    
    However, sometimes you may want to force the output to be displayed immediately, rather than waiting for the buffer to fill up. That's where `std::flush` comes in. When you use `std::cout << "something" << std::flush;`, it tells the system to immediately send the "something" text to the console, without waiting.
    
    The main reason you might want to use `std::flush`is if you need to see the output right away, such as when you're printing progress updates or debugging information. Otherwise, it's generally better to let the buffering happen automatically, as it can improve the overall performance of your program.
    
2. **`<iomanip>` :**
    
    The `<iomanip>` header in C++ provides a set of manipulators that allow you to control the formatting of input and output operations.
    
    - `setw(int n)`: Sets the field width for the next output operation to `n` characters.
        - `setw()` sets the width of the 
        output field for the subsequent output operation only. It does not 
        affect the width of the entire output line.
        
        ```cpp
        int col_width {20};
            
        std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
        std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
        std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
        std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;
        std::cout << std::setw(col_width) <<  "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width/2) << "21" << std::endl;
        std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width/2) <<"27" << std::endl;
        std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width/2) << "29" << std::endl;
        ```
        
        ```cpp
                    Lastname           Firstname       Age
                      Daniel                Gray        25
                     Stanley               Woods        33
                      Jordan              Parker        45
                         Joe                Ball        21
                        Josh                Carr        27
                      Izaiah            Robinson        29
        ```
        
        - this is right justified by default.
        - `left`, `right`, or `internal` stream manipulators can be used to control the justification of the output within the specified width.
            
            ```cpp
            std::cout << std::left;
            ```
            
        - Internal justification has the sign as left justified and the data right justified.
            
            ```cpp
            std::cout << std::setw(10) << std::internal << -123 << std::endl;
            ```
            
            ```cpp
            -     123
            ```
            
    - `setprecision(int n)` :
        - Sets the floating-point precision for the next output operation to `n` digits.
    - `setfill(char c)`: ****
        - used to set the fill character that is used to pad the output when the value being printed is shorter than the specified field width.
        
        ```cpp
        std::cout << std::setfill('-');
        ```
        
        ```cpp
        ------------Lastname-----------Firstname-------Age
        --------------Daniel----------------Gray--------25
        -------------Stanley---------------Woods--------33
        --------------Jordan--------------Parker--------45
        -----------------Joe----------------Ball--------21
        ----------------Josh----------------Carr--------27
        --------------Izaiah------------Robinson--------29
        ```
        
    - `std::setbase`:
        - The syntax is `setbase(int base)` , where `base` can be:
            - `10` for decimal (`dec`)
            - `16` for hexadecimal (`hex`)
            - `8` for octal (`oct`)
3. **`std::uppercase;` :**
    
    changes terminal output to strict uppercase
    
    ```cpp
    **std::cout << std::uppercase;**
    ```
    
4. **`std::noshowpos` :**
    
    When the `showpos` format flag is not set, no plus signs (`+`) precede positive values inserted in the output stream.
    
    It is defined in the `<ios>` header.
    
    ```cpp
    std::cout << std::noshowpos;
    ```