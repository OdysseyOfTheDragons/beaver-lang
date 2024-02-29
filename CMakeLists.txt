cmake_minimum_required(VERSION 3.10)
project(Beaver)
set(CMAKE_C_STANDARD 99)

# Source files
file(GLOB_RECURSE Core_src CONFIGURE_DEPENDS "Core/*.c")
file(GLOB_RECURSE Include_src CONFIGURE_DEPENDS "Include/*.c")
file(GLOB_RECURSE Libs_src CONFIGURE_DEPENDS "Libs/*.c")
file(GLOB_RECURSE Modules_src CONFIGURE_DEPENDS "Modules/*.c")
set(SOURCE_FILES ${Core_src} ${Include_src} ${Libs_src} ${Modules_src})

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Add header files
include_directories(.)

# Compiler flags
add_compile_options(-Wall -Wextra -pedantic -ansi)
add_compile_options(-I. -Os -s -O2)
add_compile_options(-lm)

# Create an executable
add_executable(Beaver ${SOURCE_FILES})

# Link -lm
target_link_libraries(Beaver m)

### MAIN: run ###
add_custom_target(run
	COMMAND Beaver -fsanitize=address -g
	DEPENDS Beaver
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MAIN: run-release ###
add_custom_target(run-release
	COMMAND Beaver 
	DEPENDS Beaver
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MAIN: indent ###
add_custom_target(indent
	COMMAND indent ./**/*.{c,h}
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MAIN: archive ###
add_custom_target(archive
	COMMAND tar -zcf build/beaver.tar.gz .indent.pro CMakeLists.txt LICENSE README.md Doxyfile **/*.{c,h}
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MAIN: database ###
add_custom_target(database
	COMMAND compiledb make run --dry-run
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
