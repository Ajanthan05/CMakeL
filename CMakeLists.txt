cmake_minimum_required(VERSION 3.22.1)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder) 



# -------- DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
#Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule upsate")
        execute process(COMMAND ${GIT_EXECUTABLE} Submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GET_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULJT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init faild with ${GIT_SUBMODE_RWSULT}, PLEASE CHECKout submodules")
        endif()
    endif()
endif()
#------------ cHECH ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/ecternal_modules/glfwCMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please")
endif() 





add_subdirectory(ecternal/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder
    PUBLIC ecternal/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC Adder/
    PUBLIC esternal/glfw/src
)

target_link_libraries(${PROJECT_NAME} adder glfw)