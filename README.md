# What is sorga_example
Sorga_example is an example for configuring a simple software project with
Cmake. It includes an example library, the configuration for Doxygen
and testings.

# Requirements
- Cmake minimum version 2.8
- Doxygen for building the documentation

# Building sorga_example
To clone sorga_project use:

    % git clone --recursive https://github.com/DavidKreplin/example.git

The --recursive option is mandatory!

To configure sorga_example navigate to the desired output folder and use:

    % cmake "path to the project"

To build the project simply run:

    % make

The documentations can be build with:

    % make doc

To run the test calculations run:

    % make test

