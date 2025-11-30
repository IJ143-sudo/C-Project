# ASCII Function Plotter in C

A console-based graph plotting program that draws mathematical functions 
 on an ASCII grid using ANSI colors.

---

##  Features
- Plots multiple functions together  
- ANSI color support  
---

##  Project Structure

```
project/
│
├── src/
│   ├── main.c
│   ├── plot.c
│   ├── function.c
│
├── include/
│   ├── plot.h
│   ├── function.h
│
├── docs/
│   ├── ProjectReport.pdf   
│
├─sampleinput.txt 
│         
├── README.md   
  ```
---
## How to Compile and Run
```
bash
gcc main.c plot.c function.c -lm -o plotter
./plotter.exe
```
---





