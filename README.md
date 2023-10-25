# Custom-C-Data-Structures Library

Custom-C-Data-Structures is a header-only C library that provides a simple and efficient dynamic array implementation. It is designed to be easy to integrate into your C projects, allowing you to manage dynamic arrays of various data types with ease. This library is intended to be the foundation for future data structures like **queues**, **stacks**, and **hashmaps**.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [API Documentation](#api-documentation)
4. [Contributing](#contributing)
5. [License](#license)

## Introduction

The Custom-C-Data-Structures library provides a dynamic array data structure (called `c_vector`) that can be used to store elements of any data type. It is designed for simplicity and efficiency. The library allows you to create, manipulate, and manage dynamic arrays with the following operations:

- Initialize a dynamic array.
- Push elements onto the array.
- Pop elements from the array.
- Insert elements at a specific index.
- Erase elements from a specific index.
- Get and set elements at a specific index.
- Iterate through the array.
- Clear the array.
- Reserve and shrink the capacity of the array.
- Check if the array is empty.
- Swap elements within the array.

Please note that this library is a work in progress, and there is a TODO item in the code to add a sorting function, which will be implemented in a future release.

## Usage

To use the Custom-C-Data-Structures library in your C project, follow these steps:

1. Copy the `c_vector.h` header file into your project directory.
2. Include the header file in your C source code.

   ```c
   #include "c_vector.h"
   ```

3. You can then create and use dynamic arrays by following the API documentation provided in the next section.

```c
// Example usage of the library:
#include <stdio.h>
#include "c_vector.h"

int main() {
    // Initialize a dynamic array of integers with a capacity of 10.
    c_vector int_vector = v_new(int, 10);

    // Push some values into the array.
    for (int i = 0; i < 10; i++) {
        v_push(int, int_vector, i);
    }

    // Iterate through the array and print its elements.
    for (int *ptr = v_begin(int_vector); ptr < v_end(int_vector); ptr++) {
        printf("%d ", *ptr);
    }

    // Free the memory used by the array.
    v_free(int_vector);

    return 0;
}
```

## API Documentation

For detailed information on how to use the library and its functions, refer to the comments within the `c_vector.h` file. The comments provide explanations and usage examples for each function.

## Contributing

This library is open to contributions from the community. If you would like to contribute to the development of this library or have suggestions for improvements, please create a pull request on the [GitHub repository](https://github.com/villam27/Custom-C-Data-Structures).

## License

Custom-C-Data-Structures is open-source software distributed under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute it for your projects. Please review the license for the complete terms and conditions.