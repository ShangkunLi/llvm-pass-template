#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;  //since the functions from the include files live in the llvm namespace

namespace {  //using the anaonymous namespace, making the things declared inside of the anonymous namespace visible only to the current file
  struct HelloPass : public FunctionPass { //this declared the Pass Class Name (not the pass name) HelloPass is a subclass of FunctionPass
    static char ID;
    HelloPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override{  //declare a runOnFunction method to implement the detail operations
      errs() << "Hello:";
      errs().write_escaped(F.getName()) << "!\n";
      return false;
    }
  };
}

char HelloPass::ID = 0;  //initialize the pass ID

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static RegisterPass<HelloPass> X ("hello","Hello World Pass",  //this gives it a command line argument "hello", and a name "Hello World Pass"
                                  false /* Only looks at CFG */,
                                  false /* Analysis Pass */);