cmake_minimum_required(VERSION 3.16)

project(psd)

## compiler options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++11)



## include directories
set(PSD_LIB_DIR ${CMAKE_INSTALL_PREFIX}/lib)
set(PSD_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)



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
file(GLOB c_headers ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB inlines ${PROJECT_SOURCE_DIR}/src/*.inl)


install (TARGETS psd LIBRARY DESTINATION ${PSD_LIB_DIR})
install (FILES ${headers} DESTINATION ${PSD_INCLUDE_DIR})
install (FILES ${c_headers} DESTINATION ${PSD_INCLUDE_DIR})
install (FILES ${inlines} DESTINATION ${PSD_INCLUDE_DIR})

include_directories(src/)
add_executable(psd_test test/psd_test.cpp)
target_link_libraries(psd_test psd)
