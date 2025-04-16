# Bitwise Operations in C++

This tutorial covers the following common bitwise operations:
- AND (&)
- OR (|)
- XOR (^)
- NOT (~)
- Left Shift (<<)
- Right Shift (>>)

## AND Operation (&)
- Compares each bit of two numbers.
- If both bits are 1, the result is 1, otherwise 0.
- Use case: Masking specific bits.

### Visualization:
```
   5 -> 0000 0101
   3 -> 0000 0011
  5&3 -> 0000 0001 (1 in decimal)
```

## OR Operation (|)
- Compares each bit of two numbers.
- If either bit is 1, the result is 1.
- Use case: Setting specific bits.

### Visualization:
```
   5 -> 0000 0101
   3 -> 0000 0011
  5|3 -> 0000 0111 (7 in decimal)
```

## XOR Operation (^)
- Compares each bit of two numbers.
- Result is 1 if bits are different, otherwise 0.
- Use case: Toggle bits or swap variables.

### Visualization:
```
   5 -> 0000 0101
   3 -> 0000 0011
  5^3 -> 0000 0110 (6 in decimal)
```

## NOT Operation (~)
- Inverts all bits of the number.
- Use case: Negation or flipping bits.

## Left Shift (<<) and Right Shift (>>)
- Left Shift: Shifts bits to the left, filling with 0s.
  - Equivalent to multiplying by 2^n.
- Right Shift: Shifts bits to the right, discarding bits on the right.
  - Equivalent to dividing by 2^n.

### Example:
```
   5 << 1 -> 0000 1010 (10 in decimal)
   5 >> 1 -> 0000 0010 (2 in decimal)
```

## How to Run the Program
1. Compile with: `g++ BitwiseOperations.cpp -o BitwiseOperations`
2. Run the executable: `./BitwiseOperations`

## Output Example:
```
Initial values: a = 5, b = 3, shift = 1
AND Operation:
5 & 3 = 1
OR Operation:
5 | 3 = 7
XOR Operation:
5 ^ 3 = 6
NOT Operation:
~5 = -6
Left Shift Operation:
5 << 1 = 10
Right Shift Operation:
5 >> 1 = 2
```

## Conclusion
This tutorial demonstrates basic bitwise operations with examples and visualizations to help you understand the internal workings. Happy coding!

