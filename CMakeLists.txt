cmake_minimum_required(VERSION 3.17)
project(MyMenu)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyMenu main.cpp MyConMenu/CMenu.cpp MyConMenu/CMenu.h MyConMenu/CMenuItem.cpp MyConMenu/CMenuItem.h     "ExpTree/ExpTree.h" "ExpTree/ExpTree.cpp"  "MyError/MyError.h" "MyError/MyError.cpp")