# StrPlus
C++ strings processing library

## Namespace functions
```c++
namespace hhullen {

using Str = std::string;
using StrList = std::vector<Str>;

namespace StrPlus {

enum class Type { Int, UInt, Float };

StrList Split(const Str &src, char delimiter);
void MakeUpper(Str &src);
void MakeLower(Str &src);
Str GetUpper(const Str &src);
Str GetLower(const Str &src);
bool IsUpper(const Str &src);
bool IsLower(const Str &src);
bool IsValid(const Str &src, Type type);

}  // namespace StrPlus

}  // namespace hhullen
```

## Installation
It is only-header library. Just copy `src/str_plus.h` and `src/str_plus.cc`  files to your project or execute `Make lib` command, that create `StrPlus` folder with files then copy it to your project and include it.
```c++
#include "../path_to_file/str_plus.h"
```

## Usage
```c++
#include "../path_to_file/str_plus.h"

using hhullen::StrList;

int main() {
    std::string any_string(" May  the Force  be with     you.  ");

    // Use any function
    StrList tokens = hhullen::StrPlus::Split(any_string);

    std::string str_number("-12.33e+22");
    bool IsFloat;
    // Here is no transformation string to Float. It returns true in case
    // the string satisfies the float number and can be transformed with no error
    IsFloat = IsValid(str_number, hhullen::StrPlus::Type::Float)  // returns true
    IsFloat = IsValid(str_number, hhullen::StrPlus::Type::Uint)  // returns false
    IsFloat = IsValid(any_string, hhullen::StrPlus::Type::Int)  // returns false

    return 0;
}
```