add_library(sdl-cpp
		include/sdl_cpp/sdl_cpp.h
		include/sdl_cpp/bezier.h
		include/sdl_cpp/collision_detection.h
		include/sdl_cpp/context.h
		include/sdl_cpp/event_keys.h
		include/sdl_cpp/event_mouse_dispatch.h
		include/sdl_cpp/event_quit.h
		include/sdl_cpp/events.h
		include/sdl_cpp/sdl_exception.h
		include/sdl_cpp/key_state.h
		include/sdl_cpp/lerp.h
		include/sdl_cpp/maths.h
		include/sdl_cpp/mouse_state.h
		include/sdl_cpp/pixel_buffer_painter.h
		include/sdl_cpp/point_transforms.h
		include/sdl_cpp/rectangle_collider.h
		include/sdl_cpp/render_to_texture.h
		include/sdl_cpp/renderer.h
		include/sdl_cpp/renderer_clip_region.h
		include/sdl_cpp/renderer_forward_declaration.h
		include/sdl_cpp/sdl_size.h
		include/sdl_cpp/surface.h
		include/sdl_cpp/texture.h
		include/sdl_cpp/texture_pixel_buffer.h
		include/sdl_cpp/window.h
		src/bezier.cpp
		src/collision_detection.cpp
		src/event_keys.cpp
		src/event_mouse_dispatch.cpp
		src/event_quit.cpp
		src/events.cpp
		src/key_state.cpp
		src/lerp.cpp
		src/maths.cpp
		src/mouse_state.cpp
		src/pixel_buffer_painter.cpp
		src/point_transforms.cpp
		src/rectangle_collider.cpp
		src/renderer_clip_region.cpp
		src/texture_pixel_buffer.cpp

		# fonts
		include/sdl_cpp/fonts/ttf_font.h
		include/sdl_cpp/fonts/ttf_font_context.h
		src/fonts/ttf_font.cpp
		)

target_include_directories(sdl-cpp PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_include_directories(sdl-cpp SYSTEM PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
		"${SDL2_INCLUDE_DIR}"
		)

target_link_libraries(sdl-cpp
		${SDL2_LIBRARY}
		${SDL2_IMAGE_LIBRARY}
		${SDL2_TTF_LIBRARY}
		)
