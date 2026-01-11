<h1>Project Title</h1>

<h3>Scientific Calculator in C Without math.h Library</h1>

<h2>Project Description</h2>

This project consists of developing a scientific calculator using the C programming language, implemented without using the standard mathematical library (math.h).
All mathematical functions are manually implemented using numerical methods, polynomial approximations, and bit-level manipulations, making this project both educational and low-level oriented.

The calculator runs in console mode and allows the user to perform a wide range of basic and advanced mathematical operations through an interactive menu.

<h2>Objectives</h2>

Understand how mathematical functions work internally

Implement scientific functions without relying on built-in libraries

Apply numerical methods such as Taylor series and Newton–Raphson method

Practice floating-point manipulation and bitwise operations

Strengthen skills in C programming and algorithmic thinking

<h2>Features</h2>
<h3>1. Basic Arithmetic Operations</h3>

Addition

Subtraction

Multiplication

Division (with division-by-zero protection)

<h3>2. Advanced Mathematical Operations</h3>

Factorial

Power function (xⁿ)

Absolute value

Reciprocal (1/x)

Root calculation of any order using Newton–Raphson method

<h3>3. Trigonometric Functions</h3>

Sine (sin x)

Cosine (cos x)

Tangent (tan x = sin x / cos x)

All trigonometric functions are implemented using Taylor series approximation with angle normalization.

<h3>4. Exponential and Logarithmic Functions</h3>

Exponential function exp(x)

Natural logarithm ln(x)

<h2>These functions are implemented using:</h2>

Polynomial approximations

Floating-point exponent and mantissa extraction

Binary manipulation of IEEE-754 floating-point format

Algorithms and Methods Used

Taylor Series Approximation for sin(x) and cos(x)

Polynomial approximation for exp(x)

Newton–Raphson Method for root calculation

Bitwise floating-point manipulation for logarithm computation

Iterative methods for factorial and power functions

Error Handling

Division by zero detection

Domain validation for ln(x), √x, inverse(x)

Protection against invalid operations

<h2>how to use it</h2>
gcc main.c -o main
./main

<h2>Conclusion</h2>

This scientific calculator is a complete and educational implementation that reproduces core mathematical functions from scratch.
By avoiding math.h, the project highlights how complex mathematical operations can be built using algorithms, approximations, and binary arithmetic, making it a strong example of applied computer science and numerical computing.
