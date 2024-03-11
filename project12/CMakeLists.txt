cmake_minimum_required(VERSION 3.27)

project(project12 LANGUAGES C)

add_executable(project12
    main.c
    func.h
)

target_compile_features(project12 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project12
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project12 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
