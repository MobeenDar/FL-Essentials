set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/examples)

set(INCLUDE_DIR
${PROJECT_SOURCE_DIR}/include
${FLTK_INCLUDE_DIR}
${OpenCV_INCLUDE_DIRS}
)

include_directories(${INCLUDE_DIR})

if(WIN32)
set(LIBRARIES 
${PROJECT_NAME} 
${OPENGL_gl_LIBRARY}
${OPENGL_glu_LIBRARY}
${OPENGL_LIBRARIES}
${OPENGL_LIBRARY}
${FLTK_LIBRARIES}
${OpenCV_LIBS})
else()
set(LIBRARIES 
${PROJECT_NAME} 
${OPENGL_gl_LIBRARY}
${OPENGL_glu_LIBRARY}
${OPENGL_LIBRARIES}
${FLTK_LIBRARIES}
${OpenCV_LIBS}
-ldl -lz -ljpeg -lpng)
endif(WIN32)

add_executable (opengl_events_lights_animation main.cpp opengl_events_lights_animation.cpp opengl_events_lights_animation.h)
target_link_libraries(opengl_events_lights_animation LINK_PUBLIC ${LIBRARIES})
