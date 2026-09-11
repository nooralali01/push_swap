*This activity has been created as part of the 42 curriculum by nelali, salfaraw.*

# Push_swap

## Description

**push_swap** is an algorithmic sorting project where the goal is to sort a list of integers using two stacks (`a` and `b`) and a restricted set of operations.  
The challenge is not only to sort the data correctly, but to do so efficiently by minimizing the number of operations.

The program analyzes the input, measures how disordered it is, and selects an appropriate sorting strategy based on the input size, disorder level, or explicit user flags.

This project emphasizes:
- Algorithmic complexity
- Data structure manipulation
- Optimization under constraints
- Clean, norm-compliant C code

---

## Instructions

### Compilation

```bash
make
```

## Usage
./push_swap [OPTIONS] [numbers]

## Examples
./push_swap 5 4 3 2 1

./push_swap --simple 3 1 2

./push_swap --medium 8 3 5 1 9

./push_swap --complex 4 67 3 87 23

./push_swap --adaptive 10 2 8 4 6

## Checker (example)
./push_swap 5 4 3 2 1 | ./checker_linux 5 4 3 2 1

## Implemented Operations
The following stack operations are supported:

- sa, sb, ss – swap operations
- pa, pb – push operations
- ra, rb, rr – rotate operations
- rra, rrb, rrr – reverse rotate operations
All operations strictly follow the project specifications and update internal counters when benchmark mode is enabled.

## Strategies & Algorithms
This project implements four distinct strategies, as required by the subject.

1. Simple Strategy — O(n²)
- Used for very small inputs and low disorder.
- Based on minimum and maximum extraction
- Repeatedly pushes the smallest elements from stack A to B
- Rebuilds stack A in sorted order

2. Medium Strategy — O(n√n)
- Used for medium-sized inputs.
- Uses chunk-based sorting
- Input is normalized into ranks
- Stack A is divided into √n chunks
- Chunks are pushed to stack B and rebuilt in order

3. Complex Strategy — O(n log n)
- Used for large inputs or high disorder.
- Uses radix sort adaptation
- Values are normalized
- Sorting is performed bit by bit using stack operations

4. Adaptive Strategy
- The default behavior when no flag is provided.
- Computes the disorder metric before sorting
- Chooses:
- Simple strategy for low disorder
- Medium strategy for moderate disorder
- Complex strategy for high disorder
- This ensures efficient performance across different input types.

## Disorder Metric
Before any sorting is performed, the program computes a disorder value between 0 and 1.

** 0.0 → already sorted

** 1.0 → worst possible order

The metric is calculated by counting inversions between all pairs of elements and is used by the adaptive strategy to choose the optimal algorithm.

## Benchmark Mode
When --bench is enabled, the program prints additional information to stderr after sorting:
- Disorder percentage
- Strategy used and its complexity class
- Total number of operations
- Count of each operation type

** Example:
  
./push_swap --bench 4 3 2 1

## Project Structure & Contributions

This project was developed collaboratively by two learners, with clear responsibility sharing:

** nelali: 
1) Stack implementation (doubly linked list)
2) Stack operations
3) Input parsing and validation

** salfaraw
1) Strategy flags handling
2) Sorting strategy selection logic
3) Disorder computation

Shared Work

- Algorithm design and implementaion
- Makefile and header implementation
- Main program implementaion
- Norminette compliance
- Debugging and testing
- Performance tuning and validation

## Resources

- 42 Subject PDF (Push_swap)
- Algorithm complexity references
- Stack-based sorting research
- Radix sort and chunk sorting documentation and YouTube videos

## AI Usage
AI tools were used responsibly to:
- Clarify algorithmic concepts
- Review logic and edge cases
- Improve code structure and readability

All AI-assisted content was reviewed, understood, and validated by the contributors.
