set(MODEL_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/curve.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model.cpp)

set(VERIFY_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/compute_link.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/discretize.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linking_number_certificate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/potential_link_search.cpp)

project(pyfln
    VERSION 1.0.0
    DESCRIPTION
    "Topology Computation Tool Using Fast Linking Numbers")

pybind11_add_module(_pyfln 
	${CMAKE_CURRENT_SOURCE_DIR}/pyfln.cpp SHARED
	${MODEL_FILES}
	${VERIFY_FILES})

target_link_libraries(_pyfln
    PRIVATE Eigen3::Eigen
    PRIVATE OpenMP::OpenMP_CXX)

