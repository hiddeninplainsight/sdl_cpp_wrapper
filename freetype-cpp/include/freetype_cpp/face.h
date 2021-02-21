#ifndef FREETYPE_CPP_FREETYPE_FACE_H
#define FREETYPE_CPP_FREETYPE_FACE_H

#include "points.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <memory>

namespace freetype_cpp
{
	class library;

	class face
	{
	private:
		std::shared_ptr<library> library_ptr;
		FT_Face face_object;

		face(std::shared_ptr<library> library_ptr, char const* file_path,
			 FT_Long face_index = 0);

		face(std::shared_ptr<library> library_ptr, FT_Byte const* memory,
			 FT_Long memory_size, FT_Long face_index = 0);

	public:
		~face();
		face(face const&) = delete;
		face operator=(face const&) = delete;

		static std::shared_ptr<face> initialise_from_file(
			std::shared_ptr<library> library_ptr, char const* file_path,
			FT_Long face_index = 0);

		static std::shared_ptr<face> initialise_from_memory(
			std::shared_ptr<library> library_ptr, FT_Byte const* memory,
			FT_Long memory_size, FT_Long face_index = 0);

		void set_font_size(points size, FT_UInt horizontal_resolution = 300,
						   FT_UInt vertical_resolution = 300);
	};
}

#endif	// FREETYPE_CPP_FREETYPE_FACE_H
