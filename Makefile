CC=clang
FLAGS=-Wall

all: build

prereqs:
	sudo apt-get install clang-format clang-tidy clang-tools clang clangd libc++-dev libc++1 libc++abi-dev libc++abi1 libclang-dev libclang1 liblldb-dev libllvm-ocaml-dev libomp-dev libomp5 lld lldb llvm-dev llvm-runtime llvm python-clang
	sudo mkdir -p /usr/include/LLVM-C/
	sudo cp -r /usr/include/llvm-c-10/llvm-c/* /usr/include/LLVM-C/
	clear

build: token.o compiler.o

token.o: token.c token.h

compiler.o: compiler.c compiler.h