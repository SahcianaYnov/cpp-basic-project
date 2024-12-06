# CMakeList.txt : projet CMake pour TD1CPP, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (TD1CPP "TD1CPP.cpp" "TD1CPP.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TD1CPP PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
