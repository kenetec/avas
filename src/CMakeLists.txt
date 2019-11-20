add_executable(fantastic_finale_kenetec 
main.cpp ofApp.h ofApp.cpp Note.h Note.cpp Measure.h Measure.cpp Score.h Score.cpp)

target_include_directories(fantastic_finale_kenetec PRIVATE 
../include)