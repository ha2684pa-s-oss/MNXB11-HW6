# Homework 6 (course MNXB11)
Everything for Homework 

## Running macros
Inside Apptainer root:
```root
.L MovingObject.cxx+
.x write.C
.x read.C
```
These are the commands I have used to run the macros. I am very well aware that there are a lot of things that can be improved in this code :) For the horizontal_speed_vs_vz.png I couldn't figure out how to fix the axis titles and such. Or rather, I tried for a little while and then I ran out of time so I let it be. Will make sure to have nicer plots in the project submission. 

I also wasn't entire sure which plots should be included in the submission since the final checks part states "both plots" but in the instructions I found four different plots mentioned (unless I misunderstood something) so I included all four.

## Answers to questions

### What does header guards prevent and how does `#pragma once` and `#ifndef #define #endif` differ?

### 1. (0.05 points) Explain the difference between the default access rules of struct and class.
The main difference is the default access level:
- In `struct`, all members are `public` by default while in `class` all members are `private` by default.

### 2. (0.05 points) Why do we need our class to be derived from the TObject?
    This allows the class to use ROOT's object infrastructure "automatically".


### 3. (0.20 points) Implement the class interface and verify that the class compiles without errors.
    I did this :) 

### 4. (0.10 points) Add the three velocity components to your class and initialize them correctly
    I did this too :) 

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


## Plots

![horizontal_speed_hist](/horizontal_speed_histogram.png)
![speed_hist](/speed_histogram.png)

![horizontal_speedvsvz](/horizontal_speed_vs_vz.png)
(Sorry for bad titles)

![vel_comp](/velocity_components.png)


