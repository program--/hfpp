# C++14 Hydrofabric Modeling

This repository contains a C++14 hydrofabric modeling implementation. This implementation takes inspiration from the [OGC WaterML HY_Features Model](https://docs.ogc.org/is/14-111r6/14-111r6.html) and the [Applications of HY_Features Engineering Report](https://docs.ogc.org/per/22-040.html) to represent a hydrofabric efficiently, but does not directly implement the HY_Features model.

## Getting Started

### Design

The design of this library has three core components: `hf::fabric`, `hf::catchment`, and `hf::nexus`. 

- `hf::fabric` is a *registry* containing all the catchments loaded into the running process, and provides lookup and ownership for these resources.
- `hf::catchment` is a class providing a conceptual, holistic catchment. Topological representations of a catchment are provided through the `hf::realization` class, a polymorphic base class.
- `hf::nexus` is a class providing a conceptual nexus/outlet. Typically nexuses will be represented by a POI, so nexus realizations are not channeled through the `hf::realization` class.

### Development

#### Prerequisites

This library requires the following:

- C++14 Compiler
    - gcc >= 5.0.0
    - clang >= 3.4
    - MSVC >= 19.10
- [CMake](https://cmake.org/)

#### Building From Source

1. Clone the repo
   ```
   git clone https://github.com/program--/hfpp.git
   ```

2. Enter the cloned directory
   ```
   cd hfpp
   ```

3. Build with CMake
   ```
   cmake -S . -B build
   cmake --build build
   ```

#### Running Tests

If `-DBUILD_TESTING` is enabled or following the above directions, then running the following will run the unit tests via CTest:

```
cd build
make test
```

This library uses [doctest]() as the unit testing framework. If you would like to run the doctest-based test runner instead of CTest, enter the `build` directory and run:

```
./tests/hfpp_tests
```

### Example

> TODO

## License

This library is distributed under the MIT License. See [`LICENSE`](LICENSE) for more information.
