cmake_minimum_required(VERSION 3.27)

project(project06 LANGUAGES C)

add_executable(project06
    main.c
    func.h

)

target_compile_features(project06 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project06
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project06 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
