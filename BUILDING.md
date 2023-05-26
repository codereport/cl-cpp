### Downloading GCC 13.1
```bash
# courtesy of Matt Godbolt & compiler explorer
curl -sL https://compiler-explorer.s3.amazonaws.com/opt/gcc-13.1.0.tar.xz | tar Jx
```

### Building
```bash
# Export needed variables for GCC 13.1
export CXX=/home/cph/gcc-13.1.0/bin/g++
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/gcc-13.1.0/lib64

# You might need to clear CMakeCache.txt
rm CMakeCache.txt

# Build Step 1
mkdir build & cd build

# Build Step 2
cmake -DCMAKE-CXX-COMPILER=/home/cph/gcc-13.1.0/bin/g++ ..
build -j32
