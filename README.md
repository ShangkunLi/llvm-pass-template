# llvm-pass-template
Since the [method](https://llvm.org/docs/WritingAnLLVMPass.html#quick-start-writing-hello-world) given in documentation need to put your own pass in the directory `llvm-project/llvm/lib/Transforms` ,which is inconvenient for use.

In this repository, we provide with a complete LLVM pass template, which enables building a pass independently. 

It's for LLVM 17.0.

You can put this `llvm-pass-template` file anywhere you want.

To build this pass:
``` $ cd llvm-pass-template
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
```
Then you can find the `.so` file in `llvm-pass-template/build/Hello/libHelloPass.so`.


To run this pass:

You need to use clang to generate the `.bc`  file of your source code firstly.

```
$ clang -c -emit-llvm path/to/main.c -o path/to/main.bc
```
Then, you can run the pass to get the result.

```
$ opt -load path/to/llvm-pass-template/build/Hello/libHelloPass.so -hello path/to/main.bc -o /dev/null
```
