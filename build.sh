##########################################################################
# File Name: build.sh
# Author: LEEYANGY
# mail: 1787294587@qq.com
# Created Time: Mon May 27 23:02:57 2024
#########################################################################

# clean build dir
cmake -P clean.cmake

# build src
mkdir build && cd build
cmake .. && cmake --build .
