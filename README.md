# JSON CPP
JSON parsing using C++

# Specs
nlohmann-json version [3.1.0](https://github.com/nlohmann/json/releases/tag/v3.1.0) is used to test.

# Visual Studio 

2 Changes,
## Fix for header file inclusion
Instruction for including the `nlohmann-json` header properly into the project file is [here](https://stackoverflow.com/questions/6895457/how-to-define-relative-paths-in-visual-studio-project)

This way of including the header files enables us to include header file in following fashion,

    #include <nlohmann/json.hpp>

We extract release archive of nlohmann-json and extract inside the directory where the project file reside. Dir layout looks like following,
    
    > Tree /f ..\cpp\ProblemSolving
    Folder PATH listing for volume Data
    Volume serial number is 00000028 92E4:3E3D
    ..\CPP\PROBLEMSOLVING
    │   Main.cpp
    │   ProblemSolving.sln
    │   ProblemSolving.vcxproj
    │
    ├───include
    │   └───nlohmann
    │       │   adl_serializer.hpp
    │       │   json.hpp
    │       │   json_fwd.hpp
    │       │
    │       └───detail
    │           │   exceptions.hpp
    │           │   json_pointer.hpp
    │           │   json_ref.hpp
    │           │   macro_scope.hpp
    │           │   macro_unscope.hpp
    │           │   meta.hpp
    │           │   value_t.hpp
    │           │
    │           ├───conversions
    │           │       from_json.hpp
    │           │       to_chars.hpp
    │           │       to_json.hpp
    │           │
    │           ├───input
    │           │       binary_reader.hpp
    │           │       input_adapters.hpp
    │           │       lexer.hpp
    │           │       parser.hpp
    │           │
    │           ├───iterators
    │           │       internal_iterator.hpp
    │           │       iteration_proxy.hpp
    │           │       iter_impl.hpp
    │           │       json_reverse_iterator.hpp
    │           │       primitive_iterator.hpp
    │           │
    │           └───output
    │                   binary_writer.hpp
    │                   output_adapters.hpp
    │                   serializer.hpp
    │
    └───x64
        └───Debug

Project settings looks like following,

![Visual Studio project setting - header files](img/1.%20json%20lib%20inclusion.png)

## Enabling Console Subsystem for the project
We change the linker settings of the project to enable this.

![Visual Studio project setting - linker settings](img/2.%20subsytem%20console.png)

# References
 1. [github - nlohmann/json](https://github.com/nlohmann/json)
