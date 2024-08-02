# Custom String Class Implementation

This project implements a custom string class `MyString` in C++. The `MyString` class demonstrates various string operations and features, including concatenation, comparison, substring extraction, and more. The implementation focuses on providing a foundational understanding of operator overloading and dynamic memory management in C++.

## Features

- **String Concatenation**: Overloaded `+` operator to concatenate two `MyString` objects.
- **Comparison**: Overloaded `<` operator to compare two `MyString` objects based on their ASCII values.
- **Subscript Operator**: Overloaded `[]` operator to access individual characters in the string.
- **Substring Extraction**: Overloaded `()` operator to extract a substring from a `MyString` object.
- **Assignment Operator**: Overloaded `=` operator to assign one `MyString` object to another.
- **Input/Output Stream Overloading**: Overloaded `<<` and `>>` operators for easy input and output of `MyString` objects.
- **Empty String Check**: Overloaded `!` operator to check if the string is empty.

## Compilation Instructions

To compile and run the file, follow these instructions:

1. **Ensure you have a C++ compiler installed** (e.g., g++, clang++).

2. **Compile the code** using the following command:
   ```bash
   g++ -o custom_string custom_string.cpp
3. **Run the executable with the following command:**
   ```bash
   ./custom_string

## Note
- Ensure that you handle memory management properly, as the MyString class uses dynamic memory allocation.
- The program includes basic tests for the class functionality. You can extend or modify the tests to suit your needs.

If you encounter any issues or have questions, please feel free to reach out for assistance. Happy coding!
