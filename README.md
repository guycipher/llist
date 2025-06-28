A simple KISS linked list library written in C.

### Build it
```bash
mkdir -p build
cd build
cmake ..
cmake --build .

## Tests?
make test # OR ctest --verbose

## To install system wide you can do this manually.. for example on linux you'd do
sudo cp build/libllist.so /usr/local/lib/
sudo cp src/llist.h /usr/local/include/
sudo ldconfig 
```

### License
Apache v2