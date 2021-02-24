#ifndef FREETYPE_CPP_FREETYPE_FACE_H
#define FREETYPE_CPP_FREETYPE_FACE_H

#include "points.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <memory>

namespace freetype_cpp
{
	class library;

	class draw_glyph_callback
	{
	public:
		virtual ~draw_glyph_callback() = default;

		virtual void draw_glyph(FT_GlyphSlot const& glyph) = 0;
	};

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

		bool draw_glyph(FT_ULong c, draw_glyph_callback& callback,
						FT_Int32 load_flags = FT_LOAD_RENDER);

		FT_Pos line_height() const;
	};
}

#endif	// FREETYPE_CPP_FREETYPE_FACE_H
