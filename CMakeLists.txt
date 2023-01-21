cmake_minimum_required(VERSION 3.16)

project(psd)

## compiler options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++11)




set(PSD_HEADERS "")
set(PSD_LIBS psd)

if(WIN32)
    add_library(psd STATIC
        src/PsdExport.cpp
        src/PsdPch.cpp
        src/PsdDecompressRle.cpp
        src/PsdInterleave.cpp
        src/PsdLayerCanvasCopy.cpp
        src/PsdAllocator.cpp
        src/PsdFile.cpp
        src/PsdMallocAllocator.cpp
        src/PsdNativeFile.cpp
        src/PsdParseColorModeDataSection.cpp
        src/PsdParseDocument.cpp
        src/PsdParseImageDataSection.cpp
        src/PsdParseImageResourcesSection.cpp
        src/PsdParseLayerMaskSection.cpp
        src/PsdBlendMode.cpp
        src/PsdColorMode.cpp
        src/PsdFixedSizeString.cpp
        src/PsdSyncFileReader.cpp
        src/Psdminiz.c
        src/PsdSyncFileWriter.cpp
        src/PsdStringUtil.cpp
        src/PsdTgaExporter.cpp)
endif(WIN32)

if(UNIX)
    add_library(psd STATIC
        src/PsdExport.cpp
        src/PsdPch.cpp
        src/PsdDecompressRle.cpp
        src/PsdInterleave.cpp
        src/PsdLayerCanvasCopy.cpp
        src/PsdAllocator.cpp
        src/PsdFile.cpp
        src/PsdMallocAllocator.cpp
        src/PsdNativeFile_Linux.cpp
        src/PsdParseColorModeDataSection.cpp
        src/PsdParseDocument.cpp
        src/PsdParseImageDataSection.cpp
        src/PsdParseImageResourcesSection.cpp
        src/PsdParseLayerMaskSection.cpp
        src/PsdBlendMode.cpp
        src/PsdColorMode.cpp
        src/PsdFixedSizeString.cpp
        src/PsdSyncFileReader.cpp
        src/Psdminiz.c
        src/PsdSyncFileWriter.cpp
        src/PsdStringUtil.cpp
        src/PsdTgaExporter.cpp
    )
endif(UNIX)

target_include_directories(psd PUBLIC src)
target_link_libraries(psd rt)
file(GLOB headers ${PROJECT_SOURCE_DIR}/src/*.h)
list (APPEND PSD_HEADERS ${headers})
file(GLOB c_headers ${PROJECT_SOURCE_DIR}/src/*.c)
list(APPEND PSD_HEADERS ${c_headers})
file(GLOB inlines ${PROJECT_SOURCE_DIR}/src/*.inl)
list(APPEND PSD_HEADERS ${inlines})
set(PSD_HEADERS ${PSD_HEADERS} PARENT_SCOPE)
include_directories(src/)
add_executable(psd_test test/psd_test.cpp)
target_link_libraries(psd_test psd)
