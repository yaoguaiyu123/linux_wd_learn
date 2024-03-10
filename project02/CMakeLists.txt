cmake_minimum_required(VERSION 3.27)

project(project02 LANGUAGES C)

add_executable(project02
    main.c
    func.h
)

target_compile_features(project02 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project02
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project02 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
