# Homework 6 (course MNXB11)

## Answers

### What does header guards prevent and how does `#pragma once` and `#ifndef #define #endif` differ?

### 1.3.1. (0.05 points) Explain the difference between the default access rules of struct and class.
### 1.3.2. (0.05 points) Why do we need our class to be derived from the TObject?
### 1.3.3. (0.20 points) Implement the class interface and verify that the class compiles without errors.

### 5. Speed Answers
| Example | vx (m/s) | vy (m/s) | vz (m/s) | Speed | Horizontal Speed |
|---------|----------|----------|----------|-------|------------------|
| A       | 0.30     | 0.40     | 0.00     | 0.5    | 0.5|
| B       | 0.30     | 0.40     | 0.50     | 0.707107 | 0.5 |

vz is not included in the Horizontal Speed, hence it does not affect that output. However it is included in the total speed.

### 6. Generate and store 10 000 measurements in `tree_file.root`
- Random seed: 42
- Generation parameters (I guess you meant these?):
```cpp
        vx = gRandom->Gaus(0.0, 0.30);
        vy = gRandom->Gaus(0.0, 0.30);
        vz = gRandom->Gaus(0.0, 0.30);
```