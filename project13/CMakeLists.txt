cmake_minimum_required(VERSION 3.27)

project(project13 LANGUAGES C)

add_executable(project13
    main.c
)

target_compile_features(project13 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project13
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project13 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
