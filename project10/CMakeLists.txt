cmake_minimum_required(VERSION 3.27)

project(project10 LANGUAGES C)

add_executable(project10
    main.c
    func.h
)

target_compile_features(project10 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project10
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project10 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
