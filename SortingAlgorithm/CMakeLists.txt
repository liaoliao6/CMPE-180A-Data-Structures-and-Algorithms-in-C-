cmake_minimum_required(VERSION 3.16)
project(SortingAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortingAlgorithm SortTests.cpp DataAllZeros.h DataGenerator.h DataRandom.cpp DataRandom.h DataReverseSorted.h DataSorted.h Element.cpp Element.h InsertionSort.cpp InsertionSort.h LinkedList.h ListSorter.cpp ListSorter.h MergeSort.cpp MergeSort.h Node.h QuickSortOptimal.cpp QuickSortOptimal.h QuickSortSuboptimal.cpp QuickSortSuboptimal.h QuickSorter.cpp QuickSorter.h SelectionSort.cpp SelectionSort.h ShellSortOptimal.cpp ShellSortOptimal.h ShellSortSuboptimal.cpp ShellSortSuboptimal.h Sorter.cpp Sorter.h VectorSorter.cpp VectorSorter.h LinkedList.cpp)