# ifsc_prog_ii

## Compiling

### Single file programs

To compile a program with only one file, use the following command:

```bash
gcc -o program program.c
```

### Multiple file programs

To compile a program with multiple files, use the following command:

```bash
gcc main.c -o main.o -c
gcc module.c -o module.o -c
```

To link the object files and create the executable, use the following command:

```bash
gcc -o program main.o module.o
```

## Running

To run the program, use the following command:

```bash
./program
```