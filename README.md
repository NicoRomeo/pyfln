# Python wrapper around Fast Linking Numbers

Pyfln is a pybind11-based python wrapper for [Fastlinkingnumbers developed by Ante Qu](https://github.com/antequ/fastlinkingnumbers). The build system is inspired by the solution from [this SO thread](https://stackoverflow.com/questions/47599162/pybind11-how-to-package-c-and-python-code-into-a-single-package).


### Required packages:
* [CMake](https://cmake.org/)
* [Eigen 3](https://eigen.tuxfamily.org/)
* [gflags](https://gflags.github.io/gflags/)
* OpenMP 3.1
* pybind11


### Installation and build
First, clone the  repo by using  
``
git clone --recursive https://github.com/NicoRomeo/flntest.git
``
Note the `--recursive` option to properly fetch pybind11.

The package requires Eigen3 and other dependencies listed above to build. Using a conda environment, they can be installed with

``
conda install eigen
``

``
conda install -c conda-forge c-compiler cxx-compiler gflags openmp cmake
``

With Eigen3 and python 3.9 or above, a local installation should then run using
``
pip install -e .
``

pytest (or other testing scheme) will run the tests in `tests/`
