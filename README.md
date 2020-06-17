# Cryptotasks

## Cryptographic primitives projects tasks

## To run google tests

 For test.cpp 
 RUN using google test
 ```
 g++ test.cpp -lgtest #compilation
 ./a.out #run the file
 ```
# To run benchmarks :

## For compilation :
```
g++ benchmarktask.cpp -std=c++11 -isystem benchmark/include \
  -Lbenchmark/build/src -lbenchmark -lpthread
```

## For executing :
```
./a.out
```
