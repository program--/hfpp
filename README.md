# C++14 Hydrofabric Modeling

This repository contains a C++14 hydrofabric modeling implementation. This implementation takes inspiration from the [OGC WaterML HY_Features Model](https://docs.ogc.org/is/14-111r6/14-111r6.html) and the [Applications of HY_Features Engineering Report](https://docs.ogc.org/per/22-040.html) to represent a hydrofabric efficiently, but does not directly implement the HY_Features model.

## Design

The design of this library has three core components: `hf::fabric`, `hf::catchment`, and `hf::nexus`. 

- `hf::fabric` is a *registry* containing all the catchments loaded into the running process, and provides lookup and ownership for these resources.
- `hf::catchment` is a class providing a conceptual, holistic catchment. Topological representations of a catchment are provided through the `hf::realization` class, a polymorphic base class.

...
