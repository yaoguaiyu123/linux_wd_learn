cmake_minimum_required(VERSION 3.27)

project(project09 LANGUAGES C)

add_executable(project09
    main.c
    func.h
)

target_compile_features(project09 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project09
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project09 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
