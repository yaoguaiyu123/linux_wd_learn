cmake_minimum_required(VERSION 3.27)

project(project08 LANGUAGES C)

add_executable(project08
    main.c
    func.h
)

target_compile_features(project08 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project08
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project08 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
