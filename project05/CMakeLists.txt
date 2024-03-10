cmake_minimum_required(VERSION 3.27)

project(project05 LANGUAGES C)

add_executable(project05
    main.c
    func.h
)

target_compile_features(project05 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project05
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project05 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
