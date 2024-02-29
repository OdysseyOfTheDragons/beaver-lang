# beaver-lang
A brand-new programming language to manipulate polynomials.

## Origin

It's been years I dream about building my own programming language. But years passed, and nothing happened... until last year. For homeworks in my scholl, we had to do a simple `C` program to manipulate polynomials.

Interested, I dug a little bit further and built a working REPL from scratch, in order for the teacher to use the functionalities without looking at the code (well, he still had, of course, but he could at least play a little bit with it).

From that day onwards, I read God knows how many websites, promising you to end the tutorial with a toy programming language. The thing is... I do not want to build a _toy_ programming language, but a full-featured programming language, oriented towards polynomials manipulation. And what's more: I don't want to build a LISP (people in the same situation as me will understand what I mean).

So here is a project, that will most likely die in a few months like every other project I started, but well, maybe I will learn things during that short time...

The name, _beaver_ comes from the fact that to build a language takes time, and needs to be strong enough to resist waves. I think the name fits well the way to build a language.

## The project

The project will start small, and I hope it will grow bigger and bigger over time.

Here are the specifications:

| **Specification** | Value |
| :--- | :--- |
| **Language** | `C`, `OCaml` |
| **Type** | Interpreted, Compiled |

Maybe some explanations are needed, no?

    At school, we learn the `C` and `OCaml` programming languages. So my language will be built using ONLY these two languages. I think most of the code will be pure `C`, but I may want to use `OCaml` sometimes (even for a single function which would take less than 10 lines in `C`, and which would take 20 in `OCaml` with the interfacing to `C`. But hey, am I dumb or am I not?)
    The language will be wholly interpreted, but there will be an option to compile: all the normally printed out strings will be stored, put in a dummy `C` program then compiled on the host machine. This is a trick, I know, but if it works, that's what counts.

## Inspirations

I always lose the websites I do find interesting. So, in order for this project not to lose its inspirations, I will list the websites below.

* https://blog.subnetzero.io/post/building-language-vm-part-00/

## Steps

The following steps I intend to take / took / am taking (choose three).

Joke apart, this will be a good starting point to understand what I am doing, and for me to copy myself later, if I ever need.

### Step 0

Initializing the project, searching for tutorials, loosing time in the search of a build system...

### Step 1

This is not an important part of the project, I think, but this is code I will be able to reuse later. This part is the _utils_. Well, not exactly. What I mean, is more something like a library of modules, that will be useful later. So a string module, as well as lists, vectors, stack, queue, hash maps...

And because I think what I found may come in handy later, here are some ideas to implement important features in `C`: polymorphism and types.

What I found is that one can use a `union` struct to hold multiple types in a single struct. One can think of it as a crossroad, where you choose the path you want, but as the saying goes: "all roads lead to Rome".

Example:
```c
typedef struct {
    enum { INT_TYPE, DOUBLE_TYPE, BOOL_TYPE, STRING_TYPE } type;
    union {
        IntType* intType;
        DoubleType* doubleType;
        BoolType* boolType;
        StringType* stringType;
    } data;
} ValueType;

void access(ValueType data) {
    switch (data.type) {
        case INT_TYPE:
            // data.data.intType;

        case STRING_TYPE:
            // data.data.stringType;

        ...
    }
}
```

And this would enable one to get what one wants. That way, and if every type in the union is a pointer, then the space used isn't much (an `enum` and a pointer), and an array could hold mutiple types.

The function can also return a new type to handle errors:

```c
enum { ERROR_EMPTY_TREE, ERROR_DIV_0 } error;

typedef struct {
    bool status; // success or failure?
    int errorCode; // an `error`
    ValueType ret; // returned value
} ReturnType;
```

An I can also create a `StringType` which holds more than just a `char*` to be faster in some cases:

```c
typedef struct {
    ArrayType* content;
    int hash;
};
```

This type has some advantages: the `content` of the string is `vector`, so to add or remove an element is $O(1)$ (constant time). Then the comparison for two strings can first start with the length (constant time access thanks to the use of the `vector`): different lengthes means different strings, then the hash: different hashes means different strings (or should I only compare the hashes?), and if everything is the same, then compare the strings.
