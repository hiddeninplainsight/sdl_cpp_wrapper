#!/bin/bash

find . \( -path ./sdl2windows \) -prune -type f -o -name '*.h' -exec clang-format -style=file -i {} \;
find . \( -path ./sdl2windows \) -prune -type f -o -name '*.cpp' -exec clang-format -style=file -i {} \;
