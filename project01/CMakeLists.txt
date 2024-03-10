cmake_minimum_required(VERSION 3.27)

project(project01 LANGUAGES C)

add_executable(project01
    main.c
    func.h
)

target_compile_features(project01 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project01
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project01 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
