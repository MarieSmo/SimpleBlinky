cmake_minimum_required(VERSION 2.8)
# 2.8.3 has "CMAKE_CURRENT_LIST_DIR" variable. We have 2.8.2 deployed, 
# so using "CMAKE_SOURCE_DIR" instead.
set(GEN_ROOT ${CMAKE_SOURCE_DIR})

# Select flags.
SET(CMAKE_CXX_FLAGS "-Wall -std=c++0x ${BIPFLAGS} ")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g -std=c++0x ")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -std=c++0x ")
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g -std=c++0x ")
SET(CMAKE_EXE_LINKER_FLAGS "")

SET(CMAKE_CXX_FLAGS_PROFILING "-O0 -g -pg")
SET(CMAKE_EXE_LINKER_FLAGS_PROFILING "-pg ")




set(CUSTOM_LIB_DIRS )

# Following only for building from instances.


set(USER_EXTRA_SRC)


include_directories(${GEN_ROOT}/Deploy)

set(USR_EXTRA_OBJ)

add_executable(system
  ${GEN_ROOT}/Deploy/Deploy.cpp
  ${USER_EXTRA_SRC}
  ${USER_EXTRA_OBJ})

target_link_libraries(system
)
