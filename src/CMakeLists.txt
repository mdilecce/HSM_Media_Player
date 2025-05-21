# Define source file lists
set(SOURCES
    state.cpp
    system.cpp
    power_state.cpp
    media_player.cpp
    main.cpp # Add main.cpp to the sources
)

set(HEADER_LIST
    "${PROJECT_SOURCE_DIR}/include/key_config.hpp"
    "${PROJECT_SOURCE_DIR}/include/key_binding.h"
    "${PROJECT_SOURCE_DIR}/include/state.hpp"
    "${PROJECT_SOURCE_DIR}/include/system.hpp"
    "${PROJECT_SOURCE_DIR}/include/power_state.hpp"
    "${PROJECT_SOURCE_DIR}/include/media_player.hpp"
)

# Create a static library
add_library(hsm_media_lib STATIC ${SOURCES} ${HEADER_LIST})

# Include directories for the library
target_include_directories(hsm_media_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Compile features for the library
target_compile_features(hsm_media_lib PUBLIC cxx_std_17)

# Source group for headers
source_group(TREE ${PROJECT_SOURCE_DIR}/include
    PREFIX "Header Files"
    FILES ${HEADER_LIST}
)
