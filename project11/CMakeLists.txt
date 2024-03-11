cmake_minimum_required(VERSION 3.27)

project(project11 LANGUAGES C)

add_executable(project11
    main.c
    func.h
)

target_compile_features(project11 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project11
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project11 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
