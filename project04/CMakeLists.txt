cmake_minimum_required(VERSION 3.27)

project(project04 LANGUAGES C)

add_executable(project04
    main.c
    func.h
)

target_compile_features(project04 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project04
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project04 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
