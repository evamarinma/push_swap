# PUSH_SWAP

## :bar_chart: An algorithm-based sorting program for 42 Cursus

### :open_book: Introduction
This program sorts a list of given integers (with a minimum of 2 numbers - a list of 1 num is already sorted :nerd_face:) in the least amount of movements. Sorting is limited to a given list of operations. The algorithm chosen for this project is the Turk Algorithm, we'll get back to it later on. Program creates 2 different empty stacks, stack a and stack b. The list of integers provided by the user through the terminal are parsed into stack a and then proceed to be sorted.

> [!WARNING]
> *If you're a 42 student: 42 projects must be CODED by yourself. Do not copy this project into yours. You will learn nothing by doing that. Exams are completed without Internet connection; you're alone with your IDE. The porpuse of these repositories is to show what we do at 42 and, yes, if you're stucked at some point, learn something new, but give peer-to-peer a chance first* 😉.

### :monocle_face: Operators allowed

* **SWAP A** -> Swaps the first 2 elements at the top of stack a. Terminal output: **sa**
* **SWAP B** -> Swaps the first 2 elements at the top of stack b. Terminal output: **sb**
* **DOUBLE SWAP** -> Executes sa and sb at the same time. Terminal output: **ss**
* **PUSH A** -> Takes the first element at the top of b and puts it at the top of a. Terminal output: **pa**
* **PUSH B** -> Takes the first element at the top of a and puts it at the top of b. Terminal output: **pb**
* **ROTATE A** -> Shifts up all elements of stack a by 1. The first element becomes the last one. Terminal output: **ra**
* **ROTATE B** -> Shifts up all elements of stack b by 1. The first element becomes the last one. Terminal output: **rb**
* **DOUBLE ROTATE** -> Executes ra and rb at the same time. Terminal output: **rr**
* **REVERSE ROTATE A** -> Shifts down all elements of stack a by 1. Terminal output: **rra**
* **REVERSE ROTATE B** -> Shifts down all elements of stack b by 1. Terminal output: **rrb**
* **DOUBLE ROTATE** -> Executes rra and rrb at the same time. Terminal output: **rrr**

### :dart: Example
The final code doesn't print the list of sorted integers, but for the purposes of this example, I'm using a function that does it so we can see the final result after using that list of operations:

<img width="466" height="191" alt="A screenshot from the terminal output for a given input" src="https://i.imgur.com/EM3OZnN.png" />

### :open_file_folder: Makefile
Here are some commands available to compile the code for this project.
```bash
# Compile whole project
make

# Erase .o files
make clean

# Erase .o files and executable
make fclean

# Compile libft
make -C libft
```

### :paperclip: User instructions

> [!IMPORTANT]
> *Push_swap program only works on Linux OS.

1. Clone this repository on your computer:
```
git clone git@github.com:evamarinma/push_swap.git
```

<br>

2. Use **'make'** command to compile the code.
<br>

3. You can now enter an input to be sorted as seen here:
```bash
# Enter different integers
./push_swap 2 6 1 7 3 5 4

# Enter the different integers as a string
./push_swap "2 6 1 7 3 5 4"

# You can even go crazy and mix them
./push_swap "2 6 1 7" 3 5 4
```

You will then see a list of the different instructions used to sort the list of numbers. If you want to check how many movements the program used, add ``| wc -l`` to the execution. Also, if you want to visualize how the sorting works, visit this [site](https://push.eliotlucas.ch/).

### :abacus: The algorithm
If you want to learn more about the algorithm used in this project, I highly recommend you visiting the [post](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) I used as a guide for the Turk algorithm, published by Yutong Deng, a student from Hive Helsinki.
### :hourglass_flowing_sand: Roadmap
Here are some known issues or improvements that will be implemented in the future.
- [ ] Implement double rotation into the code to reduce the number of operations :monocle_face: