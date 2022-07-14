cmake_minimum_required(VERSION 2.8)
project(Cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cryptography main.cpp ciphertext.cpp ciphertext.h)