cmake_minimum_required(VERSION 3.8)
project(project1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h LinkedList.cpp LinkedList.h SurveyClass.cpp SurveyClass.h)
set(TEST_FILES_LINKED_LIST Node.cpp Node.h LinkedList.cpp LinkedList.h SurveyClass.cpp SurveyClass.h acutest.h LinkedList.test.cpp )
set(TEST_FILES_SURVEY_CLASS Node.cpp Node.h LinkedList.cpp LinkedList.h SurveyClass.cpp SurveyClass.h acutest.h SurveyClass.test.cpp )
add_executable(project1 ${SOURCE_FILES})
add_executable(test_linked_list ${TEST_FILES_LINKED_LIST})
add_executable(test_survey_class ${TEST_FILES_SURVEY_CLASS})
