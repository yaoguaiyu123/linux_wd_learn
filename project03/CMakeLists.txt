cmake_minimum_required(VERSION 3.27)

project(project03 LANGUAGES C)

add_executable(project03
    main.c
    func.h
)

target_compile_features(project03 PRIVATE c_std_17)




































































# include(GNUInstallDirs)
# install(TARGETS project03
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# target_sources(project03 
#     PRIVATE
#         %{CppFileName}    
#         
#     PUBLIC
#         
# )
